#include<iostream>
using namespace std;
bool isgreater(int num1,int num2);
bool issmaller(int num1,int num2);
bool ismiddle(int candidat,int num2,int num3);
int main()
{
	int num1,num2,num3;
	cout<<"Enter three NUmbers = "; cin>>num1>>num2>>num3;
	if(ismiddle(num1,num2,num3))
	{
		cout<<num1;
	}
	else if(ismiddle(num2,num1,num3))
	{
		cout<<num2;
	}
	else if(ismiddle(num3,num1,num2))
	{
		cout<<num3;
	}
	else 
	cout<<" NON ";
}
bool isgreater(int num1,int num2)
{
	return num1>num2;
}
bool issmaller(int num1,int num2)
{
	return num1<num2;
}
bool ismiddle(int candidate,int num1,int num2)
{
	if((isgreater(candidate,num1)&& issmaller(candidate,num2))|| (isgreater(candidate,num2)&&issmaller(candidate,num1)))
	{
		return true;
	}
	return false;
}
