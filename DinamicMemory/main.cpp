#include<iostream>
using std::cin;
using std::cout;
using std::endl;


#define Probel "--------------------------------------------\n"

int** Allocate(const int m, const int n);
void Clear(int** arr, const int m);

void FillRand(int arr[], const int n, int minRand, int maxRand);
void FillRand(int** arr, const int m, const int n);

void Print(int arr[], const int n);
void Print(int** arr, const int m, const int n);

void push_back_mutable(int*& arr, int& n, int value);
void push_front_mutable(int*& arr, int& n, int value);

void insert(int*& arr, int& n, int value, int index);
void insert_row(int**& arr, int& m, const int n, int index);
void insert_col(int** arr, const int m, int& n, int index);

void pop_back(int*& arr, int& n);
void pop_row_back(int**& arr, int& m, const int n);
void pop_row_front(int**& arr, int& m, const int n);
void pop_col_back(int**& arr, const int m, int& n);
void pop_col_front(int**& arr, const int m, int& n);
void pop_front(int*& arr, int& n);

void erase(int*& arr, int& n, int index, int value);
void erase_row(int** arr, int& m, const int n, int index);

void push_row_back(int**& arr, int& m, const int n);
void push_row_front(int**& arr, int& m, const int n);

void push_col_back(int** arr, const int m, int& n);
void push_col_front(int** arr, const int m, int& n);

//#define DINAMIC_MEMORY_1
#define DINAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef DINAMIC_MEMORY_1
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	cout << Probel;

	int value;
	/*cout << "Введите добавляемое значение: "; cin >> value;

	push_back_mutable(arr, n, value);
	Print(arr, n);
	cout << Probel;

	cout << "Введите добавляемое значение: "; cin >> value;
	push_front_mutable(arr, n, value);
	Print(arr, n);
	cout << Probel;*/

	int index;
	cout << "Введите добавляемое значение: "; cin >> value;
	cout << "Введите добавляемое индекс: "; cin >> index;
	insert(arr, n, value, index);
	Print(arr, n);
	cout << Probel;

	cout << "Удаляем элемент с конца массива" << endl;
	pop_back(arr, n);
	Print(arr, n);
	cout << Probel;

	cout << "Удаляем элемент с начала массива" << endl;
	pop_front(arr, n);
	Print(arr, n);
	cout << Probel;

	cout << "Введите индекс удаляемого значения: "; cin >> index;
	erase(arr, n, index, value);
	Print(arr, n);
	cout << Probel;

	delete[] arr;
#endif // DINAMIC_MEMORY_1

	int m; // количество строк
	int n; // количество столбцов(элементов строки)
	cout << "Введите количество строк: "; cin >> m;
	cout << "Введите количество столбцов:  "; cin >> n;
	int** arr = Allocate(m, n);

	//3) Работа с двумерным динамическим массивом:
	FillRand(arr, m, n);
	Print(arr, m, n);
	cout << Probel;

	cout << "Добавляем строку в конец:\n";
	push_row_back(arr, m, n);
	FillRand(arr[m - 1], n, 0, 1000);
	Print(arr, m, n);
	cout << Probel;

	cout << "Добавляем строку в начало:\n";
	push_row_front(arr, m, n);
	FillRand(arr[m - 1], n, 0, 1000);
	Print(arr, m, n);
	cout << Probel;

	int index;
	cout << "Введите добавляемое индекс: "; cin >> index;
	insert_row(arr, m, n, index);
	Print(arr, m, n);
	cout << Probel;

	cout << "Добавление столбца в конец двумерного массива: \n" << endl;
	push_col_back(arr, m, n);
	//FillRand(arr, n, m);
	Print(arr, m, n);
	cout << Probel;

	cout << "Добавление столбца в начало двумерного массива: " << endl;
	push_col_front(arr, m, n);
	//FillRand(arr, m, n);
	Print(arr, m, n);
	cout << Probel;

	cout << "Введите индекс добавляемого столбца: "; cin >> index;
	insert_col(arr, m, n, index);
	Print(arr, m, n);
	cout << Probel;

	cout << "Удаляет строку с конца массива:" << endl;
	pop_row_back(arr, m, n);
	Print(arr, m, n);
	cout << Probel;

	cout << "Удаляет строку с начала массива:" << endl;
	pop_row_front(arr, m, n);
	Print(arr, m, n);
	cout << Probel;

	cout << "Удаляет столбец с конца массива:" << endl;
	pop_col_back(arr, m, n);
	Print(arr, m, n);
	cout << Probel;

	cout << "Удаляет столбец с начала массива:" << endl;
	pop_col_front(arr, m, n);
	Print(arr, m, n);
	cout << Probel;

	Clear(arr, m);
}

