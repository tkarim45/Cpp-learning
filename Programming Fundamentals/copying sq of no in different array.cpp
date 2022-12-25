#include<iostream>
using namespace std;
void fff(int a[],int b[],int size)
{
	cout<<"Enter the Elements of the array: "; 
	for(int i=0;i<size;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<size;i++)
	{
		b[i]=a[i];
	}
	for(int i=0;i<size;i++)
	{
		b[i]=b[i]*b[i];
	}
	for(int i=0;i<size;i++)
	{
		cout<<b[i]<<" ";
	}
}
int main()
{
	int size;
	cout<<"Enter the size of the array: "; cin>>size;
	int a[size],b[size];
	fff(a,b,size);

}
