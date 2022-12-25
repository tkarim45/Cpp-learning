#include<iostream>
using namespace std;
int main()
{
	int*** p = new int** [3];
	for (int i = 0; i < 3; i++)  //Allocating 3d Array
	{
		p[i] = new int* [3];
		for (int j = 0; j < 3; j++)
		{
			p[i][j] = new int[2];
		}
	}
	for (int i = 0; i < 3; i++)  //Inputing the values of the 3d Array
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				cin >> p[i][j][k];
			}
		}
	}
	for (int i = 0; i < 3; i++)  //Output of the 3d Array
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				cout << p[i][j][k] << "  ";
			}
		}
	//	cout << endl;
	}
	cout << endl;
	for (int i = 0; i < 3; i++)   //Deallocating the 3d Array;
	{
		for (int j = 0; j < 3; j++)
		{
			delete[] p[i][j];
		}
	}
	for (int i = 0; i < 3; i++)
	{
		delete[] p[i];
	}
	delete[] p;
	p = nullptr;
}