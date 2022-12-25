#include<iostream>
using namespace std;
char* get_first_name();
char* get_sec_name();
char* get_address();
int main()
{
	int num;
	cout << "Enter Number of Students: "; cin >> num;
	char*** p = new char** [num];
	for (int i = 0; i < num; i++)
	{
		p[i] = new char* [3];
	}
	cin.ignore();
	for (int i = 0; i < num; i++)
	{
		cout << "Enter Student " << i+1 << " Information: " << endl;
		for (int j = 0; j < 3; j++)
		{
			p[i][j] = get_first_name();
			j++;
			p[i][j] = get_sec_name();
			j++;
			p[i][j] = get_address();
			j++;
			break;
		}
		cout << endl;
	}
	cout << endl;
	cout << "You Have Entered the Following Information: " << endl;
	cout << endl;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "First Name: " << p[i][j] << endl;
			j++;
			cout << "Second Name: " << p[i][j] << endl;
			j++;
			cout << "Address Name: " << p[i][j] << endl;
			break;
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < 3; i++)
		{
			delete[] p[i][j];
		}
	}
	for (int i = 0; i < num; i++)
	{
		delete[] p[i];
	}
	delete[] p;
	p = nullptr;
}
char* get_first_name()
{
	cout << "Enter First Name (not long than 15 Characters): ";
	int max_size = 16;
	char* temp = new char[max_size];
	int size = 0;
	cin.getline(temp, max_size);
	size = 1;
	for (int i = 0; temp[i] != '\0'; i++)
	{
		size++;
	}
	char* new_array = new char[size];
	for (int i = 0; i < size; i++)
	{
		new_array[i] = temp[i];
	}
	delete[] temp;
	temp = new_array;
	return new_array;
}
char* get_sec_name()
{
	cout << "Enter Second Name (not long than 50 Characters): ";
	int max_size = 16;
	char* temp = new char[max_size];
	cin.getline(temp, max_size);
	int size = 1;
	for (int i = 0; temp[i] != '\0'; i++)
	{
		size++;
	}
	char* new_array = new char[size];
	for (int i = 0; i < size; i++)
	{
		new_array[i] = temp[i];
	}
	delete[] temp;
	temp = new_array;
	return new_array;
}
char* get_address()
{
	cout << "Enter Address (not long than 50 Characters): ";
	int max_size = 51;
	char* temp = new char[max_size];
	cin.getline(temp, max_size);
	int size = 1;
	for (int i = 0; temp[i] != '\0'; i++)
	{
		size++;
	}
	char* new_array = new char[size];
	for (int i = 0; i < size; i++)
	{
		new_array[i] = temp[i];
	}
	delete[] temp;
	temp = new_array;
	return new_array;
}
