#include <iostream>
#include <time.h>
#include <random>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
/*eсть массив 'arr' из 10-ти элементов, заполненный случайными числами. Нужно создать еще два массива 'even' и 'odd' минимально возможного размера, в массив 'even' нужно скопировать все четные значения из исходного массива, а в массив
'odd' - нечетные. Массивы 'even' и 'odd' вывести на экран.*/

// прототипы функций выносятся в заголовочные файлы

template <typename T>
void push_back(T*& arr, int& n, int value);
template <typename T>
void push_front(T*& arr, int& n, int value);
template <typename T>
void insert(T*& arr, int& n);
template <typename T>
void erase(T*& arr, int& n);
template <typename T>
void push_row_back(T**& arr, int& m, const int n);
template <typename T>
void push_row_front(T**& arr, int& m, const int n);
template <typename T>
void pop_back(T*& arr, int& n);
template <typename T>
void pop_front(T*& arr, int& n);


void FillRand(double arr[], const int n);
template <typename T>
void FillRand(T** arr, const int m, const int n);
void FillRand(double** arr, const int m, const int n);
template <typename T>
void print(T arr[], int n);
template <typename T>
void print(T** arr, const int m, const int n);
//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
//#define DEBUG_ARRAYS

int main()
{
	setlocale(LC_ALL, "ru");
#ifdef DYNAMIC_MEMORY_1
	int n = 0;
	cout << "введите количество элементов массива" << endl;
	cin >> n;
	int* arr = new int[n] {};
	FillRand(arr, n);
	print(arr, n);
	int value;
	cout << "введите добавляемое значение" << endl;
	cin >> value;
	push_back(arr, n, value);
	print(arr, n);

	cout << endl;

	cout << "введите добавляемое значение" << endl;
	cin >> value;
	push_front(arr, n, value);
	print(arr, n);


	cout << "удаление последнего элемента" << endl;
	pop_back(arr, n);
	print(arr, n);

	cout << "удаление нулевого элемента" << endl;
	pop_front(arr, n);
	print(arr, n);

	cout << "функция erase удаление элемента по выбранному индексу " << endl;
	erase(arr, n);
	print(arr, n);

	cout << "функция insert удаление элемента по выбранному индексу " << endl;
	insert(arr, n);
	print(arr, n);

	delete[] arr;
#endif // DYNAMIC_MEMORY_1
#ifdef DYNAMIC_MEMORY_2



	int m; // количество строк
	int n; // количетво элементов строки
	cout << "введите количество строк  "; cin >> m;
	cout << "введите количество элементов строки  "; cin >> n;

	// создаем массив указателей

	 double** arr = new double* [m];

	// выделяем память под строки двумерного массива

	for (int i = 0; i < m; i++)
	{
		arr[i] = new double[n] {};
	}

	/* cout << "Память выделена " << endl;
	 system("pause");*/

	FillRand(arr, m, n);
	print(arr, m, n);

	cout << "Добавление строки в конец массива " << endl;
	push_row_back(arr, m, n);
	cout << "Добавление строки в начало массива " << endl;
	push_row_front(arr, m, n);
	print(arr, m, n);

	cout << "Добавление столбца в конец массива " << endl;
	//push_col_back(arr, m, n);
	print(arr, m, n);

	//удаление думерного динамическго массива

	//1) удаление строк
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}

	// удаление массива указателей
	delete[] arr;
#endif // DYNAMIC_MEMORY_2


#ifdef DEBUG_ARRAYS

	const int n = 5;
	int arr[n] = { 3,5,8,13,21 };
	print(arr, n);
#endif // DEBUG_ARRAYS


}
// реализации выносят в cpp файлы

/*for (int i = 0; i < q; i++)
{
	buffer[q] = a;
}

for (int j = q; q < n; j++)
{
	buffer[j] = arr[j + 1];
}
*/


template <typename T>
void FillRand(T* arr, int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 20;
	}

}

template <typename T>
void FillRand(T** arr, const int m, const int n)
{
	// использование двумерного динамического массива
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = 1 + rand() % 100;
		}
	}
}
void FillRand(double** arr, const int m, const int n)
{
	// использование двумерного динамического массива
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = 1 + double(rand() % 10000) / 100;
		}
	}
}
template <typename T>
void print(T* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
template <typename T>
void print(T** arr, const int m, const int n)
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

template<typename T>
void push_row_back(T**& arr, int& m, const int n)
{
	//  1) создаем буферный массив
	T** buffer = new T* [m + 1];
	/*for (int i = 0; i < m + 1; i++)
	{
		buffer[i] = new int[n] {};
	}*/

	// 2) копируем все значения исходного массива в буферный
	for (int i = 0; i < m; i++)
	{
		/*for (int j = 0; j < m; j++)
		{
			buffer[i][j] = arr[i][j];
		}*/
		buffer[i] = arr[i];
	}
	// 3) удаляем иссходный массив
	/*for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}*/
	// не нужно удалять строки, достаточно удалить старый массивуказателей
	delete[] arr;

	// 4) переопределить новый массив (массив указателей)
	arr = buffer;
	arr[m] = new T[n] {};
	m++;
}
template <typename T>
void push_row_front(T**& arr, int& m, const int n)
{
	T** buffer = new T* [m + 1]{};
	for (int i = 0; i < m; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	//подменяем адрес на новый массив
	arr = buffer;
	arr[0] = new T[n] {};
	m++;

}

/*void pop_row_back(int**& arr, int& m, const int n)
{
	int** buffer = new int* [--m];
	for (int i = 0; i < m; i++)
	{
		buffer[] = arr[i];
	}
	delete[] arr;
	arr=buffer
}
*/

template <typename T>
void push_col_back(T** arr, const int m, int& n)
{
	// проходим по строкам и переопределяем каждую строку
	for (int i = 0; i < m; i++)
	{
		//1) создаем строку нужного размера
		int* buffer = new T* [n + 1]{};
		//2) копируем исходную строку в новую строку
		for (int j = 0; j < n; j++)
		{
			buffer[j] = arr[i][j];
		}

		//3)удаляем исходную строку
		delete[] arr[i];

		//4) подменяем адрес старой строки адресом новой
		arr[i] = buffer;
	}

	// 6) После того, как мы переопределили каждую строку, увеличиваем количество строк на единицу
	n++;
}


template<typename T>
void pop_back(T*& arr, int& n)
{
	T* buffer = new T[--n]{};
	//для того, чтобы удалить элемент из массива в буферный массив нужно скопировать все элементы кроме удаляемого
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;


}
template <typename T>
void pop_front(T*& arr, int& n)
{
	int* buffer = new T[--n]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
}
template <typename T> 
void FiilRand(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}

void FiilRand(double** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; i++)
		{
			arr[i][j] = double(rand() % 100000)/100;
		}
	}
}