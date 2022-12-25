#include <iostream>
using namespace std;
void removeduplicate(char []);
int main()
{
	//int size;
//	cout<<"Enter the size of the array "; cin>>size;
	char a[100];
	cout<<"Enter the elements in the array "; cin.getline(a,100);
//	for(int i=0;i<size;i++)
//	{
//		cin>>a[i];
//	}
	removeduplicate(a);	
}
void removeduplicate(char a[])
{
	int size=sizeof(a);
	for(int i=0;i<size;i++)
	{
		for(int j=i+1;j<size;j++)
		{
			if(a[i]==a[j])
			{
				for(int k=j;k<size;k++)
				{
					a[k]=a[k+1];	
				}
				size--;
				j--;
			}
		}
	}
	cout<<"After: ";
	for(int i=0;i<size;i++)
	{
		cout<<a[i];
	}
}


