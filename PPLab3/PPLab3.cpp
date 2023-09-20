// PPLab3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <omp.h>

using namespace std;

int main()
{
    int n = 1000; // размер матрицы
    int num;
    double sum;
 
    double* MatrixA = new double[n*n];
    double* MatrixB = new double[n*n];
    double* MatrixC = new double[n*n];

    srand(time(NULL)); // автоматическая рандомизация
    for (int m = 0; m < n*n; m++) {
        MatrixA[m] = rand() % 100;
        MatrixB[m] = rand() % 100;
    }

    /*for (int i = 0; i < o; i++)
    {
        for (int j = 0; j < o; j++)
        {
            if (MatrixA[i * o + j] < 10) { cout << MatrixA[i * o + j] << "   "; }
            else { cout << MatrixA[i * o + j] << "  "; }
        }
        cout << "\n";
    }*/

    for (int l = 1; l <= 12; l++) {
        omp_set_num_threads(l);
        int o = 10;
        while (o*o <= n*n) {
            auto begin = omp_get_wtime();
            
            #pragma omp parallel for private(sum)
            for (int i = 0; i < o; i++)
            {
                #pragma omp critical
                {   
                    num = omp_get_num_threads();
                }

                for (int k = 0; k < o; k++)
                {
                    sum = 0;
                    for (int j = 0; j < o; j++)
                    {
                        sum += MatrixA[i * n + j] * MatrixB[j * n + k];
                    }
                    MatrixC[i * n + k] = sum;
                }

            }
            cout << num << " ";
            auto end = omp_get_wtime();
            cout << end - begin << " ms  ";

            o *= 10;
        }
        cout << "\n";
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
