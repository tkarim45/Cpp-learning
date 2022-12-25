/*Program to Print an Empty Square box*/
#include<iostream>
using namespace std;
int main(){
	
	int n; //declaring integar
	cout<<" Enter the Size of the box = "; cin>>n;	
	
	if(n>=1 && n<=20){   //condition for the size of the square box
		
	for(int r=0; r!=n; r++){  //rows		
	   for(int c=0; c!=n; c++){  //columns
           if (r==0 || r==n-1 || c==0 || c==n-1) //condition for empty space in the box
                 cout<<" * ";
    
           else
                cout<<"   ";  }	
	cout<<endl;
	                       }	
                    }          	
    else        //Condition for a Invalid Input Value
    cout<<" Invalid entry";  //Program will show no output 
    return 0;
		
	system("pause");
	return 0;
	
}
