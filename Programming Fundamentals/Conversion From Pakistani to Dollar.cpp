#include<iostream>
using namespace std;
int main ()
{	
	float a,c;
	int b,d;
	cout<<" Please enter enter the number you want to convert in dollar = "; cin>>a;
	a=a/165;
	cout<<" In dollar ="<< a <<endl;
	b=a;
	c=a-b;
	c=c*100;
	d=c;
	cout<< b << " Dollar" << " and " << d << " cents" <<endl;		
	system("pause");
	return 0;	
}
