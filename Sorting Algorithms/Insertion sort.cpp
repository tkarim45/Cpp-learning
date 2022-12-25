#include<iostream>
using namespace std;
void insertionsort(int [],int);
int main()
{
	int n;
	cout<<"Enter the Size of the Array "; cin>>n;
	cout<<"Enter the Elements in an Array ="<<endl;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	insertionsort(a,n);
	cout<<"Array After sorting is";
	for(int i=0;i<n;i++)
	{
		cout<<" "<<a[i];
	}	
}
void insertionsort(int arr[],int n)
{
	int pos,count,val;
	for(count=1;count<n;count++)
	{
		val=arr[count];
		for(pos=count-1;pos>=0;pos--)
		if(arr[pos]>val)
		arr[pos+1]=arr[pos];
		else
		break;
		
		arr[pos+1]=val;
	}
	
}
