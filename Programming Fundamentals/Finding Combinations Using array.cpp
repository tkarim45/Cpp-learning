/*Program to Find The Sum of the Combination of the Entered Value using Arrays*/
#include<iostream>
using namespace std;
int main()
{
	int Value,sum;   //declaration of variables 
    const int n=10;  //Initailizing the size of the array
	int A[n]={28,45,-37,66,12,-15,35,52,71,-4};  //Array containing 10 integar Values
	cout<<"Enter the Number for Which You want to Find the combination = "; cin>>Value;
	for(int a=0; a<n; a++) //Condition to find the Sum of Combination of the entered Value
	{
		for(int b=a+1; b<n; b++)
		{
			for(int c=b+1; c<n; c++)
			{				
				if (A[a]+A[b]+A[c]== Value) //condition for the output of the Sum of the Cominations of the Entered Value
				{
					sum=A[a]+A[b]+A[c];         //storing the Value of sum in another variable
					cout<<A[a]<<"  "<<A[b]<<"  "<<A[c]<<endl;   //Out of the Combinations
		        } 
			}
		}	
	}
	if(Value!=sum)  //condition for Error, if the Sum is not equal to the entered Value the program will show error
	cout<<"The Entered Number has NO Combination "<<endl;
    system("pause");
	return 0;	
}
