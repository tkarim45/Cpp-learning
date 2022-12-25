#include<iostream>
using namespace std;
int main (){
	
	int n,n1=-1,n2=1,nextno,s=0,sum=0;

	cout<< " Enter N Number of Fibonaci Sequnce ";	cin>>n;
	
	if (n>0 && n<=4000000){

	while(s!=n){		
	nextno=n1+n2;
	n1=n2;
	n2=nextno;
	sum=sum+nextno;
    cout<< " The Fibocani series is " << nextno <<endl;
	s++;
	}
	cout<< " The sum of fibocani sequence is " << sum <<endl;
}
	else 
	
	cout<<" Invalid Entry "<<endl;
	return 0;
	
	
	
system("pause")	;
return 0;	
	
}
