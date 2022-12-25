#include<iostream>
#include<iostream>
using namespace std;
char* globalptr = new char[10];
int global_int = 10;
int main()
{
	cout <<_msize(globalptr) << endl;
	char* y = new char('B');
	int* x = new int[2];
	double* z = new double[2];
	int w = 20;
	char u = 'S';
	cout << _msize(x) << endl;
	cout << _msize(y) << endl;
	cout << _msize(z) << endl;
}