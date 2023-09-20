// PPLab8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define NUM_PHIL 5      //The number of philosophers
#define MEALS 100        //The number of meals per philosopher

static omp_lock_t forks[NUM_PHIL];   //Locks to represent forks

void philosopher()
{
#pragma omp barrier

    int id = omp_get_thread_num();
    int right_fork;
    int left_fork;

    if (id < NUM_PHIL - 1)
    {
        right_fork = id;
        left_fork = id + 1;
    } else
    {
        right_fork = 0;
        left_fork = id;
    }

    int i;
    srand(time(NULL));
    for (i = 0; i < MEALS; i++)
    {
        omp_set_lock(&forks[left_fork]);
        printf("Philosopher %d took fork %d\n", id, left_fork);
        omp_set_lock(&forks[right_fork]);
        printf("Philosopher %d took fork %d\n", id, right_fork);

        printf("Philosopher %d is eating\n", id);
        Sleep(1000);

        omp_unset_lock(&forks[left_fork]);
        printf("Philosopher %d freed fork %d\n", id, left_fork);
        omp_unset_lock(&forks[right_fork]);
        printf("Philosopher %d freed fork %d\n", id, right_fork);

        printf("Philosopher %d is thinking\n", id);
        Sleep((rand()%10)*100);
    }
}

int main()
{
    int i;

    for (i = 0; i < NUM_PHIL; i++)
        omp_init_lock(&forks[i]);

#pragma omp parallel num_threads(NUM_PHIL)
    {
        philosopher();
    }

    for (i = 0; i < NUM_PHIL; i++)
        omp_destroy_lock(&forks[i]);

    return 0;
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
