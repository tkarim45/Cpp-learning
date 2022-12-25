#include<iostream>
using namespace std;
void abundant(int num1, int num2)
{
	int sum1=0,sum2=0;
	for(int i=1;i<=num1/2;i++)
	{
		if(num1%i==0)
		{
			sum1+=i;
		}
	}
	for(int i=1;i<=num2/2;i++)
	{
		if(num2%i==0)
		{
			sum2+=i;
		}
	}
	if(num1==sum2 && num2==sum1)
	{
		cout<<"The Number is Amicable: "<<endl;
	}
	else
	cout<<"The Number are Not Amicable: "<<endl;
	
}
int main()
{
	int num1,num2;
	cout<<"Enter First Number: "; cin>>num1;
	cout<<"Enter Second Number: "; cin>>num2;
	abundant(num1,num2);
}
