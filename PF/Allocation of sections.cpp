#include<iostream>
using namespace std;
AllocateSection(int rollnum, int marks)
{
	int n,digit,rev=0;
	n=marks;
	do
	{
		digit=marks%10;
		rev=(rev*10)+digit;
		marks=marks/10;	
	}while(marks!=0);
	if(n==rev)
	{
		cout<<"Roll N0. "<<rollnum<<" has been allocated section BS-A "<<endl;
	}
	else
	{
		if(n%2==0)
		{
			cout<<"Roll N0. "<<rollnum<<" has been allocated section BS-B "<<endl;
		}
		else
		cout<<"Roll N0. "<<rollnum<<" has been allocated section BS-C "<<endl;	
	}	
}
int main()
{
	int rollnum,marks;
	cout<<"Enter Roll Number: "; cin>>rollnum;
	cout<<"Enter Intermediate Marks: "; cin>>marks;
	AllocateSection(rollnum, marks);
}
