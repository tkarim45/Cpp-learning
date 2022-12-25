#include<iostream>
using namespace std;
void bubblesort(int[],int);
int main()
{
	int n;
	cout<<"Enter the Size of the Array = "; cin>>n;
	cout<<"Enter the Elements of the Array = "<<endl;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	bubblesort(a,n);
	cout<<"Array after sorting is ";
	for(int i=0;i<n;i++)
	{
		cout<<" "<<a[i];
	}
}
void bubblesort(int arr[], int n)
{
	int i,tmp;
	int bound=n-1;
	int swapped=1;
	while(swapped>0)
	{
		swapped=0;
	    for(i=0;i<bound;i++)
	    if(arr[i]>arr[i+1])
	   {
		tmp=arr[i];
		arr[i]=arr[i+1];
		arr[i+1]=tmp;
		swapped=i;
	   }
	   bound=swapped;
    }
    cout<<"Freq:";
    for(int i=0;i<size;i++)
    {
    	cout<<" "<<freq[i];
	}
}
