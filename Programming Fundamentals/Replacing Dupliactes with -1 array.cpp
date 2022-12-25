/*Program to Replace the Duplicate Values in An array and in the second part moving all the negative values to the end of the array*/
#include <iostream>
using namespace std;

int main(){
	
	int n,b,c=0; //Declaration of the variables	
	cout<<" Enter the size of the Array "; cin>>n;   //Input of the Size of the Array
	cout<<" Enter the Elements of the Array "<<endl; //Input the integar values to be stored in an array
    const int size=n;   //Size of the array
    int A[size];

    for (int a=0;a<n;a++){
    cin>>A[a];}   //Inputting the integar values in an array 

    for(int a=0;a<n;a++) //condition for finding the duplicate vales 
    {
        for(b=a+1; b<n;b++) //Comparing the first integar with the rest and so on 
		{
			if(A[a]==A[b])  //Condition for duplicate integars, if found any then replacing them with -1
				A[b]=-1;
		}
    }
    for(int a=0; a<n;a++)  //Showing the result in such a form that the duplicates are replaced by -1
    cout<<" "<<A[a]<<" ";
    cout<<endl;
	
	int temp[size];   //decalring an another array to store the positive Values first and negative after that
	for(int a=0; a<n ; a++)
	{
		if(A[a]>=0)   //Check for all the positive values and storing them in temp array 
		{
			temp[c]=A[a];
			c++;
		}			
	}
	for(int a=0; a<n ; a++)  //Check for all the negative values and storing them in temp array
	{
		if(A[a]<0)
		{
			temp[c]=A[a];
			c++;
		}
	}
	for(int a=0; a<n; a++)  //Showing the output in such a form that all the negative values are in the end of the Array
	{
		cout<<" "<<temp[a]<<" ";
	}	
	system("pause");
	return 0;
}
