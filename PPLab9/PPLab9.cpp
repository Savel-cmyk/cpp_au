// PPLab9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <omp.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <process.h>
#include <time.h>
#include <locale.h>
#include <windows.h>

using namespace std;

struct customerStruct {
int index;
int state;// - статус посетителя:
// 0 - посетитель не в парикмахерской;
// 1 - посетитель в парикмахерской
// и ожидает обслуживания;
// 2 - парикмахер пригласил посетителя
// в рабочую комнату;
// 3 - посетитель ещё в парикмахерской,
// но стрижка уже окончена.
customerStruct* pNext;
};

void customer(customerStruct*& pFirst, //амперсантом говориться, что можно будет изменять данные в памяти, 
									   //звёздочкой, что передаётся указатель
	customerStruct*& pLast,
	int& queueLength,
	int queueMaxLength,
	int customerThreads,
	int& totalCustomers,
	omp_lock_t queueLock) {
#pragma omp parallel num_threads(customerThreads)
		{
			customerStruct self;
			while (true)
			{
				self.state = 0;
				self.pNext = nullptr;
				Sleep(rand() % 5000);
				omp_set_lock(&queueLock);
				self.index = ++totalCustomers;

#pragma omp critical
				{
					printf(": Пришёл новый посетитель %d.\n", self.index);
				}
				if (queueLength < queueMaxLength)
				{
					if (pFirst == nullptr)
						pFirst = pLast = &self;
					else
					{
						(*pLast).pNext = &self;
						pLast = &self;
					}
					queueLength++;
					self.state = 1;
#pragma omp critical
					{
						printf("Посетитель %d занял место в комнате ожидания. ", self.index);
						printf("В очереди %d посетителей.\n", queueLength);
					}
					omp_unset_lock(&queueLock);
					while (self.state != 2)
						Sleep(1);
					omp_set_lock(&queueLock);
					pFirst = (*pFirst).pNext;
					if (pFirst == nullptr)
						pLast = nullptr;
					queueLength--;
#pragma omp critical
					{
						printf(": Посетитель %d прошёл в рабочую комнату. ", self.index);
						printf("В очереди %d посетителей.\n", queueLength);
					}

					omp_unset_lock(&queueLock);
					while (self.state != 3)
						Sleep(100);
#pragma omp critical
					{
						printf(": Посетитель %d ушёл.\n", self.index);
					}
				}
				else
				{


#pragma omp critical
					{
						printf("Свободных мест нет. Посетитель %d ушёл.\n", self.index);
						omp_unset_lock(&queueLock);
					}
				}
			}
		}
}

void barber(customerStruct*& pFirst)
{
	int state = 0;
	customerStruct* pCurrent = nullptr;
	while (true)
		if (pFirst != nullptr)
		{
			if (state == 0)
			{
#pragma omp critical
				{
					printf(": Парикмахер проснулся.\n");
				}
			}
			state = 1;
			pCurrent = pFirst;
#pragma omp critical
			{
				printf(": Парикмахер пригласил посетителя %d в рабочую комнату.\n",
					(*pCurrent).index);
			}
			(*pCurrent).state = 2;
			Sleep(5000);

#pragma omp critical
			{
				printf(": Парикмахер закончил стричь посетителя %d.\n",
					(*pCurrent).index);
			}
			(*pCurrent).state = 3;
		}
		else
		{
			if (state == 1)
			{
#pragma omp critical
				{
					printf(": Больше нет посетителей. Парикмахер заснул.\n");
				}
			} 
			state = 0;
		}
}

void main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	customerStruct* pFirst = nullptr, 
		* pLast = nullptr;
	int queueLength = 0,
		queueMaxLength = 0,
		totalCustomers = 0,
		customerThreads = 0;
	omp_lock_t queueLock;
	omp_init_lock(&queueLock);
	omp_set_nested(true);
	printf("Программная реализация задачи \"Спящий парикмахер\".\n\n");
	printf("Введите количество мест в комнате ожидания: ");
	cin >> queueMaxLength;
	printf("Введите количество потоков, моделирующих посетителей: ");
	cin >> customerThreads;
	printf("\nМоделирование началось. Для завершения работы нажмите Ctrl+C.\n");
#pragma omp parallel sections num_threads(2)
	{
#pragma omp section
		{ 
			customer(pFirst, pLast,
				queueLength, queueMaxLength,
				customerThreads, totalCustomers,
				queueLock);
		}
#pragma omp section
		{ 
			barber(pFirst);
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
