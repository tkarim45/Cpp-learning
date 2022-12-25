#include "20L-1309.h"
#include<fstream>
#include<cmath>


//*********************************** constructors ***********************************
matrix::matrix(): Rows(0),Columns(0)
{
	Matrix = new int* [Rows];
	for (int i = 0; i < Rows; i++)
	{
		Matrix[i] = new int[Columns];
	}
}
matrix::matrix(int x, int y): Rows(x),Columns(y)
{
	Matrix = new int* [Rows];
	for (int i = 0; i < Rows; i++)
	{
		Matrix[i] = new int[Columns];
	}
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Columns; j++)
		{
			Matrix[i][j] = 0;
		}
		cout << endl;
	}
}
matrix::matrix(int x, int y, int z) : Rows(x), Columns(y)
{
	Matrix = new int* [Rows];
	for (int i = 0; i < Rows; i++)
	{
		Matrix[i] = new int[Columns];
	}
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Columns; j++)
		{
			Matrix[i][j] = z;
		}
	}
}
matrix::matrix(const matrix& Array) 
{
	Rows =Array.Rows;
	Columns= Array.Columns;
	Matrix = new int* [Rows];
	for (int i = 0; i < Rows; i++)
	{
		Matrix[i] = new int[Columns];
	}
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Columns; j++)
		{
			Matrix[i][j] = Array.Matrix[i][j];
		}
	}
}


//*********************************** reading and writing to file (insertion and extraction operator) ***********************************
ostream& operator<<(ostream& output, const matrix& Array)
{
	output << Array.Rows << " " << Array.Columns << endl;
	for (int i = 0; i < Array.Rows; i++)
	{
		for (int j = 0; j < Array.Columns; j++)
		{
			output << Array.Matrix[i][j] << " ";
		}
		output << endl;
	}
	output << endl;
	return output;
}
istream& operator>>(istream& input, matrix& Array)
{	
	char comma;
	int x;
	input >> Array.Rows >> comma >> Array.Columns;
	Array.Matrix = new int* [Array.Rows];
	for (int i = 0; i < Array.Rows; i++)
	{
		Array.Matrix[i] = new int[Array.Columns];
	}
	for (int i = 0; i < Array.Rows; i++)
	{
		int j;
		for (j = 0; j < Array.Columns - 1; j++)
		{
			input >> x;
			Array.Matrix[i][j] = x;
			input >> comma;
		}
		input >> x;
		Array.Matrix[i][j] = x;
	}
	return input;
}


//*********************************** getters ***********************************
int matrix::getrows()
{
	return Rows;
}
int matrix::getcols()
{
	return Columns;
}


//*********************************** static functions ***********************************
matrix matrix::ones(int x, int y)
{
	matrix temp;
	temp.Rows = x;
	temp.Columns = y;
	temp.Matrix = new int*[x];
	for (int i = 0; i < x; i++)
	{
		temp.Matrix[i] = new int[y];
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			temp.Matrix[i][j] = 1;
		}
	}
	return temp;
}
matrix matrix::identity(int x)
{
	matrix temp;
	temp.Rows = x;
	temp.Columns = x;
	temp.Matrix = new int* [x];
	for (int i = 0; i < x; i++)
	{
		temp.Matrix[i] = new int[x];
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (i == j)
			{
				temp.Matrix[i][j] = 1;
			}
			else
				temp.Matrix[i][j] = 0;	
		}
	}
	return temp;
}


