#include<iostream>
using namespace std;
int main()
{
	int num,sum=0,div;
	cout<<"Enter a Number: "; cin>>num;
	for(int i=1;i<num;i++)
	{
		div=num%i;
		if(div==0)
		{
			sum+=i;
		}
	}
	if(sum==num)
	{
		cout<<"Its a Perfect Square: "<<endl;
	}
	else
    cout<<"Its Not a Perfect Square: "<<endl;
}
