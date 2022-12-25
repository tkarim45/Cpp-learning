// Allocation of 3D Array and Data is Stored in 3D Arrays

#include <iostream>
using namespace std;
int main()
{
	// Declaration of 3D Array
	int test[2][3][2] = {{{1, 2}, {3, 4}, {5, 6}}, {{7, 8}, {9, 10}, {11, 12}}};

	// Loop to print Data and to Show how and where data is Stored (Index at which data is stored)
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				cout << "Test [" << i << "][" << j << "][" << k << "]=" << test[i][j][k] << endl;
			}
		}
	}
}

// Path: Programming Fundamentals/3D array.cpp

// Output
