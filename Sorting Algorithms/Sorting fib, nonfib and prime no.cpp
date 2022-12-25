#include <iostream>
using namespace std;
bool isFibonacci (int x)
{          //this function tells if a number is fabnoicci or not	
	int last = 0;
	int next = 1;
	int term = 0;	
	while (term<x)
	{
		term = next + last;
		last = next;
		next = term;	
	}	
	if(term == x || x == 0 || x == 1 )
	{
		return 1;
	}
	else
	return 0;	
}
bool isPrime (int x)
{              //this function tells if a number is prime or not
	int count;	
	for(int i = 1;i<=x;i++)
	{	
		if(x%i == 0 )
		{
			count++;
		}
	}	
	if(count ==  2)
	{
		return 1;
	}
	else
	return 0;	
}
int main()
{
    int swap = 0;	                   //declaration of variables
	bool ansf = 0,ansp = 0;
	int add = 0;
	int x[13] = {2,5,4,17,34,11,10,8,18,24,23,89,1};        //array x declared
	cout<<"Array Before Sorting\n";
	for(int count = 0;count<13;count++)
	{                  //this loop outputs x	
		cout<<x[count]<<" ";	
    } 
	int address = 0,temp = 0;
	for(int i = 0;i<13;i++)
	{      //this nested loop moves all fibanoicii to the left
	    ansf = 0;
		for(int count = i;count<13;count++)
		{               
		    ansf = isFibonacci(x[count]);
		    if(ansf){	
	    	temp = x[count];
		    address = count;
		    break;	
	    }	
	}
	if (ansf)
	{
	    if(x[address] == x[i])
		{            //this part is done to remove unnecessay swaps 
		    add++;
    	}
	    else
		{
	       x[address] = x[i];                 //this code works when swapping is required and it counts it in swap
	       x[i] = temp;
	       add++;
	       swap++;
        }
    }
}
int temp2 = 0,address2 = 0;
for(int i = 12;i>=add;i--)
{          //this nested loop moves all prime to the right	
	ansp = 0;
	for(int j = i;j>=add;j--)
	{
	
	    ansp=isPrime(x[j]);
	    if(ansp)
		{  
		   temp = x[j];
		   address2 = j;
	    	break;
	    }	
	}
    if(ansp)
	{
	    if(x[address2] == x[i])
		{                 //this part is done to remove unnecessary swaps
	    }
	    else
		{
	       x[address2] = x[i];                      //this code works when swapping is required and it counts it in swap
	       x[i] = temp;
           swap++;
        }
    }	
}
cout<<endl;
cout<<"Array After Sorting:"<<endl;	
for(int count = 0;count<13;count++)
{                  //this loop outputs x
	cout<<x[count]<<" ";		
} 
cout<<"\nswap = "<<swap;                              //prints total swaps	
}


