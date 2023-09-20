#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <mpi.h>

using namespace std;

#define root 0
static int gsize = 0, myid = 0;

#define MATRIX 1000
#define N MATRIX 
#define M MATRIX 

void printArray(uint64_t* a, uint64_t m);
void print(uint64_t* arr, int rows, int cols);
void mux(uint64_t* a, uint64_t* C, uint64_t* B);
void init(uint64_t* a);

int main(int argc, char* argv[])
{
	srand(time(NULL));
	uint64_t *A, *B, *C;
	uint64_t *temp_array, * temp_array_;
	int *displs, *sendcounts;
	long double begin = 0.0, end = 0.0;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &gsize);
	MPI_Comm_rank(MPI_COMM_WORLD, &myid);

	int matrix_size = M * N;
	int useproc = 0;
	int temp_array_size = 0;
	int sum = 0, balance = 0;
	
	A = (uint64_t*)malloc(matrix_size * sizeof(uint64_t));
	B = (uint64_t*)malloc(matrix_size * sizeof(uint64_t));
	C = (uint64_t*)malloc(matrix_size * sizeof(uint64_t));
	
	if (myid == root)
	{
		for (int i = 0; i < matrix_size; ++i)
		{
			A[i] = rand() % 5;
			B[i] = rand() % 5;
		}
		//printf("Process #%d:\n", myid);
		//printf("A:\n");
		//print(A, M, N);
		//printf("B:\n");
		//print(B, M, N);

		for (int i = 1; i < gsize; ++i)
			MPI_Send(B, matrix_size, MPI_UNSIGNED_LONG_LONG, i, 0, MPI_COMM_WORLD);
	}
	else 
	{
		MPI_Status status;
		MPI_Recv(B, matrix_size, MPI_UNSIGNED_LONG_LONG, root, 0, MPI_COMM_WORLD, &status);
	}
	begin = MPI_Wtime();
	if (M >= gsize) 
	{    
		balance = M % gsize;
		useproc = gsize;
	}
	else 
	{
		balance = 0;
		useproc = M;
	}

	if (myid < useproc)
	{
		sendcounts = (int*)calloc(gsize, sizeof(int));
		displs = (int*)malloc(gsize * sizeof(int));

		for (int i = 0; i < useproc; ++i)
		{
			sendcounts[i] = N * (M / useproc);
			if (balance > 0){
				sendcounts[i] += N;
				--balance;
			}
			displs[i] = sum;
			sum += sendcounts[i];
		}

		temp_array_size = sendcounts[myid];
		temp_array = (uint64_t*)malloc(temp_array_size * sizeof(uint64_t));
		temp_array_ = (uint64_t*)malloc(temp_array_size * sizeof(uint64_t));

		MPI_Scatterv(A, sendcounts, displs, MPI_UNSIGNED_LONG_LONG, temp_array, temp_array_size, MPI_UNSIGNED_LONG_LONG, root, MPI_COMM_WORLD);
		/*
		printf("Process #%d recieved:\n", myid);
		for (int i = 0; i < temp_array_size; i += N)
			printArray(temp_array + i, N);
		*/

		for (int i = 0; i < temp_array_size; i += N)
			init(temp_array_ + i);

		for (int i = 0; i < temp_array_size; i += N)
			mux(temp_array + i, temp_array_ + i, B);
		
		printf("\n");

		MPI_Gatherv(temp_array_, temp_array_size, MPI_UNSIGNED_LONG_LONG, C, sendcounts, displs, MPI_UNSIGNED_LONG_LONG, root, MPI_COMM_WORLD);
	}
	end = MPI_Wtime();
	MPI_Barrier(MPI_COMM_WORLD);

	if (myid == root)
	{
		//printf("Process #%d:\nC:\n", myid);
		printf("Time=%fs", end - begin);
		//print(C, M, N);
	}
	free(A);
	free(B);
	free(C);
	MPI_Finalize();
	return 0;
}

void printArray(uint64_t* a, uint64_t m) 
{
	cout << "[ ";
	for (int i = 0; i < m; i++) printf("%u ", a[i]);
	cout << "]\n"; 
}

void print(uint64_t* arr, int rows, int cols) 
{

	for (int i = 0; i < rows; ++i) 
	{
		for (int j = 0; j < cols; ++j)
			printf("%u ", arr[i * cols + j]);
		printf("\n");
	}
	printf("\n");
}

void mux(uint64_t* a, uint64_t* C, uint64_t* B)
{
	for (int i = 0; i < N; i++)
		for (int j = 0, k = i; j < N; j++, k += N)
			C[i] += a[j] * B[k];
}

void init(uint64_t* a)
{
	for (int i = 0; i < N; i++) a[i] = 0;
}