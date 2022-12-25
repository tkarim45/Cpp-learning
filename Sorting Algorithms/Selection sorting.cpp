#include<iostream>
using namespace std;
int findindexmin(int[],int,int);
void selectionsort(int[],int);
int main()
{
	int n;
	cout<<"Enter the Size of the Array "; cin>>n;
	int a[n];
	cout<<"Entert the Elements in the Array ="<<endl;
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}	
	selectionsort(a,n);
	cout<<"Array after sorting is =";
	for(int i=0; i<n; i++)
	{
		cout<<" "<<a[i];
	}
}
void selectionsort(int arr[], int n)
{
	int posmin,count,tmp;	
	for(count=0; count<n; count++)
	{
		posmin=findindexmin(arr, count, n);
		tmp=arr[posmin];
		arr[posmin]=arr[count];
		arr[count]=tmp;
	}	
}
int findindexmin(int arr[],int start, int n)
{
	int posmin=start;
	int index;	
	for(index=start; index<n; index++)
	{
	    if(arr[index]<arr[posmin])
	    {
	       posmin=index;
	    }
    }
	return posmin;
}


