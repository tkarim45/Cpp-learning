#include<iostream>
using namespace std;
int main()
{
	int x, y;
	x = 3, y = 4;
	int* p;
	int* q;
	p = & x;
	q = &y;
	cout << x << '\t' << p << '\t' << *p << '\t' << &p << '\t' << &x << endl;
	//3       00EFFB24        3       00EFFB0C        00EFFB24 
	cout << y << '\t' << q << '\t' << *q << '\t' << &q << '\t' << &y << endl;
	//4       00EFFB18        4       00EFFB00        00EFFB18
}


