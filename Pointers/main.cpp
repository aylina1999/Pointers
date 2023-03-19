#include<iostream>
using namespace std;

//#define POINTERS_BASICS

void main()
{
	setlocale(LC_ALL, "");
#ifdef POINTERS_BASICS
	int a = 2;
	int* pa = &a;        //pa - указатель на переменную 'a'
	cout << a << endl;   //¬ывод значени€ переменной 'a' на экран
	cout << &a << endl;  //¬з€тие адреса переменной 'a' пр€мо при выводе
	cout << pa << endl;  //¬ывод адреса переменной 'a', хран€щегос€ в указателе 'pa'
	cout << *pa << endl; //–азыменование указател€ 'pa', дл€ того чтобы получить значение по адресу

	int* pb;
	int b = 3;
	pb = &b;
#endif // POINTERS_BASICS

	const int n = 5;
	int arr[n] = { 3, 5, 8, 13, 21 };
	
	cout << arr << endl;
	cout << *arr << endl;
	
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;

}