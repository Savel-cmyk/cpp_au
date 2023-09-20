﻿// PPLab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <omp.h>
#include <math.h>
#include <cmath>
#include <chrono>

#define SIZE 12
using namespace std;
typedef double(*pointFunc)(double);

double f(double x) {
	return sin(log(x));
}
/*
double rrectangle_integral(pointFunc f, double a, double b, int n) {
	double x, h;
	double sum = 0.0;
	double numbers[SIZE];

	cout << "\n";
	#pragma omp parallel reduction(+:sum) num_threads(SIZE) //reduction позволяет суммировать без потери данных
	{
		auto begin = std::chrono::steady_clock::now();

		h = (b - a) / (n * omp_get_num_threads());  //шаг
		for (int i = 0; i < n; i++) {
			x = a + n * h * omp_get_thread_num() + (i + 1) * h;
			sum += f(x);
		}

		auto end = std::chrono::steady_clock::now();

		auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

		numbers[omp_get_thread_num()] = elapsed_ms.count();
	}

	for (int i = 0; i < SIZE; i++) {
		cout << i << " " << numbers[i] << " ms ";
	}

	return (sum * h); //приближенное значение интеграла равно 
					  //сумме площадей прямоугольников
}

double mrectangle_integral(pointFunc f, double a, double b, int n) {
	double x1, x2, h;
	double sum = 0.0;
	double numbers[SIZE];

	cout << "\n";
	#pragma omp parallel reduction(+:sum) num_threads(SIZE)
	{
		auto begin = std::chrono::steady_clock::now();
		
		h = (b - a) / (n * omp_get_num_threads());
		for (int i = 0; i < n; i++) {
			x1 = a + n * h * omp_get_thread_num() + i * h;
			x2 = a + n * h * omp_get_thread_num() + (i + 1) * h;

			sum += f((x1 + x2) * 0.5);
		}

		auto end = std::chrono::steady_clock::now();

		auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

		numbers[omp_get_thread_num()] = elapsed_ms.count();
	}

	for (int i = 0; i < SIZE; i++) {
		cout << i << " " << numbers[i] << " ms ";
	}

	return (sum * h);
}
*/
double lrectangle_integral(pointFunc f, double a, double b, int n, int k) {
	double x, h;
	double sum = 0.0;

	#pragma omp parallel reduction(+:sum) num_threads(k) //reduction позволяет суммировать без потери данных
	{
		
		h = (b - a) / (n * omp_get_num_threads());  //шаг
		for (int i = 0; i < n; i++) {
			x = a + n * h * omp_get_thread_num() + i * h;
			sum += f(x);
		}
		//printf("%f нить %d\n", sum * h, omp_get_thread_num());
	}

	return (sum * h); //приближенное значение интеграла равно 
					  //сумме площадей прямоугольников
}
/*
double trapezoidal_integral(pointFunc f, double a, double b, int n) {
	double x1, x2, h;
	double sum = 0.0;

	cout << "\n";
	#pragma omp parallel reduction(+:sum) num_threads(SIZE)
	{
		auto begin = std::chrono::steady_clock::now();

		h = (b - a) / (n * omp_get_num_threads());
		for (int i = 0; i < n; i++) {
			x1 = a + n * h * omp_get_thread_num() + i * h;
			x2 = a + n * h * omp_get_thread_num() + (i + 1) * h;

			sum += 0.5 * (f(x1) + f(x2));
		}

		auto end = std::chrono::steady_clock::now();

		auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

		numbers[omp_get_thread_num()] = elapsed_ms.count();
	}

	for (int i = 0; i < SIZE; i++) {
		cout << i << " " << numbers[i] << " ms ";
	}

	return (sum * h);
}

double simpson_integral(pointFunc f, double a, double b, int n) {
	double x1, x2, h;
	double sum = 0.0;
	double numbers[SIZE];

	cout << "\n";
	#pragma omp parallel reduction(+:sum) num_threads(SIZE)
	{
		auto begin = std::chrono::steady_clock::now();

		h = (b - a) / (n * omp_get_num_threads());
		for (int i = 0; i < n; i++) {
			x1 = a + n * h * omp_get_thread_num() + i * h;
			x2 = a + n * h * omp_get_thread_num() + (i + 1) * h;

			sum += (f(x1) + 4.0 * f(0.5 * (x1 + x2)) + f(x2)) / 6.0;
		}

		auto end = std::chrono::steady_clock::now();

		auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

		numbers[omp_get_thread_num()] = elapsed_ms.count();
	}

	for (int i = 0; i < SIZE; i++) {
		cout << numbers[i] << " ms ";
	}

	return (sum * h);
}
*/
int main()
{
	setlocale(LC_ALL, "ru");

	double a, b, eps;
	double s;
	
	int n = 1; //начальное число шагов
	double integral = 3 * (sin(log(6)) - cos(log(6))) - (sin(log(2)) - cos(log(2)));

	cout << "Введите левую границу интегрирования a = ";
	cin >> a;
	cout << "\nВведите правую границу интегрирования b = ";
	cin >> b;
	cout << "\nВведите требуемую точность eps = ";
	cin >> eps;
	do {
		s = lrectangle_integral(f, a, b, n, 1);
		n = 2 * n;  //увеличение числа шагов в 2 раза, 
					//т.е. уменьшение значения шага в 2 раза
	} while (fabs(integral - s) > eps);  
					//сравнение разности приближения и интеграла с заданной точностью
	cout << "\n\nИнтеграл = " << s << endl;
	int i = n;
	for (int k = 1; k <= SIZE; k++) {
		i = n;
		while (i <= 1000 * n) {
			i *= 10;
			//auto begin = std::chrono::steady_clock::now();
			auto begin = omp_get_wtime();
			cout << lrectangle_integral(f, a, b, i, k) << " "; 
			auto end = omp_get_wtime();
			cout << end - begin << " ms ";
			//auto end = std::chrono::steady_clock::now();

			//auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

			//cout << elapsed_ms.count() << " ms ";
		}
		cout << "\n\n";
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
