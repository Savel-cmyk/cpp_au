// PPLab5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <omp.h>
#include <math.h>
#include <cmath>
#include <vector>
#include <algorithm>

#define SIZE 12
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	int n, m;
	bool b;
	std::vector<int> num;

	cout << "Введите левую границу m = ";
	cin >> m;
	cout << "\nВведите правую границу n = ";
	cin >> n;
	for (int k = 1; k <= SIZE; k++) {
		num.clear();
		omp_set_num_threads(k);
        auto begin = omp_get_wtime();
            
        #pragma omp parallel private(b)
		#pragma omp for
		for (int i = m; i <= n; i++) {
			b = true;
			if (i == 1) b = false;
			else if (i == 2) b = true;
			else
				for (int k = 2; k < sqrt(i) + 1; k++)
					if (i % k == 0)
						b=false;
		//	#pragma omp critical
			//{
				//if (b) num.push_back(i);
			//}
		}

		//sort(num.begin(), num.end());
//		for (int i = 0; i < num.size(); i++) cout << num[i] << ", ";
		auto end = omp_get_wtime();
		cout << end - begin << " ms ";
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

