#include<iostream>
using namespace std;
int main()
{
	int num,digit,rem,sum=0;
	cout<<"Enter a Number: "; cin>>num;
	digit=num;
	while(digit!=0)
	{
		rem=digit%10;
		sum=sum+rem;
		digit/=10;
	}
	if(num%sum==0)
	{
		cout<<"The Number is Harshad: "<<endl;
	}
	else
	cout<<"The Number is Not HArshad: "<<endl;

}
