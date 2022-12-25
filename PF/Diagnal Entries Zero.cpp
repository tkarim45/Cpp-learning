/*Program to Print the Diagnal Entries ZERO*/
#include<iostream>
#include<iomanip>
using namespace std;
int main ()
{
	
	int s,p; //declaring variables 
	cout<<" Enter the Size of the Table = "; cin>>s;   //entering the size of th table
	for (int r=1; r<=s; r++)
	{   //rows 
		for (int c=1; c<=s; c++)
		{   //columns 
			if (r==c)
			{        // Condition for Inputing Zero as daignal Entries 
				cout<<setw(4);    //Equal spaces between rows and columns
				p=0;
			}
			else              //Showing a table with product 
			p = r * c;
			
			cout<<setw(4)<<p;	//Equal Spacing 
		}		
    	cout<<endl;	
	}	
	system("pause");
	return 0;
}
