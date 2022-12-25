#include<iostream>
using namespace std;
int main()
{
	int i,z;
	int A[5]={3,5,7,8,9};
	for(i=0;i<5;i++)
	{
		i=A[i];
	}
	cout<<"Please enter a positive integar "; cin>>z;
	int found=0;
	for(i=0;i<5;i++)
	{
		if(z==A[i])
		{
			found=1; 
		    break;
		}		
	}
	if(found==1)
	cout<<"The number is at index "<<i<<endl;

    else
    cout<<"The number is not found"<<endl;	
}
