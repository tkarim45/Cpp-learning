#include<iostream>
using namespace std;
int main()
{
	int num,digit,rem,sum=0;
	cout<<"Enter Number: "; cin>>num;
	digit=num;
	while(digit!=0)
	{
		rem=digit%10;
		int fact=1;
		for(int i=rem;i>0;i--)
		{
			fact=fact*i;		
		}
		sum+=fact;
		digit/=10;	
	}
	if(sum==num)
	{
		cout<<"The Number is Strong: "<<endl;
	}
	else
	cout<<"The Number is not Strong:"<<endl;
}
