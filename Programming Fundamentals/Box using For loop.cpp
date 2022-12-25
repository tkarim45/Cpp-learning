//Program for making a square box of "*" characters
#include<iostream>
using namespace std;
int main()
{
	int n;  //declaring variables 
	cout<<" Enter the Value = "; cin>>n;
	
    	//loop for making a square box of "*" characters
	for (int r=0; r<n; r++ )
	{
	    for (int c=0; c<n; c++)
	    {     
	       cout<< " * " ;
	    }
		cout<<endl;
	}
	system("pause");
	return 0;	
}
