#include <iostream>
using namespace std;
void freq(int [],int);
int main()
{
	int size,val;
	cout<<"Enter the size of the array "; cin>>size;
	int a[size];
	cout<<"Enter the elements in the array "<<endl;
	for(int i=0;i<size;i++)
	{
		cin>>a[i];
	}	
	freq(a,size);	
}
void freq(int a[],int size)
{
	int val,status,check,k=0;
	int freq[size];
	cout<<"freq: ";
	for(int i=0;i<size;i++)
	{
	    val=a[i];
	    status=0;
	    check=1;
		for(int j=0;j<size;j++)
		{
		  if(val==a[j])
		  status++;
		}
		for(int j=0;j<k;j++)
		{
			if(freq[j]==val)
			check=0;
        }
		if(check==1)
		{
			cout<<" "<<status;
			freq[k]=val;
			k++;
		}	
	}
}
