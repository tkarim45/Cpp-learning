/*The Program finds the consective Numbers of the input value for which after multiplying gives the same Input value*/
#include<iostream>
using namespace std;
int main ()
{
	int n,a=0,b=1,c=2,n1; 
	cout<<" Enter an value for Finding Consective Number = "; cin>>n;
	for(int product=0; product<n; )
	{   
		product=a*b*c;   
		n1=product;	     
		if (product!=n)	 
		a++,b++,c++;     
	}
    if (n1==n)
	{      
    	cout<<" The Three Consective Numbers of " << n << " are = " << a << " " << b << " " << c <<endl;
	}
	else           
	cout<<" There is no Consective Numbers For the Input Value "  << endl;
	system("pause");
	return 0;
}

    
		

