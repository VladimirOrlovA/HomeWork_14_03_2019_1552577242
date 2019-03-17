#include<iostream>
#include<fstream>			
#include<Windows.h>
#include<locale.h>




// VladimirOrlovA /HomeWork_14_03_2019_1552577242

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


using namespace std;

void Task1()
{
	/*1. Создать функцию, вставляющую столбец в двумерный динамический массив в указанную позицию.*/

	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n--------------------------------------------------------------------------\n\nTask1\n\n";
	SetConsoleTextAttribute(hConsole, 7);


}

void Task2()
{
	/*2.	Написать программу, которая поэлементно суммирует два динамических двумерных массива, заполненных 
	случайными числами и сохраняет результат в третьем массиве. Размеры исходных массивов  задаются пользователем.*/

	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n--------------------------------------------------------------------------\n\nTask2\n\n";
	SetConsoleTextAttribute(hConsole, 7);

	 

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