#include<iostream>
using namespace std;
int main()
{
	int rows, cols;
	cout << "Enter the Number of Rows and Columns: "; cin >> rows >> cols;
	int** p = new int* [rows];   //declarig 2d dynamic array
	for (int i = 0; i < rows; i++) //declaring the columns of the dynamic array
	{
		p[i] = new int[cols];
	}
	cout << "Enter the Values: " << endl;
	for (int i = 0; i < rows; i++)   //Taking input of the dynamic array
	{
		for (int j = 0; j < cols; j++)
		{
			cin >> p[i][j];
		}
	}
	cout << endl;
	cout << "The Original Array is:\n " << endl;  //Output of the dynamic array 
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << p[i][j] << "   ";
		}
		cout << endl;
	}
	for (int i = 0; i < rows; i++)   //Deallocating the dynamic array
	{
		delete[] p[i];
	}
	delete[] p;
	p = nullptr;
}