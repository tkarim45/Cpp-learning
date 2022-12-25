#include <iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
int main()
{
	char data[100],*list_token[100][100];
	char delimeter;
	int size=1;
	char *token;	
	cout<<"Enter a Sentence with (,) between them"<<endl;
	cin.getline(data,100);         						
	for(int i = 0;i<100;i++){
		if(data[i] == ',')
		{
			size++;
		}
	}
	cout<<endl;
	list_token[0][0] = strtok(data,",");
	for(int row = 1;row<size;row++)
	{                   	
	    list_token[row][0] = strtok(NULL,",");		
	}	
	for(int row = 0;row<size;row++)
	{                   		
	   cout<<list_token[row][0]<<endl;	
	}		
}
