#include<iostream>
using namespace std;
int Multiple(int,int);
void PrintMultiple(int, int);
int main()
{
	int v1,v2;
	cout<<"Enter Two Numbers = "; cin>>v1>>v2;
	PrintMultiple(v1, v2);
	return 0;
}
void PrintMultiple(int v1,int v2)
{
	switch(Multiple(v1, v2))
	{
		case 1:
		cout<<v1<<" is the multiple of "<<v2<<" i.e "<<v2<<" * "<<v1/v2<<endl; break;
		
		case 2:
		cout<<v2<<" is the multiple of "<<v1<<" i.e "<<v1<<" * "<<v2/v2<<endl; break;
		
		case 3:
		cout<<" NON "<<endl; break;
	}
}

int Multiple(int v1,int v2)
{
	if(v1%v2==0)
	return 1;
	
	else if(v2%v1==0)
	return 2;
	
	else 
	return 3;	
}
