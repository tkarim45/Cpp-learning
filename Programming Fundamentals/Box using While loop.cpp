// Program that prints a box n*n with "*" Character*/
#include<iostream>
using namespace std;
int main ()
{
	int n,row,column;  //decalring integars
	cout<<" Enter a Single Integar Value = "; cin>>n;
	if(n>=1) //condition for drawing a box
	{ // loop for repetition of nested while loop to form the box
		for(row=0; row<n; row++)
		{
			cout<<" "<<endl;
			column=0;      //initializing the row
			while(column<n)
			{  
				cout<<" * " ;
				column++;
			}     
		}
		cout<<endl;
	}
	else 	//The program will show error if the user enters an input less then ZERO 
	cout<<" Invalid input, No Ouput "<<endl;	
	system("pause");
	return 0;
}
