#include<iostream>
#include<iomanip>
using namespace std;
int main() 
{
	int size;
	cout<<"Please enter the table size: ";
	cin>>size;
	int row = 1;
	while(row <= size)
	{
    	int column = 1;
    	while (column <= size) 
		{
       		int product = row*column;
       		cout << setw(4)<<product;
       		column++;
   		}
		cout << endl;
		row++;
	}
}
