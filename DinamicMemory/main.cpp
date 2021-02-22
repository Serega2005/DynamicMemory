#include "DynamicMemory.h"
#include "DynamicMemory.cpp"

#define Probel "-------------------------------------------------------------------------------------------\n"

//#define DINAMIC_MEMORY_1
#define DINAMIC_MEMORY_2


typedef double DataType;
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

#ifdef DINAMIC_MEMORY_2

	int m; // количество строк
	int n; // количество столбцов(элементов строки)
	cout << "Введите количество строк: "; cin >> m;
	cout << "Введите количество столбцов:  "; cin >> n;

	DataType** arr = Allocate<DataType>(m, n);

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

	//cout << "Удаляет строку массива по указанному индексу:"; cin >> index;
	//erase_row(arr, m, n, index);
	//Print(arr, m, n);
	//cout << Probel;

	cout << "Удаляет столбец с конца массива:" << endl;
	pop_col_back(arr, m, n);
	Print(arr, m, n);
	cout << Probel;

	cout << "Удаляет столбец с начала массива:" << endl;
	pop_col_front(arr, m, n);
	Print(arr, m, n);
	cout << Probel;

	Clear(arr, m);
#endif // DINAMIC_MEMORY_2
}
