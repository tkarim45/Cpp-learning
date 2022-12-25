#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	fstream file;
	file.open("Aaa.txt", ios::in | ios::out );
	if(!file.is_open())
	{
		cout<<"File not opened";
	}
	else
	cout<<"filed opened";
	file.close();
	return 0;
}
