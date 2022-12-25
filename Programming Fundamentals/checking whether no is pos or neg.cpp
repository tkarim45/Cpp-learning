#include<iostream>
using namespace std;
int main()
{
	int num;
	cout<<"Enter a number: "; cin>>num;
	if(num>0)
	{
		if(num%2==0)
		{
			cout<<"The Number is Even "<<endl;
		}
		else
		cout<<"The Number is Odd "<<endl;
	}
	else if(num<0)
	{
		if((num*-1)%2==0)
		{
			cout<<"The Number is Even "<<endl;
		}
		else
		cout<<"The Nmber is Odd "<<endl;
	}
}
