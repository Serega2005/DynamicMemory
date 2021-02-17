#include <iostream>
#include <ctime>
using namespace std;

#define Probell "-------------------------------" 

void FillRand(int arr[], const int n);
void Print(int* arr, const int n);

void main()
{
	setlocale(LC_ALL, "Russian");
	const int n = 10;
	int arr[n];
	srand(time(NULL));
	FillRand(arr, n, 0, 1000);
	cout << "Изначальный массив:\t\t";
	Print(arr, n);

	//посчитаем количество чётных и не чётных значений в исходном массиве
	int even_count = 0;//количество чётных значених в массиве
	int odd_count = 0;//количество не чётных значений в массиве
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)even_count++;
		else odd_count++;
	}

	//Выделяем память для массивов: 
	int* even_values = new int[even_count] {};
	int* odd_values = new int[odd_count] {};

	//Копируем значения в соответсвии массивыж
	for (int i = 0, i_even = 0, i_odd = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)even_values[i_even++] = arr[i];
		else odd_values[i_odd++] = arr[i];
	}

	//Выводим масссивы на экран
	cout << "Выводим максимальные значения:\t";
	Print(even_values, even_count);
	cout << "Выводим минимальные значения:\t";
	Print(odd_values, odd_count);

	delete[] odd_values;
	delete[] even_values;
}

void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 10;
	}
}

void Print(int* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
	cout << Probell << endl;
}