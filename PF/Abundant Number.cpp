// Program to check whether the Entered Number is Abundant or Not 

// What is Abundant Number?

/* Ans: An abundant Number (also known as excessive number) is a number in the number theory which itself is smaller 
than the sum of all its proper divisors. For example,12 is an abundant Number : divisors 1,2,3,4,6 , sum =16 >12 */

#include<iostream>
using namespace std;
int main()
{
	int num,div,sum=0;
	cout<<"Enter a Number: "; cin>>num; // Taking Input
	for(int i=1;i<num;i++) // Adding Divisors of the Entered Number 
	{
		div=num%i;
		if(div==0)
		{
			sum+=i;
		}
	}
	if(sum>num) // Condition for checking Abundant Number
	{
		cout<<"The Number is Abundant: "<<endl;
	}
	else
	cout<<"The Number is Not Abundant: "<<endl;
}
