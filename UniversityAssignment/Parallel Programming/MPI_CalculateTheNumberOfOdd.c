#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define SIZE 1000

void main(int argc, char* argv[]) {

    int count = 0, i, j;
    int my_rank, p;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &p);

    int* A = malloc(SIZE * sizeof(int));
    int* B = malloc((SIZE / p) * sizeof(int));


    if (my_rank == 0) {
        for (i = 0; i < SIZE; i++)
            A[i] = i + 1;
    }
    MPI_Scatter(A, (SIZE / p), MPI_INT, B, (SIZE / p), MPI_INT, 0, MPI_COMM_WORLD);

    for (j = 0; j < (SIZE / p); j++)
        if (B[j] % 2 != 0) count++;

    int sum = 0;
    MPI_Reduce(&count, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    if (my_rank == 0) printf("%d\n", sum);

    MPI_Finalize();

}