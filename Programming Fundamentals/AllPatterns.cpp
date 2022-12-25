#include<iostream>
using namespace std;
void pattern1()
{
	cout<<"PATTERN 1: "<<endl;
	for(int i=0;i<=5;i++)
	{
		cout<<"\t\t";
		for(int j=0;j<=i;j++)
		{
			cout<<"*";
		}
		cout<<endl;
	}
}
void pattern2()
{
	cout<<"PATTERN 2: "<<endl;
	for(int i=0;i<=5;i++)
	{
		cout<<"\t\t";
		for(int j=i;j<=5;j++)
		{
			cout<<"*";
		}
		cout<<endl;
	}
}
void pattern3()
{
	cout<<"PATTERN 3: "<<endl;
	for(int i=0;i<=6;i++)
	{
		cout<<"\t\t";
		for(int j=i;j<=6;j++)
		{
			cout<<" ";
		}	
		for(int k=0;k<=i-1;k++)
		{
			cout<<"*";
		}
		cout<<"\n";
	}
}
void pattern4()
{
	cout<<"PATTERN 4: "<<endl;
	for(int i=0;i<=6;i++)
	{
		cout<<"\t\t";
		for(int j=0;j<=i;j++)
		{
			cout<<" ";
		}	
		for(int k=i;k<=5;k++)
		{
			cout<<"*";
		}
		cout<<"\n";
	}
}
void pattern5()
{
	cout<<"PATTERN 5: "<<endl;
	for(int i=0;i<=5;i++)
	{
		cout<<"\t\t";
		for(int j=0;j<=5-i;j++)
		{
			cout<<" ";
		}	
		for(int k=0;k<=2*i;k++)
		{
			cout<<"*";
		}
		cout<<"\n";
	}
}
void pattern6()
{
	cout<<"PATTERN 6: "<<endl;
	for(int i=0;i<=5;i++)
	{
		cout<<"\t\t";
		for(int j=0;j<=5-i;j++)
		{
			cout<<" ";
		}	
		for(int k=0;k<=2*i;k++)
		{
			cout<<"*";
		}
		cout<<"\n";
	}
	for(int i=4;i>=0;i--)
	{
		cout<<"\t\t";
		for(int j=0;j<=5-i;j++)
		{
			cout<<" ";
		}	
		for(int k=0;k<=2*i;k++)
		{
			cout<<"*";
		}
		cout<<"\n";
	}
}
void pattern7()
{
	cout<<"PATTERN 7: "<<endl;
	for(int i=0;i<=5;i++)
	{
		cout<<"\t\t";
		for(int j=0;j<=5;j++)
		{
			cout<<"*";
		}	
		cout<<"\n";
	}
}
void pattern8()
{
	cout<<"PATTERN 8: "<<endl;
	for (int i=0; i<=5; i++ )
	{  
	    cout<<"\t\t";	
    	for (int j=0; j<=i; j++)
		{   
        	cout<<"*";
     	}
	    cout<<endl;
	}	
	for (int i=1; i<=6; i++)
	{  
	    cout<<"\t\t";			
    	for(int j=6; j>i; j--)
		{	
	        cout<<"*";
    	}
    	cout<<endl;
    }	
}
void pattern9()
{
	int totalrows=5;
	int i,j,k;
	cout<<"PATTERN 9: "<<endl;
	cout<<"\t\t";
	for(i=1;i<=2*totalrows-1;i++)
	{
		cout<<"*";
	}
	cout<<endl;
	for(int i=1;i<=totalrows;i++)
	{
		cout<<"\t\t";		
		for( j=totalrows-i;j>=1;j--)
		{
			cout<<"*";
		}
		for( k=1;k<=2*i-1;k++)
		{
			cout<<" ";
		}
		for( j=totalrows-i;j>=1;j--)
		{
			cout<<"*";
		}
		cout<<endl;
	}
	for(int i=totalrows-1;i>=1;i--)
	{
		cout<<"\t\t";	
		for( j=1;j<=totalrows-i;j++)
		{
			cout<<"*";
		}	
		for( k=1;k<=2*i-1;k++)
		{
			cout<<" ";
		}
		for( j=1;j<=totalrows-i;j++)
		{
			cout<<"*";
		}
		cout<<endl;
	}
	cout<<"\t\t";
	for(i=1;i<=2*totalrows-1;i++)
	{
		cout<<"*";
	}
}
int main()
{
	pattern1();
	pattern2();
	pattern3();
	pattern4();
	pattern5();
	pattern6();
	pattern7();
	pattern8();
	pattern9();
}
