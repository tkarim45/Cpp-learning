/*program to insert an number at a certain index*/
#include<iostream>
using namespace std;
int main()
{
	int size,num,index; //declaring variables
	cout<<"Enter the Size of Array "; cin>>size; //declaring the size of the array
	int a[size];
	cout<<"Enter the Numbers(size-1) in the array "<<endl;  //Entering the number in the array which is 1 	                                                         
	for(int i=0;i<size-1;i++)                               //times less than the size, to keep a free index
	{
		cin>>a[i];
	}
	cout<<"Enter the Number You want to place "; cin>>num; //Entering the number to be placed
	cout<<"Enter the Index at which ypu want to replace the Element "; cin>>index; //Entering the index at which the number is to be placed 
	cout<<"Original Elements in the array are ";
	for(int i=0;i<size-1;i++)  //Printing the original array
	{
		cout<<" "<<a[i];
	}
	cout<<endl;
	for(int i=size;i>index;i--)  //condition for placing the num at a certain index
	{
		a[i]=a[i-1];
	}
	a[index]=num;
	cout<<"After Replacing the Element the Array becomes "; //printing the array after the num is being inserted
	for(int i=0; i<size;i++)
	{
		cout<<" "<<a[i];
	}	
}
