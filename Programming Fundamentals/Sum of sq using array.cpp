#include<iostream>
using namespace std;
int main()
{
	int a[10];
	int sumofsq=0;
	cout<<"Enter the elements in an array"<<endl;
	for(int i=0; i<10; i++)
	{
		cin>>a[i];
	}
	for(int i=0; i<10; i++)
	{
		sumofsq=sumofsq+a[i]*a[i];
	}
	cout<<"The sum of the Sq number is "<<sumofsq<<endl;
}
