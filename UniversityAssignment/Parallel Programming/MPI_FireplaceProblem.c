#include <stdio.h>
#include <mpi.h>
void main(int argc, char* argv[]) {
	int my_rank, p;
	double R[102][102] = { 0.0 }; //방안 초기 온도

	int i, j, k, m1, m2, n1, n2;
	MPI_Datatype columntype;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &p);

	MPI_Type_vector(100, 1, 102, MPI_DOUBLE, &columntype);
	MPI_Type_commit(&columntype);

	int start = 100 * my_rank / p + 1; //1, 26, 51, 76
	int end = 100 * (my_rank + 1) / p; //25, 50, 75, 100


	for (j = 40; j < 60; j++) {//벽난로의 온도 (계속 유지)
		R[0][j] = 200.0;
	}


	if (my_rank == 0) { //프로그램이 너무 오래걸려서 먼저 구간부터 물어보고 계산한다..
		printf("m1 m2 n1 n2: \n");
		scanf("%d %d %d %d", &m1, &m2, &n1, &n2);
	}

	for (k = 0; k < 10000; k++) {
		//계산
		for (i = 1; i <= 100; i++)
			for (j = start; j <= end; j++)
				R[i][j] = 0.25 * (R[i][j - 1] + R[i][j + 1] + R[i - 1][j] + R[i + 1][j]);

		//필요한 거 주고받음
		if (my_rank == 0) {
			MPI_Send(&R[1][end], 1, columntype, my_rank + 1, 5, MPI_COMM_WORLD);
			MPI_Recv(&R[1][end + 1], 1, columntype, my_rank + 1, 4, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		}
		else if (my_rank == p - 1) {
			MPI_Recv(&R[1][start - 1], 1, columntype, my_rank - 1, 5, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			MPI_Send(&R[1][start], 1, columntype, my_rank - 1, 4, MPI_COMM_WORLD);
		}
		else {
			MPI_Recv(&R[1][start - 1], 1, columntype, my_rank - 1, 5, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			MPI_Send(&R[1][start], 1, columntype, my_rank - 1, 4, MPI_COMM_WORLD);

			MPI_Send(&R[1][end], 1, columntype, my_rank + 1, 5, MPI_COMM_WORLD);
			MPI_Recv(&R[1][end + 1], 1, columntype, my_rank + 1, 4, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

		}

	}


	for (k = 0; k < p; k++) {
		for (i = 1; i <= 100; i++)
			for (j = 100 * k / p + 1; j <= 100 * (k + 1) / p; j++)
				MPI_Bcast(&R[i][j], 1, MPI_DOUBLE, k, MPI_COMM_WORLD);
	}


	if (my_rank == 0) {
		for (i = m1; i <= m2; i++) { //방의 세로 구간
			for (j = n1; j <= n2; j++)
				printf("%7.1f ", R[i][j]);
			printf("\n");
		}
	}


	MPI_Finalize();
}