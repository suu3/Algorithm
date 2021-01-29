#include <mpi.h>
#include <stdio.h>
void main(int argc, char *argv[]){
    int i, j, my_rank;
    int A[5][5] = { 0 };
    int B[5][5] = { 0 };
    MPI_Datatype columntype;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    if (my_rank == 0) {
        for (i = 0; i < 5; i++)
            for(j = 0 ; j < 5; j++)
                A[i][j] = i * 5 + j;
    }
    if (my_rank == 1) {
        for (i = 0; i < 5; i++)
            for (j = 0; j < 5; j++)
                B[i][j] = i * 5 + j;
    }

    MPI_Type_vector(5, 1, 5, MPI_INT, &columntype);
    MPI_Type_commit(&columntype);

    //4번
    if (my_rank == 0) {
        MPI_Send(&A[0][3], 1, columntype, 1, 5, MPI_COMM_WORLD);
    }
    if (my_rank == 1) {
        MPI_Recv(&B[0][4], 1, columntype, 0, 5, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }

    //5번
    if (my_rank == 1) {
        MPI_Send(&B[0][2], 1, columntype, 0, 5, MPI_COMM_WORLD);
    }
    if (my_rank == 0) {
        MPI_Recv(&A[0][4], 1, columntype, 1, 5, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }

    //출력
    if(my_rank==1)
        for(i = 0 ;i < 5 ;i++)
            for (j = 0; j < 5; j++)
                printf("B[%d][%d] = %d\n", i, j, B[i][j]);
    MPI_Finalize();
}