#include<iostream>
using namespace std;
void cin_Array(int arr[], int n);
void cout_Array(const int arr[], int n);
void Digit_Frequency(const int Numbers[], int N, int F[]);
int main()
{
	int size;
	x:
	cout << "Enter the Size of Array b/w 1 to 20: ";  cin >> size;
	if (size > 0 && size <=20)
	{
		int* array = new int[size];
		cout << "Enter the Elements of the Array " << endl;
		cin_Array(array, size);
		int* freq = new int[10]{};
		Digit_Frequency(array, size, freq);
		cout << "Original Array is: ";
		cout_Array(array, size);
		cout << "The Frequency of Each Digit is: ";
		cout_Array(freq, size);
		delete[] array;
		array = nullptr;
		delete[] freq;
		freq = nullptr;
	}
	else
		cout << "Enter the Size Again...." << endl;
		goto x;
}
void cin_Array(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}
void cout_Array(const int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void Digit_Frequency(const int Numbers[], int N, int F[])
{
	int flag = 0, number = 0;
	for (int i = 0; i < N; i++)
	{
		number = Numbers[i];
		while (number != 0)
		{
			flag = number % 10;
			F[flag]++;
			number = number / 10;
		}
	}
}