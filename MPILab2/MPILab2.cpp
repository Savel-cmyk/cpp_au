#include <iostream>
#include "mpi.h"
#include <math.h>
#include <cmath>
#include <chrono>

using namespace std;

typedef double(*pointFunc)(double);

double f(double x) {
	return sin(log(x));
}
double trapezoidal_rule(double, double, double, pointFunc);

int main(int nargs, char* args[])
{
	int numprocs, my_rank;
	double local_n, a, b, eps, h, local_a, local_b, total_sum, local_sum;
	double time_start, time_end, total_time;
	
	int n = 500; //начальное число шагов
	a = 2.0; b = 6.0;
	/*double integral = 3 * (sin(log(6)) - cos(log(6))) - (sin(log(2)) - cos(log(2)));

	cout << "\nEnter required precision eps = ";
	cin >> eps;
	do {
		total_sum = trapezoidal_rule(a, b, n, f);
		n = 2 * n;  //увеличение числа шагов в 2 раза, 
					//т.е. уменьшение значения шага в 2 раза
	} while (fabs(integral - total_sum) > eps);
	cout << n << endl;*/
	// MPI initializations
	/**/MPI_Init(&nargs, &args);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	
	time_start = MPI_Wtime();
	// Fixed values for a, b and n
	
	h = (b - a) / n; // h is the same for all processes
	local_n = n * 1.0 / numprocs; // make sure n > numprocs, else integer division gives zero
	// Length of each process' interval of
	// integration = local_n*h.
	local_a = a + my_rank * local_n * h;
	local_b = local_a + local_n * h;
	total_sum = 0.0;
	local_sum = trapezoidal_rule(local_a, local_b, local_n, f);
	MPI_Reduce(&local_sum, &total_sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	time_end = MPI_Wtime();
	total_time = time_end - time_start;
	if (my_rank == 0) {
		cout << total_time << " " << total_sum << " " << numprocs;
	}
	// End MPI
	MPI_Finalize();
	return 0;/**/
}

double trapezoidal_rule(double a, double b, double n, pointFunc f)
{
	double trapez_sum;
	double fa, fb, x, step;
	int j;
	step = (b - a) / n;
	fa = f(a) / 2.;
	fb = f(b) / 2.;
	trapez_sum = 0.;
	for (j = 1; j <= n - 1; j++) {
		x = j * step + a;
		trapez_sum += f(x);
	}
	trapez_sum = (trapez_sum + fb + fa) * step;
	return trapez_sum;
}