#include<iostream>
using namespace std;
void armstrong(int num)
{
	int digit,rem,sum=0;
	digit=num;
	while(digit!=0)
	{
		rem=digit%10;
		sum=(rem*rem*rem)+sum;
		digit=digit/10;
	}
	if(sum==num)
	{
		cout<<" "<<num;
	}	
}
int main()
{
	int l_limit,u_limit;
	cout<<"Enter the Range to Find any Armstrong Number: ";
	cin>>l_limit>>u_limit;
	for(int i=l_limit;i<=u_limit;i++)
	{
		armstrong(i);
	}
}
