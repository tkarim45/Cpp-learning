#include <iostream>
using namespace std;
int main()
{	
	int size,count=0;
	int a[100];	
	do
	{		
	    cout<<"enter no = ";
	    cin>>a[count];
	    count++;			
	}while(a[count-1] !=-99 && count<100);		
    if((count-1)%2 == 0)
	{
	  cout<<"Equilibrium index does not exist!";
	}
	else
	{
	    size = (count-1)/2;
	    int sum1 = 0,sum2= 0;
	    for(int i = 0;i<size;i++)
		{
	    	sum1 = sum1 + a[i];		
		}
		for(int i = count-2;i>size;i--)
		{
      	 	sum2 = sum2 + a[i];		
		}
		if(sum1 == sum2)
		{
    		cout<<size<<" is an equilibrium index";	
		}
		else
		cout<<"Equilibrium index does not exist"<<endl;
	}	
}
