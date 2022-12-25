#include<iostream>
using namespace std;
int main()
{	
	int product,a=0,b=1,c=2,n;
	cout<< " Enter an Value "; cin>>n;
	while(product<n)
	{	
		product=a*b*c;
		if (product!=n)
		a++,b++,c++;
	}
	if (product==n)
	cout<<" The Three Consective Numbers are: " << a << " " << b << " " << c <<endl;		
	else
	cout<<" There is no Consective Numbers of Entered value"  << endl;
}
