#include<iostream>
using namespace std;
int main()
{
	int a[10], * p;
	p = a;
	cout << "Enter Elements in Array :" << endl;
	for (int i = 1; i < 10; i++)
	{
		cin >> *(p + i);
	}
	for (int i = 1; i < 10; i++)
	{
		p[i] = *(p + i) + 3;
	}
	cout << endl;
	for (int i = 1; i < 10; i++)
	{
		cout << *(p + i) << " ";
	}
	system("pause");
}