/*Program to Sum the Even Number of Fibocani series till 4000000*/
#include<iostream>
using namespace std;
int main (){
	
	int n,n1=-1,n2=1,nextno,s=0,sum=0; //Declaring variables 

	cout<< " Enter N Number of Fibonaci Series  ";	cin>>n;
	
	while(s!=n){   //Loop for calculating the next number 
	nextno=n1+n2;	
    n1=n2;
	n2=nextno;
	s++;
   
   if (n2%2==0)   //Condition for the sum of even numbers of fibocani series 
   sum=sum+n2;  
}
   if(nextno<=4000000)  //Output will be shown if the fibocani series is less then 4000000
   cout<< " The Sum of  Even Number Fibocani series is "<<sum<<endl;
  
   else      //If the condition fails the program will show error message
   cout<<" error , the fibocan series is exceding more than 4000000 "<<endl;
     
    system("pause");
    return 0;		
}
