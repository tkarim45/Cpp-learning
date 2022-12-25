/*#include<iostream>
using namespace std;
int* InputArray(int& size);
void OutputArray(int* myArray, const int& size);
int* Intersection(int* setA, int& size1, int* setB, int& size2, int& size3);
int main()
{
	int size1,size2;
	int* array1=InputArray(size1);
	for (int i = 0; i < size1; i++)
	{
		cin >> *(array1 + i);
	}
	int* array2 = InputArray(size2);
	for (int i = 0; i < size2; i++)
	{
		cin >> *(array2 + i);
	}
	int size3 = 0;
	int *temp=Intersection(array1, size1, array2, size2, size3);
	OutputArray(temp, size3);
	delete[] array1;
	array1 = nullptr;
	delete[] array2;
	array2 = nullptr;
	delete[] temp;
	temp = nullptr;
}
int* InputArray(int& size)
{
	cout << "Enter the Size of the Array: "; cin >> size;
	int* arr = new int[size];
	return arr;
}
void OutputArray(int* myArray, const int& size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *(myArray + i)<<" ";
	}
}
int* Intersection(int* setA, int& size1, int* setB, int& size2, int& size3)
{
	if (size1 > size2)
	{
		size3 = size2;
	}
	else
		size3 = size1;
	int* temp = new int[size3];
	int k = 0;
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			if (setA[i] == setB[j])
			{
				temp[j] = setA[i];
				k++;
			}
		}
		
	}
	size3 = k;
	int* temp1 = new int[k];
	for (int i = 0; i < k; i++)
	{
		temp1[i] = temp[i];
	}
	delete[] temp;
	temp = nullptr;
	return temp1;
}*/