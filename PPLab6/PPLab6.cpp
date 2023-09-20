// PPLab6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <omp.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <vector>

std::vector<int> v;
omp_lock_t lock;

void producer() {
    while (true) {
        omp_set_lock(&lock);
        if (v.size() < 10) {
            v.push_back(abs(rand() % 100));
            printf("Create product %d %zu\n", v.back(), v.size());
        }
        else
            printf("Storage is full invoked by prod\n");

        omp_unset_lock(&lock);
        Sleep(abs(rand() % 1001));
    }
}

void consumer() {
    while (true) {
        omp_set_lock(&lock);
        if (!v.empty()) {
            printf("Get product %d %zu\n", v.back(), v.size());
            v.pop_back();
        }
        else
            printf("Storage is empty invoked from consumer\n");

        omp_unset_lock(&lock);
        Sleep(abs(rand() % 1001));
    }
}

int main() {
    srand(time(NULL));

    omp_init_lock(&lock);

    printf("Producer-consumer\n\n");
    printf("The simulation has begun. Press Ctrl+C to exit.\n");
#pragma omp parallel sections num_threads(2)
    {
#pragma omp section
        {
            producer();
        }
#pragma omp section
        {
            consumer();
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
