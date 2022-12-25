#include<iostream>
using namespace std;
int main()
{
	int x, y;
	cout << "Enter the First Num: "; cin >> x;
	cout << "Entr the Second Num: "; cin >> y;
	int* a = &x;
	int* b = &y;
	cout << *a + *b << endl;
}