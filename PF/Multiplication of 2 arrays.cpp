#include<iostream>
using namespace std;
int main()
{
	int a[3]={2,3,2};
	int b[2]={2,3};
	int c[6];
	int k=0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<2;j++,k++)
		{
			c[k]=a[i]*b[j];
		}
	}
	for(int i=0;i<4;i++)
	{
		cout<<" "<<c[i];
	}
}