//*********************************** Arithmetic operators ***********************************
matrix matrix::operator++(int u)
{
	matrix temp;
	temp.Rows=Rows;
	temp.Columns=Columns;
	temp.Matrix = new int* [Rows];
	for (int i = 0; i < Rows; i++)
	{
		temp.Matrix[i] = new int[Columns];
	}
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Columns; j++)
		{
			temp.Matrix[i][j]=Matrix[i][j];
		}
	}
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Columns; j++)
		{
			Matrix[i][j] += 1;
		}
	}
	return temp;
}
matrix matrix::operator++()
{
	matrix temp;
	temp.Rows = Rows;
	temp.Columns = Columns;
	temp.Matrix = new int* [Rows];
	for (int i = 0; i < Rows; i++)
	{
		temp.Matrix[i] = new int[Columns];
	}
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Columns; j++)
		{
			temp.Matrix[i][j] = Matrix[i][j] + 1;
		}
	}
	return temp;
}
matrix matrix::operator+(const matrix& Array)const
{
	matrix temp;
	if (this->Rows == Array.Rows && this->Columns == Array.Columns)
	{
		temp.Rows = Array.Rows;
		temp.Columns = Array.Columns;
		temp.Matrix = new int* [Array.Rows];
		for (int i = 0; i < Array.Rows; i++)
		{
			temp.Matrix[i] = new int[Array.Columns];
		}
		for (int i = 0; i < Array.Rows; i++)
		{
			for (int j = 0; j < Array.Columns; j++)
			{
				temp.Matrix[i][j] = this->Matrix[i][j] + Array.Matrix[i][j];
			}
		}
		return temp;
	}
	else
		cout << "Dimension of both Matrices are not Compatible " << endl;
		return temp;
	
}
matrix matrix::operator+(const int sum)const
{
	
	matrix temp;
	temp.Rows = Rows;
	temp.Columns = Columns;
	temp.Matrix = new int* [Rows];
	for (int i = 0; i < Rows; i++)
	{
		temp.Matrix[i] = new int[Columns];
	}
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Columns; j++)
		{
			temp.Matrix[i][j] = Matrix[i][j] + sum;
		}
	}
	return temp;
}
matrix operator+(const int sum, const matrix& Array)
{
	matrix temp;
	temp.Rows = Array.Rows;
	temp.Columns = Array.Columns;
	temp.Matrix = new int* [Array.Rows];
	for (int i = 0; i < Array.Rows; i++)
	{
		temp.Matrix[i] = new int[Array.Columns];
	}
	for (int i = 0; i < Array.Rows; i++)
	{
		for (int j = 0; j < Array.Columns; j++)
		{
			temp.Matrix[i][j] = Array.Matrix[i][j] + sum;
		}
	}
	return temp;
}
matrix matrix::operator-(const matrix& Array)const
{
	matrix temp;
	if (this->Rows == Array.Rows && this->Columns == Array.Columns)
	{
		temp.Rows = Array.Rows;
		temp.Columns = Array.Columns;
		temp.Matrix = new int* [Array.Rows];
		for (int i = 0; i < Array.Rows; i++)
		{
			temp.Matrix[i] = new int[Array.Columns];
		}
		for (int i = 0; i < Array.Rows; i++)
		{
			for (int j = 0; j < Array.Columns; j++)
			{
				temp.Matrix[i][j] = this->Matrix[i][j] - Array.Matrix[i][j];
			}
		}
		return temp;
	}
	else
		cout << "Dimension of both Matrices are not Compatible - " << endl;
		return temp;
}
matrix matrix::operator-()const
{
	matrix temp;
	temp.Rows = Rows;
	temp.Columns = Columns;
	temp.Matrix = new int* [Rows];
	for (int i = 0; i < Rows; i++)
	{
		temp.Matrix[i] = new int[Columns];
	}
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Columns; j++)
		{
			temp.Matrix[i][j] = Matrix[i][j] * -1;
		}
	}
	return temp;
}
matrix operator ^ (int base, const matrix& Array)
{
	matrix temp;
	temp.Rows = Array.Rows;
	temp.Columns = Array.Columns;
	temp.Matrix = new int* [Array.Rows];
	for (int i = 0; i < Array.Rows; i++)
	{
		temp.Matrix[i] = new int[Array.Columns];
	}
	for (int i = 0; i < Array.Rows; i++)
	{
		for (int j = 0; j < Array.Columns; j++)
		{
			int exponent = Array.Matrix[i][j];
			double result = pow(base, exponent);
			temp.Matrix[i][j] = result;
		}
	}
	return temp;
}
matrix matrix::operator ^ (int exponent)
{
	matrix temp;
	temp.Rows = Rows;
	temp.Columns = Columns;
	temp.Matrix = new int* [Rows];
	for (int i = 0; i < Rows; i++)
	{
		temp.Matrix[i] = new int[Columns];
	}
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Columns; j++)
		{
			int base = Matrix[i][j];
			double result = pow(base, exponent);
			temp.Matrix[i][j] = result;
		}
	}
	return temp;
}
matrix matrix::operator * (const matrix& Array)const
{
	matrix temp;
	if (this->Columns == Array.Rows)
	{
		temp.Rows = this->Rows;
		temp.Columns = Array.Columns;
		temp.Matrix = new int*[temp.Rows];
		for (int i = 0; i < temp.Rows; i++)
		{
			temp.Matrix[i] = new int[temp.Columns];
		}
		int sum = 0;
		for (int i = 0; i < this->Rows; i++)
			for (int j = 0; j < Array.Columns; j++)
			{
				sum = 0;
				for (int k = 0; k < this->Columns; k++)
				{
					sum += this->Matrix[i][k] * Array.Matrix[k][j];
				}
				temp.Matrix[i][j] = sum;
			}
		return temp;
	}
	else
		cout << "Dimension of both Matrices are not Compatible * " << endl;
		return temp;
} 
matrix operator * (int Num, const matrix& Array)
{
	matrix temp;
	temp.Rows = Array.Rows;
	temp.Columns = Array.Columns;
	temp.Matrix = new int* [Array.Rows];
	for (int i = 0; i < Array.Rows; i++)
	{
		temp.Matrix[i] = new int[Array.Columns];
	}
	for (int i = 0; i < Array.Rows; i++)
	{
		for (int j = 0; j < Array.Columns; j++)
		{
			temp.Matrix[i][j] = Num * Array.Matrix[i][j];
		}
	}
	return temp;
}
matrix matrix::operator +=(const matrix& Array)
{
	if (this->Rows == Array.Rows && this->Columns == Array.Columns)
	{
		for (int i = 0; i < Array.Rows; i++)
		{
			for (int j = 0; j < Array.Columns; j++)
			{
				this->Matrix[i][j] = this->Matrix[i][j] + Array.Matrix[i][j];
			}
		}
		return *this;
	}
	else
		cout << "Dimension of both Matrices are not Compatible " << endl << endl;
		matrix temp;
		return temp;
}


