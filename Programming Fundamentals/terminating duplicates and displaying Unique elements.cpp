#include <iostream>
using namespace std;
int main()
{	
	int no[20],count;
	int s = 1,DArray[s];
	do{                           		
		cin>>no[count];
		count++;		
	}while(no[count-1] != -99);	
	int check;	
	for(int i = 0;i<count;i++){              
		check = 0;
		for(int j =0;j<s;j++){
			if(no[i] == DArray[j]){
				check++;			
			}		
		}
		 if (check == 0){
			DArray[s-1] = no[i];
			s++;		
		}
	}	
	for(int i = 0;i<s-2;i++)
	{              	
		cout<<DArray[i]<<" ";
	}
	cout<<endl;
	int SUS= 1,Us[SUS];
	for(int i = 0;i<count;i++){                
		check = 0;
		for(int j = 0;j<count;j++){		
	    	if(no[i]==no[j]){		
				check++;
			}
		}	
		if(check == 1){	
		Us[SUS]=no[i];
		SUS++;
	}
	}
		for(int i = 1;i<SUS-1;i++){                 	
		cout<<Us[i]<<" ";
	}
	cout<<endl;	
}
