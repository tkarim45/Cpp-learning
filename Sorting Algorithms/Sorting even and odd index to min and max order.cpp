/*Program to sort the even index values, in increasing order and odd index values, in decreasing order*/
#include<iostream>
using namespace std;
void sorting(int a[], int size)   //function for sorting the indexes
{
	int temp;
	for(int i=0;i<size;i++)      
	{
		for(int j=i+2;j<size;j++)
		{
			if(i%2==0 && j%2==0)   // condition for comparing even indexes and sorting them
			{
			   if(a[i]>a[j])
			   {
			   	    temp=a[i];
			   	    a[i]=a[j];
			   	    a[j]=temp;
			   }	
			}
			else if(i%2!=0 && j%2!=0)  //condition for odd indexes and sorting them
			{
				if(a[i]<a[j])
				{
					temp=a[i];
					a[i]=a[j];
					a[j]=temp;	
				}
			}
		}
	}
}
int main()
{
	int j=0;
	int a[100];
	cout<<"Enter The Numbers in the Array and -1 to Exit "<<endl;   //Taking input from the user untill -1 is entered
	for(j=0;j<100;j++)
	{
		cin>>a[j];
		if(a[j]==-1)
		break;
	}
	
	cout << "Original Array: ";   //Printing the original array
    for (int i=0;i<j;i++)
    cout <<" "<<a[i];
    
    sorting(a, j);  //Calling the function
    
    cout<<endl;
    cout << "\nSorted Array is:  ";  //Printing the Sorted array
    for (int i=0;i<j;i++)
    cout <<" "<<a[i];
 
}