//*********************************** Relational Operators ***********************************
matrix matrix::operator > (const int Num) const
{
	matrix temp;
	temp.Rows = Rows;
	temp.Columns = Columns;
	temp.Matrix = new int* [Rows];
	for (int i = 0; i < Rows; i++)
	{
		temp.Matrix[i] = new int[Columns];
	}
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Columns; j++)
		{
			int count = Matrix[i][j];
			if (count > Num)
			{
				temp.Matrix[i][j] = 1;
			}
			else
				temp.Matrix[i][j] = 0;
		}
	}
	return temp;
}
matrix matrix::operator >= (const int Num) const
{
	matrix temp;
	temp.Rows = Rows;
	temp.Columns = Columns;
	temp.Matrix = new int* [Rows];
	for (int i = 0; i < Rows; i++)
	{
		temp.Matrix[i] = new int[Columns];
	}
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Columns; j++)
		{
			int count = Matrix[i][j];
			if (count >= Num)
			{
				temp.Matrix[i][j] = 1;
			}
			else
				temp.Matrix[i][j] = 0;
		}
	}
	return temp;
}
matrix matrix::operator < (const int Num) const
{
	matrix temp;
	temp.Rows = Rows;
	temp.Columns = Columns;
	temp.Matrix = new int* [Rows];
	for (int i = 0; i < Rows; i++)
	{
		temp.Matrix[i] = new int[Columns];
	}
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Columns; j++)
		{
			int count = Matrix[i][j];
			if (count < Num)
			{
				temp.Matrix[i][j] = 1;
			}
			else
				temp.Matrix[i][j] = 0;
		}
	}
	return temp;
}
matrix matrix::operator <= (const int Num) const
{
	matrix temp;
	temp.Rows = Rows;
	temp.Columns = Columns;
	temp.Matrix = new int* [Rows];
	for (int i = 0; i < Rows; i++)
	{
		temp.Matrix[i] = new int[Columns];
	}
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Columns; j++)
		{
			int count = Matrix[i][j];
			if (count <= Num)
			{
				temp.Matrix[i][j] = 1;
			}
			else
				temp.Matrix[i][j] = 0;
		}
	}
	return temp;
}
matrix matrix::operator == (const int Num) const
{
	matrix temp;
	temp.Rows = Rows;
	temp.Columns = Columns;
	temp.Matrix = new int* [Rows];
	for (int i = 0; i < Rows; i++)
	{
		temp.Matrix[i] = new int[Columns];
	}
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Columns; j++)
		{
			int count = Matrix[i][j];
			if (count == Num)
			{
				temp.Matrix[i][j] = 1;
			}
			else
				temp.Matrix[i][j] = 0;
		}
	}
	return temp;
}
bool matrix::operator == (const matrix& Array) const
{
	if (this->Rows == Array.Rows && this->Columns == Array.Columns)
	{
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Columns; j++)
			{
				if (this->Matrix[i][j] != Array.Matrix[i][j])
				{
					return false;
					break;
				}
				else
					return true;
			}
		}
	}
	else
		return false;
	
}
bool matrix::operator!=(const matrix& Array)const
{
	int flag = 0;
	if (this->Rows == Array.Rows && this->Columns == Array.Columns)
	{
		for (int i = 0; i < Array.Rows; i++)
		{
			for (int j = 0; j < Array.Columns; j++)
			{
				if (this->Matrix[i][j] == Array.Matrix[i][j])
				{
					flag = 1;
					break;
				}
				else
				{
					flag = 0;
				}
			}
		}
		if (flag == 1)
			return 0;
		else
			return 1;
	}
	else
	{
		return 1;
	}
}


