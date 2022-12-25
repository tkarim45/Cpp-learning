#include<iostream>
using namespace std;
int main()
{
	int number,count=1,large=0,small=0;
	cout<<"How Many Number you want to enter "<<endl;
	cin>> count;
	while(count>=1)
	{
		cin>>number;
		if(number>large)
		{		
			large=number;
		}
		else
		{
			small=number;	
		}
		count--;
	}
	cout<<"Large Number is "<<large<<endl<<endl;
	cout<<"Smallest Number "<<small<<endl;
	system("pause");
}	
		
	
	
	
	
	
	

