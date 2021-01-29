#include <mpi.h>
#include <stdio.h>
void main(int argc, char* argv[]) {
    int i, j, my_rank;
    int A[10][10];
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    if (my_rank == 0) {
        for (i = 0; i < 10; i++)
            for (j = 0; j < 10; j++)
                A[i][j] = i * 10 + j;
    }

    MPI_Bcast(A, 100, MPI_INT, 0, MPI_COMM_WORLD);

    if (my_rank == 1)
        for (i = 0; i < 10; i++)
            for (j = 0; j < 10; j++)
                printf("A[%d][%d] = %d\n", i, j, A[i][j]);
    MPI_Finalize();
}