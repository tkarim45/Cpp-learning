#include<iostream>
using namespace std;
int main()
{
	int size=0,num;
	int a[100];
	cout<<"Enter the Elements of the Array: ";
	for(int i=0;i<100;i++)
	{
		cin>>a[i];
		if(a[i]==-1)
		break;
		size++;
	}
	//displaying the index of the number from the start
	cout<<"Enter the Number to find its Index: "; cin>>num;
	for(int i=0;i<size;i++)
	{
		if(a[i]==num)
		{
			cout<<"The Index of "<<num<<" is: "<<i<<endl;
			break;
		}
	}
	//displaying the index of the number from the end
	cout<<"Enter the Number to find its Index: "; cin>>num;
	for(int i=size;i>0;i--)
	{
		if(a[i]==num)
		{
			cout<<"The Index of "<<num<<" is: "<<i<<endl;
			break;
		}
	}
}
