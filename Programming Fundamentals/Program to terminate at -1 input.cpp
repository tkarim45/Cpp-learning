#include<iostream>
using namespace std;
int main()
{
	int j=0;
	int a[100];
	for(j=0;j<100;j++)
	{
		cin>>a[j];
		if(a[j]==-1)
		break;
	}
	for(int i=0;i<j;i++)
	{
		cout<<" "<<a[i];
	}
}
