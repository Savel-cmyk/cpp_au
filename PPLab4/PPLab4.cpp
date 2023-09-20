// PPLab4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _USE_MATH_DEFINES

#include <iostream>
#include <omp.h>
#include <math.h>
#include <cmath>
#include <chrono>

#define SIZE 12
using namespace std;
typedef double(*pointFunc)(double);

double f(double x) {
	return pow((1 + 2.0/x), pow((-1), x) * x);
}

double pi_num(pointFunc f, double n, int k) {
	double h;
	double sum = 1.0;

#pragma omp parallel reduction(*:sum) num_threads(k) //reduction позволяет суммировать без потери данных
	{

		h = n / omp_get_num_threads();  //шаг
		h = (int(h) == h ? h : int(h + 1));
		for (double i = 2.0 + h * omp_get_thread_num(); i < 2.0 + h * (omp_get_thread_num() + 1); i++) {
			if (i <= (1 + n)) sum *= f(i);
		}
		//printf("%f нить %d\n", sum * h, omp_get_thread_num());
	}

	return (6.0 / (M_E * sum)); //приближенное значение интеграла равно 
					  //сумме площадей прямоугольников
}

int main()
{
	setlocale(LC_ALL, "ru");

	double eps;
	double s;

	double n = 2.0; //начальное число шагов минус 1

	cout << "Введите требуемую точность eps = ";
	cin >> eps;
	do {
		s = pi_num(f, n, 1);
		n = 2.0 * n;  //увеличение числа шагов в 2 раза, 
					//т.е. уменьшение значения шага в 2 раза
	} while (fabs(M_PI - s) > eps);
	//сравнение разности приближения и интеграла с заданной точностью
	cout << "\n\nРезультат = " << s << endl;
	int i = n;
	for (int k = 1; k <= SIZE; k++) {
		i = n;
		while (i <= 100 * n) {
			i *= 10;
			//auto begin = std::chrono::steady_clock::now();
			auto begin = omp_get_wtime();
			cout << pi_num(f, i, k) << " ";
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
