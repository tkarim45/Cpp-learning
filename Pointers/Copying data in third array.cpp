#include<iostream>
using namespace std;
void copy(int* a, int* b, int m, int n)
{
	int size = m + n;
	int* c = new int[size];
	int j = 0;
	for (int i = 0; i < m; i++)
	{
		if (a[i] % 2 == 0)
		{
			*(c+j) = *(a+i);
			j++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (b[i] % 2 == 0)
		{
			*(c+j) = *(b+i);
			j++;
		}
	}
	for (int i = n-1; i >= 0; i--)
	{
		if (b[i] % 2 != 0)
		{
			*(c+j) = *(b+i);
			j++;
		}
	}
	for (int i = m-1; i >= 0; i--)
	{
		if (a[i] % 2 != 0)
		{
			*(c+j) = *(a+i);
			j++;
		}
	}
	cout << "The Third Array is: ";
	for (int i = 0; i <size; i++)
	{
		cout << *(c+i) << " ";
	}
	cout << endl;
	delete[] c;
	c = nullptr;
}
int main()
{
	int m, n;
	cout << "Enter the Size of First Array: "; cin >> m;
	cout << "Enter the Size of Second Array: "; cin >> n;
	int* a = new int[m];
	int* b = new int[n];
	cout << "Enter the Elements of the First Array: " << endl;
	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
	}
	cout << endl;
	cout << "Enter the Elements of the Second Array: " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	cout << endl;
	cout << "First Array is: ";
	for (int i = 0; i < m; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "Second Array is: ";
	for (int i = 0; i < n; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;
	copy(a, b, m, n);
	delete[] a;
	a = nullptr;
	delete[] b;
	b = nullptr;
}