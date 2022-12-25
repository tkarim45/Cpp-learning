#include <iostream>
using namespace std;
void populatearray(int* p, int size)
{
	cout << "Enter the Elements:" << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> p[i];
	}
}
void copyarray(int* x, int* y, int size1, int size2)
{
	int j = 0;
	for (int i = size2; i < size1; i++)
	{
		y[j] = x[i];
		j++;
	}
}
void printarray(int* p, int size)
{
	for (int i = 0; i <= size - 1; i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;
}
int main()
{
	int size1, size, red;
	cout << "Enter the size of First Array: "; cin >> size;
	int* array1 = new int[size];
	populatearray(array1, size);
	cout << "Original Array is :";
	printarray(array1, size);
	cout << "Enter the Reduced size of Array: "; cin >> red;
	size1 = size - red;
	int* array2 = new int[red];
	copyarray(array1, array2, size, size1);
	cout << "Reduced array is:";
	printarray(array2, red);
	delete[] array1;
	array1 = array2;
	array2=nullptr;
}


