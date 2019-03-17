#include<iostream>
#include<iomanip>
#include<fstream>			
#include<Windows.h>
#include<locale.h>




// VladimirOrlovA /HomeWork_14_03_2019_1552577242

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


using namespace std;

void add_positionK_column(int **&p, int n, int &m, int k)
{
	// меняем адреса указателям массива указателей
	int **tmp = new int *[n];


	for (int i = 0; i < n; i++)			// двигаемся по массиву указателей
		tmp[i] = new int[m + 1];		// добавляем к элементам одномерного массива еще один элемент	


	for (int i = 0; i < n; i++)			// двигаемся по массиву указателей
	{
		for (int j = 0; j < k; j++)		// копируем элементы с исходного массива в новый расширенный массив до k позиции
		{
			tmp[i][j] = p[i][j];
		}
	}

	for (int i = 0; i < n; i++)			// двигаемся по указателям на одномерные массивы
		tmp[i][k] = k;					// в каждый k элемент пишем значения элемента - в данном случае ноль


	for (int i = 0; i < n; i++)			// двигаемся по массиву указателей
	{
		for (int j = k + 1; j < m + 1; j++)		// копируем элементы с исходного массива в новый расширенный массив c k позиции
		{
			tmp[i][j] = p[i][j - 1];
		}
	}


	/// удаляем указатели в массиве указателей и указатели на одномерные массивы ---- ВАЖНО удаление обязательно для освобождения ОЗУ ///

	for (int i = 0; i < n; i++)			// двигаемся по указателям на одномерные массивы
		delete[] p[i];					// удаляем указатели(адреса) на одномерные массивы в массиве указателей

	delete[] p;							// удаляем массив указателей
	p = tmp;
	m++;								// увеличиваем размер одномерного массива на 1 элемент
}

void fill_array(int **pp, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			pp[i][j] = rand() % 21;
		}
	}
}

void print_array(int **pp, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << pp[i][j] << "\t";
		}
		cout << endl;
	}
}


void sum2array(int **arr1, int **arr2, int **arrSum, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			arrSum[i][j] = arr1[i][j] + arr2[i][j];
		}
		//cout << endl;
	}
}

void Task1()
{
	/*1. Создать функцию, вставляющую столбец в двумерный динамический массив в указанную позицию.*/
	
	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n--------------------------------------------------------------------------\n\nTask1\n\n";
	SetConsoleTextAttribute(hConsole, 7);

	int **arr;
	int n, m, k;

	cout << "Введите кол-во строк -> ";
	cin >> n;

	cout << "Введите кол-во столбцов -> ";
	cin >> m;

	cout << "Введите номер столбца куда вставить новый столбец -> ";
	cin >> k;

	cout << endl;

	arr = new int *[n];

	for (int i = 0; i < n; i++)
		arr[i] = new int[m];

	fill_array(arr, n, m);
	print_array(arr, n, m);
	add_positionK_column(arr, n, m, k);

	cout << endl << "Массив после добавления столбца" << endl << endl;

	print_array(arr, n, m);

	for (int i = 0; i < n; i++)
		delete[] arr[i];
	delete[] arr;

	cout << endl;
	
}

void Task2()
{
	/*2.	Написать программу, которая поэлементно суммирует два динамических двумерных массива, заполненных 
	случайными числами и сохраняет результат в третьем массиве. Размеры исходных массивов  задаются пользователем.*/

	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n--------------------------------------------------------------------------\n\nTask2\n\n";
	SetConsoleTextAttribute(hConsole, 7);

	int **arr1;
	int **arr2;
	int **arrSum;
	int n, m;

	cout << "Введите кол-во строк -> ";
	cin >> n;

	cout << "Введите кол-во столбцов -> ";
	cin >> m;

	cout << endl;

	arr1 = new int *[n];
	arr2 = new int *[n];
	arrSum = new int *[n];

	for (int i = 0; i < n; i++)
	{
		arr1[i] = new int[m];
		arr2[i] = new int[m];
		arrSum[i] = new int[m];
	}

	fill_array(arr1, n, m);
	fill_array(arr2, n, m);

	cout << "\nМассив 1 ->\n\n";
	print_array(arr1, n, m);

	cout << "\n\nМассив 2 ->\n\n";
	print_array(arr2, n, m);
	

	cout << endl << "Сумарный массив, массивов 1 и 2" << endl << endl;

	sum2array(arr1, arr2, arrSum, n, m);

	print_array(arrSum, n, m);

	for (int i = 0; i < n; i++)
	{
		delete[] arr1[i];
		delete[] arr2[i];
		delete[] arrSum[i];
	}
	delete[] arr1;
	delete[] arr2;
	delete[] arrSum;

	cout << endl;
	 
	
}


int main()
{
	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n Orlov Vladimir HomeWork_14_03_2019_1552577242 \n\n";
	SetConsoleTextAttribute(hConsole, 7);

	/*SetConsoleCP(1251);
	SetConsoleOutputCP(1251);*/

	setlocale(LC_ALL, "");

	int number;
	char flag;

	do
	{
		cout << endl << "Enter number of Task (1) to (2) => ";
		cin >> number;

		switch (number)
		{
		case 1: {Task1(); } break;
		case 2: {Task2(); } break;

		default: cout << "\nEntered number of Task does not exist...\n\n";

		}

		SetConsoleTextAttribute(hConsole, 10);
		cout << "\n--------------------------------------------------------------------------\n\n";
		SetConsoleTextAttribute(hConsole, 7);

		cout << "Do you want to continue? \n\nIf YES press (y) if NO press any keys => ";
		cin >> flag;

	} while (flag == 'y');
}