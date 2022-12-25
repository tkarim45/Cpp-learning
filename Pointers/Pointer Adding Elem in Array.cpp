#include<iostream>
#include<malloc.h>
using namespace std;
int main()
{
	int size;
	int bytes = 0;
	cout << "Enter the Size of the array: "; cin >> size;
	new int[size];
	int* darray = new int[size];
	cout << "Enter the Elements of the Array: " << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> darray[i];
	}
	cout << "The Original Array is: ";
	for (int i = 0; i < size; i++)
	{
		cout << darray[i] << " ";
	}
	cout << endl;
	int elem;
	cout << "Enter How Many Elements You want to Input: "; cin >> elem;
	int* newarray = new int[size+elem];
	for (int i = 0; i < size; i++)
	{
		newarray[i] = darray[i];
	}
	cout << "Enter the Elements: " << endl;
	for (int i = size; i < size + elem; i++)
	{
		cin >> newarray[i];
	}
	delete[] darray;
	darray = newarray;
	size = size + elem;
	newarray = nullptr;
	cout << "The Updated Array is: ";
	for (int i = 0; i < size; i++)
	{
		cout << darray[i] << " ";
	}
	cout << endl;
}
