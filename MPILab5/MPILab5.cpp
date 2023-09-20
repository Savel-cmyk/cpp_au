#include "mpi.h"
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime(int num)
{
	switch (num) {
	case 0:
		return 0;
	case 1:
		return 0;
	case 2:
		return 1;
	default:
		for (int i = 2; i < sqrt(num) + 1; i++)
			if (num % i == 0)
				return 0;
	}	
	return 1;
}

int main(int argc, char** argv) {
	int i, m = 1, n = 100, k = 0, size, rank;
	int* curPrimes;//the primes that we will calculate in THIS process
	int* recvPrimes;//temporary variable for primes the main process will recieve from secondary ones
	double time_start, time_end;
	vector <int> allPrimes;

	//init mpi
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	//we cant have more than n/2 primes because even numbers for sure cant be prime
	curPrimes = new int[n / 2];

	time_start = MPI_Wtime();
	//calculate prime numbers each process will calculate its own portion
	for (i = m + rank; i < n; i+=size)
		if (isPrime(i))
			curPrimes[k++] = i;
	time_end = MPI_Wtime();

	//if we are not in the main process(process with rank 0) send our prime numbers to main process
	if (rank != 0)
	{
		MPI_Send(&k, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
		MPI_Send(curPrimes, k, MPI_INT, 0, 0, MPI_COMM_WORLD);
	}

	int recvSize;

	if (rank == 0)
	{
		//this runs only on main process
		//add the primes calculated here to our large prime vector
		for (i = 0; i < k; i++)
			allPrimes.push_back(curPrimes[i]);
		//clear the memory of our primes
		delete curPrimes;
		//go through all the recieved primes and add them to our vector
		for (i = 1; i < size; i++)
		{
			MPI_Recv(&recvSize, 1, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			recvPrimes = new int[recvSize];
			MPI_Recv(recvPrimes, recvSize, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			for (int j = 0; j < recvSize; j++)
				allPrimes.push_back(recvPrimes[j]);
			delete recvPrimes;
		}

		//cout << "overall " << allPrimes.size() << " primes" << endl;
		//output all primes to a file
		//freopen("primes.txt", "w", stdout);

		printf("\n");
		sort(allPrimes.begin(), allPrimes.end());
		for (i = 0; i < allPrimes.size(); i++)
			printf("%d ", allPrimes[i]);
		printf("\n %f", time_end - time_start);
	}

	MPI_Finalize();
	return 0;
}