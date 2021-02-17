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
	cout << "����������� ������:\t\t";
	Print(arr, n);

	//��������� ���������� ������ � �� ������ �������� � �������� �������
	int even_count = 0;//���������� ������ �������� � �������
	int odd_count = 0;//���������� �� ������ �������� � �������
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)even_count++;
		else odd_count++;
	}

	//�������� ������ ��� ��������: 
	int* even_values = new int[even_count] {};
	int* odd_values = new int[odd_count] {};

	//�������� �������� � ����������� ��������
	for (int i = 0, i_even = 0, i_odd = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)even_values[i_even++] = arr[i];
		else odd_values[i_odd++] = arr[i];
	}

	//������� �������� �� �����
	cout << "������� ������������ ��������:\t";
	Print(even_values, even_count);
	cout << "������� ����������� ��������:\t";
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