//*********************************** Function call operator ***********************************
int& matrix::operator () (const int N1, const int N2) const
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Columns; j++)
		{
			if (i == N1 && j == N2)
			{
				return Matrix[i][j];
				
			}
		}
	}
}
matrix matrix::operator () (const int N1, const int N2, const int N3, const int N4)
{
	matrix temp;
	if ((N1 >= 0 && N1 < Rows) && (N2 >= 0 && N1 < Rows) && (N3 >= 0 && N3 < Columns) && (N4 >= 0 && N4 < Columns))
	{
		int x = (N2 - N1)+1;
		int y = (N4 - N3)+1;
		temp.Rows = x;
		temp.Columns = y;
		temp.Matrix = new int* [temp.Rows];
		for (int i = 0; i < temp.Rows; i++)
		{
			temp.Matrix[i] = new int[temp.Columns];
		}
		for (int i = N1,x=0; i <= N2; i++,x++)
		{
			for (int j = N3,y=0; j <= N4; j++,y++)
			{
				temp.Matrix[x][y] = Matrix[i][j];
			}
		}
		return temp;
	}
	else
	{
		cout << "Dimension of both Matrices are not Compatible " << endl;
		return temp;
	}
	
}


//************************ MORE TESTS ***************************************************************
matrix matrix::operator =(const matrix& Array)
{
	matrix temp;
	temp.Rows = Array.Rows;
	temp.Columns = Array.Columns;
	temp.Matrix = new int*[temp.Rows];
	for (int i = 0; i < temp.Rows; i++)
	{
		temp.Matrix[i] = new int[temp.Columns];
	}
	for (int i = 0; i < temp.Rows; i++)
	{
		for (int j = 0; j < temp.Columns; j++)
		{
			temp.Matrix[i][j] = Array.Matrix[i][j];
		}
	}
	return temp;
}
matrix matrix::transpose()
{
	matrix temp;
	temp.Rows = Columns;
	temp.Columns = Rows;
	temp.Matrix = new int* [temp.Rows];
	for (int i = 0; i < temp.Rows; i++)
	{
		temp.Matrix[i] = new int[temp.Columns];
	}
	for (int i = 0; i < temp.Rows; i++)
	{
		for (int j = 0; j < temp.Columns; j++)
		{
			temp.Matrix[i][j] = Matrix[j][i];
		}		
	}
	return temp;
}

//************************ DESTRUCTOR ***************************************************************
matrix::~matrix()
{
	if (Matrix != nullptr)
	{
		for (int i = 0; i < Rows; i++)
		{
			delete[] Matrix[i];
		}
		delete[] Matrix;
		Matrix = nullptr;
	}
}