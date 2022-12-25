#include <iostream>

using namespace std;


int main(){


// to take input
	
	int A[100],n;                         // array and it's counter declared
	cout<<"Enter No's Horizontally (Enter -99 to stop)";
	do{                                       //this loop takes input until input  = -99   // array size = n-1
		
		
		
		cin>>A[n];
		n++;
	
		
	}while(A[n-1] != -99);
	
	
	
	cout<<endl;                               //blank line
	



// to find Us
	
	int size = 1,check = 0;                     //this is the size of unique array and check declared
	int Us[size];                  				//unique array declared
		
	for(int count = 0;count<n-1;count++){       //this loop compares Input Array(A) with empty Array (Us), If It's Not In Us Then Added To Us
		check = 0;
		for(int count2 = 0;count2<size;count2++){
			
			if(A[count] == Us[count2]){
				check++;
			}
			
		}
		
		if (check == 0){
			Us[size-1] = A[count];
			size++;
		}
		
		
	}
	                                        
	
		
cout<<"Us: ";	                    
	for(int count = 0;count<size-1;count++){     //this loop outputs Us   //size of Us = size -1            
		cout<<Us[count]<<" ";
	}
	


//to find freq

int freq[size]; // freq array declared  // Size Of Freq = Size Of Us 

for(int count = 0; count<size-1;count++){     // this loop selects one element from Us and compares it with every element in Input Array, If found it increases count and after getting out of loop it stores that in freq
check = 0;	
	for(int count2 = 0;count2<n-1;count2++){
		
		if(Us[count] == A[count2]){
			check++;
		}
		
	}
	
	freq[count] = check;
	
	
}

cout<<endl;

cout<<"freq: ";
	for(int count = 0;count<size-1;count++){  //this loop prints freq
		cout<<freq[count]<<" ";
	}
	
	
//to find sorted us

	
	int maxf = 0,maxUs = 0;
	int address2 = 0;
	for(int i = 0;i<(size-1);i++){           //sorts the frequency in descending order and no according to frequency
		maxf = 0;
		maxUs = 0;			
		for(int j = i +1;j<(size-1);j++){
		if(freq[j]>freq[i]){           
			maxf = freq[j];
			address2 = j;
			maxUs = Us[j];
		freq[address2] = freq[i]; 
		freq[i] = maxf;
		
		Us[address2] = Us[i]; 
		Us[i] = maxUs;	
		}
		}	
	}
	
	cout<<endl;
	
	cout<<"Sorted Us: ";
	for(int i =0;i<(size-1);i++){          //this loop outputs sorted Us
		cout<<Us[i]<<" ";
	}
	
//to find New D Array	
	
	int count = 0;
	int mcount = 0;
for(int j = 0;j<size-1;j++){                        // this increases the f and us element

for(int i = mcount;i<(mcount +freq[j]);i++){        //this nested loop stores us in D until f
	A[i] = Us[j];
 count++;                                           // this remembers the place it is being stored
 
 
}
mcount = count;                                     
}
	

cout<<endl;                                       //blank line

cout<<"New D Array: ";	                          //outputs new D array
	for(int count = 0;count<n-1;count++){
		cout<<A[count]<<" ";
	}
	
	
}
