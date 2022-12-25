/*Program to Find the Unique Elements in A and B set*/
#include<iostream>
using namespace std;
int setSubtraction (int a[], int size1, int b[], int size2, int c[]);	//function
int main()
{
		
int A[10] = { 1, 2, 4, 5, 8, 19, 17, 23, 45, 32 };       //hardcoding set A                     
int B[9] = { 1, 2, 5, 7, 8, 23, 32, 12, 31 };            //hardcoding set B                   
int C[19];    //declaring Maximum size of Array C

cout << "\n\n\nThe subtraction of B from A (A-B) is = ";  //Output of Unique Set in A
int size = 0;      //decalring Size as an varibale
size = setSubtraction(A, 10, B, 9, C);   //sending the hardcoded elements into the function and Storing its size in Variable Size
for(int c=0; c<size; c++)   //loop for displayng output of Set A
{
	cout<<" "<<C[c];
}

cout << "\n\n\nThe subtraction of A from B (B-A) is = ";  //Output of Unique Elements in B
size = setSubtraction(B, 9, A, 10, C);   //sending the hardcoded Elements into the function and storing its size in Varibale Size
for(int c=0; c<size; c++)   //loop for displayng output of Set B
{
	cout<<" "<<C[c];
}
cout<<endl;
system("pause");
}
 
int setSubtraction (int A[], int size_a, int B[], int size_b, int C[])  //Developing the function that is to e used in the main
{	   
    int c=0; //initializing the Array C starting with Index 0
	for(int a=0; a<size_a; a++) //Comparing Array A( Starting with Index 0) with Array B(starting with index 0)
	{
		int status=0;    //Applying check
		for(int b=0; b<size_b; b++) //condition to check if Value Set A is equal to Value of set B
		{
			if(A[a]==B[b])     //If value Of set A becomes equal to Value of Set B status=1
			{
				status=1;
			}
		}
		if(status==0)  //If the Value set A is not equals to Value of set B Unique Element is stored is different array and vice versa
	  	{
			C[c]=A[a]; //Storing Unique values of A and B in Array C
			c++;
		}		
	}	
	return c;	//returing the Value of Array C
}
