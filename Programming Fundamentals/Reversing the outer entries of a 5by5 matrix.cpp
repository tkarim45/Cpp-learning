#include <iostream>
using namespace std;
int main()
{
	int A[5][5];
	cout<<"Input: ";
	for(int row = 0;row<5;row++)
	{          //input loop	
		for(int column = 0;column<5;column++)
		{	
			cin>>A[row][column];
		}	
	}	
	cout<<"Input: "<<endl;
	for(int row = 0;row<5;row++)
	{          //output loop	
		for(int column = 0;column<5;column++)
		{		
			cout<<A[row][column]<<" ";
		}
		
		cout<<endl;
	}	
	cout<<endl;
	int temp = 0, temp2,temp3;
	temp=A[0][0];
	temp2 = A[4][0];
	temp3 = A[4][4];
	for(int frow = 1;frow<5;frow++ )
	{     
		A[0][frow-1] = A[0][frow];
	}
	for(int frow = 5;frow>0;frow-- )
	{    
		A[frow+1][0] = A[frow][0];
	}
	A[1][0] = temp;
    for(int frow = 4;frow>0;frow-- )
    {       
		A[4][frow+1] = A[4][frow];
	}	
	A[4][1] = temp2;
    for(int i =1;i<5;i++)
    {
	  A[i-1][4] = A[i][4];
    }	
	A[3][4] = temp3;
    cout<<"Output: "<<endl;	
	for(int row = 0;row<5;row++)
	{      
		for(int column = 0;column<5;column++)
		{	
			cout<<A[row][column]<<" ";
		}		
	 cout<<endl;
	}	
}
