#include<iostream>
using namespace std;
class Matrix
{
	int** matrix;
	int rows;
	int size;
public:
	Matrix()
	{
		cout << "Default Constructor Invoked " << endl;
		matrix = nullptr;
	}
	Matrix(const Matrix& M)
	{
		rows = M.rows;
		size = M.size;
		matrix = new int* [rows];
		for (int i = 0; i < rows; i++)
			matrix[i] = new int[size];

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < size; j++)
				matrix[i][j] = M.matrix[i][j];
	}
	int** GetMatrix()
	{
		return matrix;
	}
	int GetSize()
	{
		return size;
	}
	int GetRows()
	{
		return rows;
	}
	void SetRows(int r)
	{
		rows = r;
	}
	void SetSize(int s)
	{
		size = s;
	}
	void SetMatrix(int** m, int r, int c)
	{
		rows = r;
		size = c;
		matrix = new int* [rows];
		for (int i = 0; i < rows; i++)
			matrix[i] = new int[size];

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < size; j++)
				matrix[i][j] = m[i][j];
	}
	void InputMatrix()
	{
		matrix = new int* [rows];
		for (int i = 0; i < rows; i++)
			matrix[i] = new int[size];

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cin >> matrix[i][j];
			}
		}
		cout << endl;
	}
	void OutputMatrix()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	int** AddMatrix(Matrix& matrix2)
	{
		int** arr = new int* [rows];
		for (int i = 0; i < rows; i++)
			arr[i] = new int[size];
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < size; j++)
			{
				arr[i][j] = this->matrix[i][j] + matrix2.matrix[i][j];
			}
		}
		return arr;
	}
	~Matrix()
	{
		cout << "Destructor Invoked " << endl;
		for (int i = 0; i < rows; i++)
		{
			delete matrix[i];
		}
		delete[] matrix;
		matrix = nullptr;
	}
};
int main()
{
	Matrix M1;
	int r, c;
	cout << "Enter number of rows: "; cin >> r;
	cout << "Enter number of columns:"; cin >> c;
	M1.SetRows(r);
	M1.SetSize(c);
	M1.InputMatrix();
	Matrix M2(M1);
	cout << "First matrix: " << endl << endl;
	M1.OutputMatrix();
	cout << "Second matrix: " << endl << endl;
	M2.OutputMatrix();
	cout << "Sum of matrices: " << endl << endl;
	int** sum = M1.AddMatrix(M2);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << sum[i][j] << " ";
		}
		cout << endl;
	}
}