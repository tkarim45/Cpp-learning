/*Program to sort the array in such a way that the first element is first maximum
and second element is first minimum and so on*/
#include<iostream>
using namespace std;
void sorting(int arr[], int size)  //function for sorting 
{
    int temp[size];   //Bubble sorting to sort the array
   	int i,tmp;
	int bound=size-1;
	int swapped=1;
	while(swapped>0)
	{
		swapped=0;
	    for(i=0;i<bound;i++)
	    if(arr[i]>arr[i+1])
	   {
		tmp=arr[i];
		arr[i]=arr[i+1];
		arr[i+1]=tmp;
		swapped=i;
	   }
	   bound=swapped;
    }
    
    int small=0, large=size-1;  //Sine the array is sorted from min to max it is easy to find min and max value
    int check=true;
    for (int i=0;i<size;i++)   //condition for printing first max value then first minimum and so on
    {
        if (check)
        temp[i]=arr[large--];
        
        else
        temp[i]=arr[small++];
 
        check=!check;
        cout<<check;
    }
    for(int i=0;i<size;i++) //All the values stored in temp are stored in array arr
    arr[i]=temp[i];
}
int main()
{
	int size=8;  //hardcoded input
    int a[size] ={17,11,12,13,14,15,16,18};
    cout << "Original Array:\n"; //Printing the original array
    for (int i=0;i<size;i++)
    cout <<" "<<a[i];
 
    sorting(a, size);
 
    cout << "\nSorted Array is:\n"; //Printing the sorted array
    for (int i=0;i<size;i++)
    cout <<" "<<a[i];
    
    return 0;
}
