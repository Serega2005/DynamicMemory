#include "DynamicMemory.h"

template<typename T>T** Allocate(const int m, const int n)
{
	//1)создаём массив указателей:
	T** arr = new T * [m];

	//2) Выделяем память для строк двумерного динамического массива:
	for (int i = 0; i < m; i++)
	{
		arr[i] = new T[n];
	}
	return arr;
}
template<typename T>void Clear(T** arr, const int m)
{
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

template<typename T>void Random(T& variable)
{
	if (typeid(variable) == typeid(int))
	{
		variable = rand() % 100;
	}
	else if (typeid(variable) == typeid(float) || typeid(variable) == typeid(double))
	{
		variable = double(rand() % 10000) / 100;
	}
	else if (typeid(variable) == typeid(char))
	{
		variable = rand();
	}
	else
	{
		variable = T();//записываем в переменную значение по умолчанию
	}
}

template<typename T>void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
template<typename T>void Print(T** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

template<typename T>void push_back_mutable(T*& arr, int& n, T value)
{
	T* buffer = new T[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[n] = value;
	n++;
}
template<typename T>void push_front_mutable(T*& arr, int& n, T value)
{
	//создаем буферныйй массив нужнного размера
	T* buffer = new T[n + 1]{};
	//копируем значение из исходного массива в буферный со смещением на 1 элемент
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	//удаляем исходный массив
	delete[] arr;
	//подменяем указатель на адрес нового массива
	arr = buffer;
	//добавляем значение в начало массива
	arr[0] = value;
	// увеличивае5м массив на 1
	n++;
}
template<typename T>void insert(T*& arr, int& n, T value, int index)
{
	if (index >= n)return;
	T* buffer = new T[n + 1]{};
	/*for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}*/
	for (int i = 0; i < n; i++)
	{
		//(i < index) ? buffer[i] = arr[i] : buffer[i + 1] = arr[i];
		(i < index ? buffer[i] : buffer[i + 1]) = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
}
template<typename T>void insert_row(T**& arr, int& m, const int n, int index)
{
	if (index > m)return;
	T** buffer = new T * [m + 1]{};
	for (int i = 0; i < index; i++)
		buffer[i] = arr[i];
	for (int i = index; i < m; i++)
		buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	m++;
	arr[index] = new T[n]{};
}
template<typename T>void insert_col(T** arr, const int m, int& n, int index)
{
	if (index > n)return;
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n + 1]{};
		for (int j = 0; j < index; j++)
			buffer[j] = arr[i][j];
		for (int j = index; j < n; j++)
			buffer[j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	n++;
}

template<typename T>void pop_back(T*& arr, int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
}
template<typename T>void pop_front(T*& arr, int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];

	}
	delete[] arr;
	arr = buffer;
}

template<typename T>void pop_row_back(T**& arr, int& m, const int n)
{
	T** buffer = new T * [--m]{};
	for (int i = 0; i < m; i++)
		buffer[i] = arr[i];
	delete[] arr[m];//удаляем строку из памяти
	delete[] arr;//удаляем массив указателей
	arr = buffer;//подменяем на новый массив указателей
}
template<typename T>void pop_row_front(T**& arr, int& m, const int n)
{
	T** buffer = new T * [--m]{};
	for (int i = 0; i < m; i++)
		buffer[i] = arr[i + 1];
	delete[] arr[0];
	delete[] arr;
	arr = buffer;
}
template<typename T>void pop_col_back(T**& arr, const int m, int& n)
{
	T** buffer = new T * [--n]{};
	for (int i = 0; i < m; i++)
		buffer[i] = arr[i];
	delete[] arr;
	arr = buffer;
}
template<typename T>void pop_col_front(T**& arr, const int m, int& n)
{
	T** buffer = new T * [--n]{};
	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
}

template<typename T>void push_col_back(T** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		//Создаём буферную строку нужного размера
		T* buffer = new T[n + 1]{};
		//Копируем исходную строку в буферную
		for (int j = 0; j < n; j++)
			buffer[j] = arr[i][j];
		//Удаляем исходную строку
		delete[] arr[i];
		//Подменяем адрес
		arr[i] = buffer;
	}
	n++;
}
template<typename T>void push_col_front(T** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		//Создаём буферную строку нужного размера
		T* buffer = new T[n + 1]{};
		//Копируем исходную строку в буферную
		for (int j = 0; j < n; j++)
			buffer[j + 1] = arr[i][j];
		//Удаляем исходную строку
		delete[] arr[i];
		//Подменяем адрес
		arr[i] = buffer;
	}
	n++;
}
template<typename T>void push_row_back(T**& arr, int& m, const int n)
{
	T** buffer = new T * [m + 1];
	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	buffer[m] = new T[n]{};
	m++;
}
template<typename T>void push_row_front(T**& arr, int& m, const int n)
{
	T** buffer = new T * [m + 1];
	buffer[0] = new T[n]{};
	for (int i = 0; i < m; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	m++;
}

template<typename T>void erase(T*& arr, int& n, int index, T value)
{
	/*T* buffer = new T[--n];
	for (int i = 0; i < n; i++)
	{
		i = index ? arr[n]=arr
	}
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	buffer - arr[index];*/
}
template<typename T>void erase_row(T** arr, int& m, const int n, int index)
{
	/*if (index > m)return;
	T* buffer = new T[--m];
	for (int i = 0; i < n; i++)
	{
		i = index ? arr[n] = arr
	}
	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	buffer - arr[index];*/
}
