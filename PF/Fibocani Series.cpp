#include<iostream>
using namespace std;
int main ()
{	
	int n,n1=-1,n2=1,nextno,s=0,sum=0;
	cout<< " Enter N Number of Fibonaci Sequnce "<< endl;  cin>> n;
	while(s!=n)
	{	
		nextno=n1+n2;
		n1=n2;
		n2=nextno;
		s++;
		sum=sum+nextno;	
		cout<< " The Fibocani Sequence is  " << nextno <<endl;			
	}
	cout<< " The  Sum of Fibocani Sequence is  " << sum <<endl;
	system("pause")	;
	return 0;		
}
