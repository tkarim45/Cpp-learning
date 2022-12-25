#include<iostream>
using namespace std;
int** AllocateMemory(int& rows, int& cols);
void InputMatrix(int** matrix, const int rows, const int cols);
void DisplayMatrix(int** matrix, const int& rows, const int& cols);
void DeallocateMemory(int** matrix, const int& rows);
int* maxCol(int** matrix, const int rows, const int cols);
int** concat_table(int** table1, int** table2, int &row1, int &col1, int &row2, int &col2, bool axis);
int main()
{
	int rows, cols;
	cout << "Enter the Rows and Columns: ";  cin >> rows>>cols;
	int** matrix = AllocateMemory(rows, cols);
	InputMatrix(matrix, rows, cols);
	DisplayMatrix(matrix, rows, cols);
	int* maxColValues = maxCol(matrix, rows, cols);
	cout << endl;
	cout << "Max Columns Values are: ";
	for (int i = 0; i < rows; i++)
	{
		cout << maxColValues[i] << " ";
	}
	cout << endl;
	int rows1, cols1;
	cout << "Enter the Rows and Columns: ";  cin >> rows1>>cols1;
	int** table1 = AllocateMemory(rows1, cols1);
	InputMatrix(table1, rows1, cols1);
	DisplayMatrix(table1, rows1, cols1);

	int rows2, cols2;
	cout << "Enter the Rows and Columns ";  cin >> rows2>>cols2;
	int** table2 = AllocateMemory(rows2, cols2);
	InputMatrix(table2, rows2, cols2);
	DisplayMatrix(table2, rows2, cols2);

	bool axis;
	cout << "Enter 0 for x-axis and 1 for y-axis: ";  cin >> axis;
	int** result= concat_table(table1, table2, rows1, cols1, rows2, cols2, axis);
	DisplayMatrix(result, rows1, cols1);
}
int** AllocateMemory(int& rows, int& cols)
{
	int** p = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		p[i] = new int[cols];
	}
	return p;
}
void InputMatrix(int** matrix, const int rows, const int cols)
{
	cout << "Enter the Values: " << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cin >> matrix[i][j];
		}
	}
	cout << endl;
}
void DisplayMatrix(int** matrix, const int& rows, const int& cols)
{
	cout << "The Original Array is:\n" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << matrix[i][j] << "   ";
		}
		cout << endl;
	}
	cout << endl;
}
int* maxCol(int** matrix, const int rows, const int cols)
{
	int* arr = new int[rows];
	for (int i = 0; i < rows; i++)
	{
		int flag = matrix[0][i];
		for (int j = 0; j < cols; j++)
		{
			if (matrix[j][i] >= flag)
			{
				flag = matrix[j][i];
				arr[i] = flag;
			}
		}
	}
	return arr;
}
int** concat_table(int** table1, int** table2, int &row1, int &col1, int &row2, int &col2, bool axis)
{
	if (axis)
	{
		int row = row1 + row2;
		int** p = new int* [row];
		for (int i = 0; i < row; i++)
		{
			p[i] = new int[col1];
		}
		int k = -1;
		for (int i = 0; i < row; i++)
		{
			if (i < row / 2)
			{
				for (int j = 0; j < col1; j++)
				{
					p[i][j] = table1[i][j];
				}
			}
			if (i >= row / 2 && i < row)
			{
				k++;
				for (int j = 0; j < col1; j++)
				{
					p[i][j] = table2[k][j];
				}
			}
		}
		row1 = row;
		return p;
	}
	else
	{
		int col = col1 + col2;
		int** p = new int* [row1];
		for (int i = 0; i < row1; i++)
		{
			p[i] = new int[col];
		}
		for (int i = 0; i < row1; i++)
		{
			int k = 0;
			for (int j = 0; j < col; j++)
			{
				if (j < col / 2)
				{
					p[i][j] = table1[i][j];
				}
				if (j < col && j >= col / 2)
				{
					p[i][j] = table2[i][k];
					k++;
				}
			}
		}
		col1 = col;
		return p;
	}
}
void DeallocateMemory(int** matrix, const int& rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}