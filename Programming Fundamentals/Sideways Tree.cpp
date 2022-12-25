/*Program to Print a Tree sideways*/
#include<iostream>
using namespace std;
int main(){
	
	int n; //declaring variables
	cout<<" Enter the Value = "; cin>>n;
	for (int i=0; n!=i; i++ )
	{  //rows (increment)	
    	for (int j=0; j<=i; j++)
		{    //columns (increment)
        	cout<<" * ";
     	}
	    cout<<endl;
	}	
	for (int i=1; n!=i; i++)
	{  //rows (decrement)		
    	for(int j=n; j>i; j--)
		{	//columns (decrement)
	        cout<<" * ";
    	}
    	cout<<endl;
    }	
	system("pause");
	return 0;	
}
