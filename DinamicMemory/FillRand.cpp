#include "DynamicMemory.h"
#include "DynamicMemory.cpp"

void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		//arr[i] = rand() % (maxRand - minRand) + minRand;
		Random(arr[i]);
	}
}
void FillRand(float arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		//arr[i] = float(rand() % (maxRand - minRand) + minRand)/10;
		Random(arr[i]);
	}
}
void FillRand(double arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		//arr[i] = double(rand() % (maxRand - minRand) + minRand)/10;
		Random(arr[i]);
	}
}
void FillRand(char arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		//arr[i] = rand();
		Random(arr[i]);
	}
}

void FillRand(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//arr[i][j] = rand() % 100;
			Random(arr[i][j]);
		}
	}
}
void FillRand(float** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//arr[i][j] = float(rand() % 100)/10;
			Random(arr[i][j]);
		}
	}
}
void FillRand(double** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//arr[i][j] = double(rand() % 100)/10;
			Random(arr[i][j]);
		}
	}
}
void FillRand(char** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//arr[i][j] = char(rand() % 100)/10;
			Random(arr[i][j]);
		}
	}
}
