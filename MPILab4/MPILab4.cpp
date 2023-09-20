#define _USE_MATH_DEFINES

#include <iostream>
#include "mpi.h"
#include <math.h>
#include <cmath>
#include <chrono>

#define N 1E6
MPI_Status status;

using namespace std;

int main(int argc, char* argv[])
{
    int rank, size, i;
    double begin, end, result = 1.0, prod = 1.0;
    bool b = false;

    MPI_Init(&argc, &argv);

    //Get process ID
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    //Get processes Number
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    //Synchronize all processes and get the begin time
    MPI_Barrier(MPI_COMM_WORLD);
    begin = MPI_Wtime();

    double f = 1 + 1/N;

    //Each process caculates a part of the sum
    for (i = rank + 1; i < (N / size) * size + 1; i += size)
    {
        result *= f;
    }

    //Sum up all results
    MPI_Reduce(&result, &prod, 1, MPI_DOUBLE, MPI_PROD, 0, MPI_COMM_WORLD);

    //Synchronize all processes and get the end time
    MPI_Barrier(MPI_COMM_WORLD);
    end = MPI_Wtime();

    //Caculate and print PI
    if (rank == 0) printf("np=%2d;    Time=%fs;    E=%f\n", size, end - begin, prod);

    MPI_Finalize();

    return 0;
}
/*typedef double(*pointFunc)(double);

double f(double x) {
    return pow((1 + 2.0 / x), pow((-1), x) * x);
}

int main(int argc, char* argv[])
{
    int rank, size, i;
    double pi, begin, end, result = 1.0, prod = 1.0;
    bool b = false;

    MPI_Init(&argc, &argv);

    //Get process ID
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    //Get processes Number
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    //Synchronize all processes and get the begin time
    MPI_Barrier(MPI_COMM_WORLD);
    begin = MPI_Wtime();

    //Each process caculates a part of the sum
    for (i = rank + 2; i < (N / size) * size + 2; i += size)
    {
        if (b) {
            result *= f(i);
            b = false;
        }
        else {
            result *= f(i + size - 2 * rank - 1);
            b = true;
        }
    }

    //Sum up all results
    MPI_Reduce(&result, &prod, 1, MPI_DOUBLE, MPI_PROD, 0, MPI_COMM_WORLD);

    //Synchronize all processes and get the end time
    MPI_Barrier(MPI_COMM_WORLD);
    end = MPI_Wtime();

    //Caculate and print PI
    if (rank == 0)
    {
        pi = 6.0 / (M_E * prod);
        printf("np=%2d;    Time=%fs;    Pi=%f\n", size, end - begin, pi);
    }

    MPI_Finalize();

    return 0;
}*/