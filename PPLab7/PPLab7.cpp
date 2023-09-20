// PPLab7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <omp.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <vector>

std::vector<int> v;
omp_lock_t lock;

void writer() {
    while (true) {
        omp_set_lock(&lock);

        v.push_back(rand() % 100);
        printf("Write book %d %zu\n", v.back(), v.size());

        omp_unset_lock(&lock);
        Sleep(rand() % 1001);
    }
}

void reader() {
    while (true) {
        omp_set_lock(&lock);

        if (!v.empty())
            printf("Get book %d\n", v[rand() % v.size()]);
        else
            printf("Storage is empty invoked from reader\n");

        omp_unset_lock(&lock);
        Sleep(rand() % 1001);
    }
}

int main() {
    srand(time(NULL));

    omp_init_lock(&lock);

    printf("Reader-writer\n\n");
    printf("The simulation has begun. Press Ctrl+C to exit.\n");
#pragma omp parallel sections num_threads(3)
    {
#pragma omp section
        {
            writer();
        }
#pragma omp section
        {
            reader();
        }
#pragma omp section
        {
            reader();
        }
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
