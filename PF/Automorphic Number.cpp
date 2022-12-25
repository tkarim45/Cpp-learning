#include<iostream>
using namespace std;
int main()
{
	int num,flag=0;
	cout<<"Enter a Number: "; cin>>num;
	int sq=num*num;
	int store=num;
	for(int i=1;i<num;i++)
	{
		if(num%10!=sq%10)
		{
			flag=1;
			break;
		}
		num/=10;
		sq/=10;
	}
	if(flag==1)
	{
		cout<<"Its Not Automorphic Number: "<<endl;
	}
	else
    cout<<"Its Automorphic Number: "<<endl;
}
