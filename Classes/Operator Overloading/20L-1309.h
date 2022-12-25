#include<iostream>
using namespace std;
class matrix
{
	int Rows;
	int Columns;
	int** Matrix;
public:

	//*********************************** constructors ***********************************
	matrix();
	matrix(int, int);
	matrix(int, int, int);
	matrix(const matrix& );


	//*********************************** reading and writing to file (insertion and extraction operator) ***********************************
	friend ostream& operator << (ostream& out, const matrix&);
	friend istream& operator >> (istream& in, matrix&);


	//*********************************** getters ***********************************
	int getrows();
	int getcols();


	//*********************************** static functions ***********************************
	static matrix ones(int , int);
	static matrix identity(int);


	//*********************************** Arithmetic operators ***********************************
	matrix operator ++ (int);
	matrix operator ++ ();
	matrix operator + (const matrix&)const;
	matrix operator + (const int)const;
	friend matrix operator + (const int , const matrix&);
	matrix operator - (const matrix&)const;
	matrix operator - ()const;
	friend matrix operator ^ (int, const matrix&);
	matrix operator ^ (int);
	matrix operator * (const matrix&)const;
	friend matrix operator * (int, const matrix&);
	matrix operator += (const matrix&);


	//*********************************** Relational Operators ***********************************
	matrix operator > (const int) const;
	matrix operator >= (const int) const;
	matrix operator < (const int) const;
	matrix operator <= (const int) const;
	matrix operator == (const int) const;
	bool operator == (const matrix&) const;
	bool operator!=(const matrix&)const;

	
	//*********************************** Function call operator ***********************************
	int &operator () (const int, const int) const;
	matrix operator () (const int, const int, const int, const int);


	//************************ MORE TESTS ***************************************************************
	matrix operator =(const matrix&);
	matrix transpose();


	//************************ DESTRUCTOR ***************************************************************
	~matrix();

};