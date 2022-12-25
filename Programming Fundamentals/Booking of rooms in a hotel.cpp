#include <iostream>
using namespace std;
int main()
{	
	char hotel[8][6];
	for(int i = 0; i<8;i++)
	{	
		for(int j = 0;j<6;j++)
		{
			hotel[i][j] = '*';		
		}
	}	
	for(int i = 0; i<8;i++)
	{
		cout<<"Floor   "<<i+1<<"\t";	
		for(int j = 0;j<6;j++)
		{
			cout<<hotel[i][j]<<"\t"; 	
		}
		cout<<endl;	
	}		
	int classes, zones;
	bool available;
	do
	{
		cout<<"Enter 1 for firstclass, 2 for economy class , -1 to exit"<<endl;
		cin>>classes;
		if (classes == 2)
		{
			cout<<"Enter 1 for smoking, 2 for non-smoking";
			cin>>zones;	
		}	
		if (classes ==1)
		{                        
			for(int i = 0; i<2;i++)
			{
				available = 0;
				for(int j = 0;j<6;j++)
				{
					if(hotel[i][j] != 'X')
					{
						hotel[i][j] = 'X';
						available =1; 
						goto end1;	
					}			
				}	
			}
			end1 : if(available ==0)
			{
				cout<<"Seat notavailable;"<<endl;
			}	
		}
		if(classes == 2 && zones ==2 )
		{               	
			for(int i = 2; i<5;i++)
			{
				available = 0;
				for(int j = 0;j<6;j++)
				{
					if(hotel[i][j] != 'X')
					{
						hotel[i][j] = 'X';
						available = 1; 
						goto end2;	
					}
				}	
			}
			end2 : if(available ==0)
			{
				cout<<"Seat notavailable;"<<endl;
			}
		}
		if(classes == 2 && zones ==1 )
		{				
			for(int i = 5; i<8;i++)
			{
				for(int j = 0;j<6;j++)
				{
					if(hotel[i][j] != 'X')
					{
						hotel[i][j] = 'X'; 
						available =1;
						goto end3;	
					}
				}		
			}
			end3 : if(available ==0)
			{
				cout<<"Seat notavailable;"<<endl;
			}
		}
		for(int i = 0; i<8;i++)
		{                   
			cout<<"Floor "<<i +1<<"\t";	
			for(int j = 0;j<6;j++)
			{
				cout<<hotel[i][j]<<"\t"; 		
			}
			cout<<endl;	
		}		
	} while (classes != -1);
}
