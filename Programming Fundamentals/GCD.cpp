#include<iostream>
using namespace std;
int main()
{
	int num,div,rem;
	cout<<"Enter the number to Find the GCD of: "; cin>>num;
	cout<<"Enter the Divident to be Divided by the Number: "; cin>>div;
	while(num%div>0)
	{
		rem=num%div;
		num=div;
		div=rem;	
	}
	cout<<"The GCD of "<<num<<" is "<<div<<endl;
}