int** Allocate(const int m, const int n)
{
	//1)создаём массив указателей:
	int** arr = new int* [m];

	//2) Выделяем память для строк двумерного динамического массива:
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n];
	}
	return arr;
}

void Clear(int** arr, const int m)
{
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand - minRand) + minRand;
	}
}
void FillRand(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void Print(int** arr, const int m, const int n)
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

void push_back_mutable(int*& arr, int& n, int value)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[n] = value;
	n++;
}
void push_front_mutable(int*& arr, int& n, int value)
{
	//создаем буферныйй массив нужнного размера
	int* buffer = new int[n + 1]{};
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

void insert(int*& arr, int& n, int value, int index)
{
	if (index >= n)return;
	int* buffer = new int[n + 1]{};
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
void insert_row(int**& arr, int& m, const int n, int index)
{
	if (index > m)return;
	int** buffer = new int* [m + 1]{};
	for (int i = 0; i < index; i++)
		buffer[i] = arr[i];
	for (int i = index; i < m; i++)
		buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	m++;
	arr[index] = new int[n] {};
}
void insert_col(int** arr, const int m, int& n, int index)
{
	if (index > n)return;
	for (int i = 0; i < m; i++)
	{
		int* buffer = new int[n + 1]{};
		for (int j = 0; j < index; j++)
			buffer[j] = arr[i][j];
		for (int j = index; j < n; j++)
			buffer[j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	n++;
}

void pop_back(int*& arr, int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
}
void pop_front(int*& arr, int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];

	}
	delete[] arr;
	arr = buffer;
}
void pop_row_back(int**& arr, int& m, const int n)
{
	int** buffer = new int* [--m]{};
	for (int i = 0; i < m; i++)
		buffer[i] = arr[i];
	delete[] arr[m];//удаляем строку из памяти
	delete[] arr;//удаляем массив указателей
	arr = buffer;//подменяем на новый массив указателей
}
void pop_row_front(int**& arr, int& m, const int n)
{
	int** buffer = new int* [--m]{};
	for (int i = 0; i < m; i++)
		buffer[i] = arr[i + 1];
	delete[] arr[0];
	delete[] arr;
	arr = buffer;
}
void pop_col_back(int**& arr, const int m, int& n)
{
	int** buffer = new int* [--n];
	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
}
void pop_col_front(int**& arr, const int m, int& n)
{
	int** buffer = new int* [--n];
	for (int i = 0; i < m; i++)
	{
		buffer[i-1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
}

void push_col_back(int** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		//Создаём буферную строку нужного размера
		int* buffer = new int[n + 1]{};
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
void push_col_front(int** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		//Создаём буферную строку нужного размера
		int* buffer = new int[n + 1]{};
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
void push_row_back(int**& arr, int& m, const int n)
{
	int** buffer = new int* [m + 1];
	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	buffer[m] = new int[n] {};
	m++;
}
void push_row_front(int**& arr, int& m, const int n)
{
	int** buffer = new int* [m + 1];
	buffer[0] = new int[n] {};
	for (int i = 0; i < m; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	m++;
}

void erase(int*& arr, int& n, int index, int value)
{
	/*int* buffer = new int[--n];
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
void erase_row(int** arr, int& m, const int n, int index)
{
	/*int* buffer = new int[--m];
	for (int i = 0; i < m; i++)
	{
		i = index ? arr[n] = arr
	}*/
}
