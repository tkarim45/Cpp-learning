#include<iostream>
using namespace std;
int main()
{
	int size;
	cout << "Enter the Size of th Array: "; cin >> size;
	int* darray = new int[size];
	cout << "Enter the Elements of the Array: " << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> darray[i];
	}
	cout << "The Original Array is: ";
	for (int i = 0; i < size; i++)
	{
		cout << " " << darray[i];
	}
	cout << endl;
	int ind,val;
	cout << "Enter the Index at Which You want to Replace the Value: "; cin >> ind;
	cout << "Enter the Value: "; cin >> val;
	for (int i = 0; i<size; i++)
	{
		if (i == ind)
		{
			darray[i] = val;
		}
	}
	cout << "The Updated Array is: ";
	for (int i = 0; i < size; i++)
	{
		cout << darray[i] << " ";
	}
	cout << endl;
	delete[] darray;
	darray = nullptr;
}