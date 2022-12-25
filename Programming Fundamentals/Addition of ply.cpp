#include<iostream>
using namespace std;
void addpoly(float poly1[50],float poly2[50],float num3)
{
	int poly3[50];
	for(int i=0;i<=num3;i++)
	{
		poly3[i]=poly1[i]+poly2[i];
	}
	cout<<"After Addition the Two Polynomials are: ";
	for(int i=num3;i>0;i--)
	{
	    cout<<poly3[i]<<"x^"<<i<<" ";
	}
	for(int i=0;i<=0;i++)
	{
	   	cout<<poly3[i]<<endl;
	}	
}
void subpoly(float poly1[50],float poly2[50],float num3)
{
	int poly3[50];
	for(int i=0;i<=num3;i++)
	{
		poly3[i]=poly1[i]-poly2[i];
	}
	cout<<"After Subtraction the Two Polynomials are: ";
	for(int i=num3;i>0;i--)
	{
	    cout<<poly3[i]<<"x^"<<i<<" ";
	}
	for(int i=0;i<=0;i++)
	{
	   	cout<<poly3[i]<<endl;
	}		
}
void multipoly(float poly1[50],float poly2[50],float num3)
{
	int poly3[50];
	for(int i=0;i<=num3;i++)
	{
		for(int j=0;j<=num3;j++)
		{
			poly3[j]=poly1[i]*poly2[j];
		}	
	}
	cout<<"After Multiplication the Two Polynomials are: ";
	for(int i=num3;i>0;i--)
	{
		for(int j=num3;j>0;j--)
		{
		   cout<<poly3[i]<<"x^"<<i+j<<" ";	
		}
	}
	for(int i=0;i<=0;i++)
	{
	   	cout<<poly3[i]<<endl;
	}			
}
void divpoly(float poly1[50],float poly2[50],float num3)
{
	float poly3[50];
	for(int i=0;i<=num3;i++)
	{
		poly3[i]=poly1[i]/poly2[i];
	}
	cout<<"After Divition the Two Polynomials are: ";
	for(int i=num3;i>0;i--)
	{
	    cout<<poly3[i]<<"x^"<<i<<" ";
	}
	for(int i=0;i<=0;i++)
	{
	   	cout<<poly3[i]<<endl;
	}			
}
int main()
{
	float num1,num2,num3;
	float poly1[50],poly2[50];
	cout<<"Enter the Higest Power of the Polynomial 1: "; cin>>num1;
	cout<<"Enter the Constant of Polynomial 1: ";
	for(int i=0;i<=0;i++)
	{
	   	cin>>poly1[i];
	}	
	for(int i=1;i<=num1;i++)
	{	
		cout<<"Enter the Coefficient x^"<<i<<" : "; cin>>poly1[i];
	}
	cout<<"------------------------------------------------"<<endl	
	cout<<"Enter the Higest Power of the Polynomial 2: ";  cin>>num2; 
	cout<<"Enter the Constant of Polynomial 2: ";
	for(int i=0;i<=0;i++)
	{
	   	cin>>poly2[i];
	}		 
	for(int i=1;i<=num2;i++)
	{	
		cout<<"Enter the Coefficient x^"<<i<<" : "; cin>>poly2[i];
	}
	cout<<"------------------------------------------------"<<endl;
	cout<<"First Polynomial is: ";
	for(int i=num1;i>0;i--)
	{
	    cout<<poly1[i]<<"x^"<<i<<" ";
	}
	for(int i=0;i<=0;i++)
	{
	   	cout<<poly1[i]<<endl;
	}	
	
	
	
	cout<<"Second Polynomial is: ";
	for(int i=num2;i>0;i--)
	{
	    cout<<poly2[i]<<"x^"<<i<<" ";
	}
	for(int i=0;i<=0;i++)
	{
	   	cout<<poly2[i]<<endl;
	}	
	cout<<"------------------------------------------------"<<endl;
	
	if(num1>num2)
	{
		num3=num1;
	}
	else
	num3=num2;
		cout<<num3<<endl;
	
	
	
	addpoly(poly1,poly2,num3);
	subpoly(poly1,poly2,num3);
	multipoly(poly1,poly2,num3);
	divpoly(poly1,poly2,num3);
}
