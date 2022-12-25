#include<iostream>
#include<conio.h>
using namespace std;
int DetermineWinner(char player1_symbol,char player2_symbol);
void Display_Winner(int who_wins);
int main()
{
	int who_wins;
	char player1_symbol;
	char player2_symbol;
	int player1_count=0;
	int player2_count=0;
	char choice;
	do
	{
	   cout <<"\tR for rock, P for paper, or S for scissors : " <<endl;
	   cout <<"\tPlayer 1 vs Player 2 : ";
	   player1_symbol=getch();
	   cout <<"*";
	   player2_symbol=getch();
	   cout <<"*"<< endl;
       who_wins=DetermineWinner(player1_symbol,player2_symbol);
       Display_Winner(who_wins);
       cout<<" press (c)ontinue or (s)top \n";
       cin>>choice;
       
       if(who_wins==1)
       {
       	 player1_count++;
	   }
	   if(who_wins==2)
	   {
	   	player2_count++;
	   }
    }
    while(choice=='c');
    {
       if (player1_count>player2_count)
       cout<<"Player 1 wins ";
       
       else if(player1_count<player2_count)
       cout<<"Player 2 wins ";
       
       else if(player1_count==player2_count)
       cout<<" Draw ";
       
       else
	   return 0;
    }
}
int DetermineWinner(char player1_symbol,char player2_symbol)
{
	if ((player1_symbol=='s'&&player2_symbol=='p')||(player1_symbol=='r'&&player2_symbol=='s')||(player1_symbol=='p'&&player2_symbol=='r'))
	return 1;
	
	else if ((player1_symbol=='p'&&player2_symbol=='s')||(player1_symbol=='s'&&player2_symbol=='r')||(player1_symbol=='r'&&player2_symbol=='p'))	
	return 2;
	
	else if ((player1_symbol=='r'&& player2_symbol=='r')||(player1_symbol=='p'&&player2_symbol=='p')||(player1_symbol=='s'&& player2_symbol=='s'))
	return 3;
	
	else
	return 4;
	
}
void Display_Winner(int who_wins)
{
    cout<<"\t\t";
    switch (who_wins)
    {
	  case 1:
	  cout << "player 1 wins" << endl; break;
	
	  case 2:
	  cout << "player 2 wins" << endl; break;
	
	  case 3:
	  cout << "game draws" << endl; break;
	
	  case 4:	
	  cout << "invalid character input" << endl; break;	
    }
}
