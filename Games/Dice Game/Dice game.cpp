#include<iostream>
using namespace std;
int main()
{
	int dice1,dice2;
	a:
	cout<<"Enter the First Dice Number (1-6): "; cin>>dice1;
	if(dice1<=0 || dice1>6)
	{
		cout<<"Invalid Entry\n"<<endl;
		goto a;
	}
    b:
	cout<<"Enter the Second Dice Number (1-6): "; cin>>dice2;
	if(dice2<=0 || dice2>6)
	{
		cout<<"Invalid Entry\n"<<endl;
		goto b;
	}
	if((dice1+dice2)%2==0 || dice1+dice2==3)
	{
		cout<<"\nYour are a Winner"<<endl;
		return 0;
	}
	else if(dice1+dice2==11)
	{
		cout<<"\nYou Have Lost the Game"<<endl;
		return 0;
	}
	else if(dice1+dice2==5 || dice1+dice2==7 || dice1+dice2==9)
	{
		cout<<"Carry On: \n"<<endl;
		goto a;
	}	
}
