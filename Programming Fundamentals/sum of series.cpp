/*Program to calculate the sum of the series*/
#include<iostream>
using namespace std;
int main (){
	
	int n,s=0,n1,sum=0;  // declaring of varibales 
	cout<<" Enter the Value for nth Term, the input value should be an positive integar = "; cin>>n;
	n1=n;  //storing the input value in another varibale 
	n=0;   //initializing input value
	while(s!=n1 && n1>0){   
    n++;	
    cout<<" n*n =" << n*n <<endl;  //calculating the series till the input value
    sum=sum+(n*n);                 //calculating the sum of the series
    s++;	
	}
	
	cout<< " The Sum of the above series is = " << sum <<endl;
	system("pause");
	return 0;	
}
