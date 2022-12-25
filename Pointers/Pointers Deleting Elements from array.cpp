#include<iostream>
using namespace std;
int main()
{
	int size,del,count=0;
	cout << "Enter the size of the array: "; cin >> size;
	int *darray = new int[size];
	cout << "Enter the Values: " << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> darray[i];
	}
	cout << "The Original Array is: ";
	for (int i = 0; i < size; i++)
	{
		cout <<darray[i] << " ";
	}
	cout << endl;
	cout << "Enter the Value you want to delete: ";	cin >> del;
	for (int i = 0; i < size; i++)
	{
		if (darray[i] == del)
		{
			count++;
		}	
	}
	cout << "The Occurence of " << del << " is " << count; cout << endl;
	int* newarray = new int[size - count];
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (darray[i] != del)
		{
			newarray[j++] = darray[i];
		}
	}
	delete[] darray;
	darray = newarray;
	size = size - count;
	newarray = nullptr;
	cout << "The Values are: ";
	for (int i = 0; i < size; i++)
	{
		cout << darray[i] << " ";
	}
	cout << endl;
}