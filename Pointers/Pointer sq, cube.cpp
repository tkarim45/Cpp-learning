#include<iostream>
using namespace std;
int main()
{
	float x;
	cout << "Enter the Number: "; cin >> x;
	float *a = &x;
	cout << (*a) * (*a) << endl;
	cout << (*a) * (*a) * (*a) << endl;
	cout << (*a) / 2 << endl;
}