#include<iostream>
using namespace std;
int main()
{
	int num,i=1,sum=0;
	while(i<=3)
	{
		cout<<"Enter the Angles of the triangle "<<i<<": "; cin>>num;
		sum=sum+num;
		i++;
	}
	if(sum==180)
	{
		cout<<"The traingle is Valid "<<endl;
	}
	else
	cout<<"The traingle is not Valid "<<endl;
}
