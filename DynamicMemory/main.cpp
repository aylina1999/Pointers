#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

int* push_back(int arr[], int& n, int value);
int* push_front(int arr[], int& n, int value);
int* insert(int arr[], int& n, int value, int index);
int* erase(int arr[], int& n, int value, int index);

int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);

#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2


void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "Введите значение добавляемого элемента: "; cin >> value;

	arr = push_back(arr, n, value);
	Print(arr, n);

	arr = push_front(arr, n, value);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);
	arr = pop_front(arr, n);
	Print(arr, n);

	int index;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> index;
	arr = insert(arr, n, value, index);
	Print(arr, n);

	
	cout << "Введите индекс удаляемого элемента: "; cin >> index;
	cout << "Введите значение удаляемого элемента: "; cin >> index;
	arr = erase(arr, n, value, index);
	Print(arr, n);

	delete[] arr;
#endif // DYNAMIC_MEMORY_1

	
}


void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//обращение к элементам массива через арифметику указателей и оператор разименования:
		*(arr + i) = rand() % 100;
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//люращение к элементам массива через оператор индексирования:
		cout << arr[i] << "\t";
	}
	cout << endl;
}

int* push_back(int arr[], int& n, int value)
{
	//1) Сздаём новый массив нужного размера:
	int* buffer = new int[n + 1];
	//2) Копируем всё содержимое исходного массива в новый:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	// 3) Удаляем исходный массив:
	delete[] arr;
	// 4) Подменяем адрес старого массива, адресом нового массива:
	arr = buffer;
	// 5) После всего этого в массиве 'arr' появляется элемент, в который можно сохранить добавляемое значение:
	arr[n] = value;
	// 6)  После добавления элемента в массив, количество его элементов увеличивается на 1:
	n++;
	return arr;
}

int* push_front(int arr[], int& n, int value)  //Добавляем элемент в начало массива:

{
	//1) Создание нового массива нужного размера (на 1 элемент больше):
	int* buffer = new int[n + 1];
	//2) Копирование всего содержимого из исходного массива в буферный:
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	//3)Удаляем исходный массив:
	delete[] arr;
	//4)Помещаем добавляемое значение в начало массива:
	buffer[0] = value;
	//5)После добавления элемента в начало массива, колличество его элементов уведичивается на 1:
	n++;
	//6)Возвращаем новый массив на место вызова:
	return buffer;
}

int* insert(int arr[], int& n, int value, int index)  //Добавление в массив элемент по заданному индексу:
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	buffer[index] = value;
	n++;
	return buffer;
}

int* erase(int arr[], int& n, int value, int index) //Удаление элемента массива по указанному индексу:
{
	int* buffer = new int[--n];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	buffer[index] = value;
	n++;
	return buffer;

}

int* pop_back(int arr[], int& n) // Удаление последнего элемента массива:
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	return buffer;
}

int* pop_front(int arr[], int& n)  //Удаление первого элемента массива:
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	return buffer;
}