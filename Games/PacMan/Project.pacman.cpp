/* PROJECT PACMAN */
#include<iostream>       //libraries
#include<conio.h>
#include<windows.h>
#include "map2.h"
using namespace std;
void gotoxy(int x , int y)     //function for gotoxy
{
	static HANDLE h = NULL;
	if(!h)
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x , y };
	SetConsoleCursorPosition(h,c);
}
bool game=true;  
int main()
{
	system("color 7");  //Instructions
	cout<<"INSTRUCTION \n\n1: Press up arrow to move up\n";
	cout<<"2: Press down arrow to move down \n3: Press left arrow to move left\n";
	cout<<"4: Press right arrow to move right \n5: Avoid the enemeys (E)\n";
	cout<<"6: Press ESC to leave during the game\n\n";
	cout<<"As you progress towards next level the difficulty level will exced by decreasing 1 life in next level\n\n";
	char ch;                                    //Condition for starting the game
	cout<<"Press S(tart) \nPress E(nd):  ";
	cin>>ch;
	if(ch=='E' || ch=='e')
	return 0;
	else if(ch=='S' || ch=='s')
	{
		int x=1   , y=1;  //declaring pacman coordinates
		int x1=20 , y1=8; //declaring enemy1 coordinates
		int x2=21 , y2=8;  //declaring enemy2 coordinates
		int x3=16 , y3=8;  //declaring enemy3 coordinates
		int pacman=char(1);   //initialzing pacman symbol
		int	enemy1='E';   //initialzing enemy 1 symbol
		int enemy2='E';   //initialzing enemy 2 symbol
		int enemy3='E';   //initialzing enemy 3 symbol
		int fruit=0, life=3; 
		int time=300;   //declaring time for pacman to become invinsible when eats the special fruit
		char w=219;
		char map[500][500] = //hardcoding the map
		{
			"#########################################",
			"# . . . . . . . . . # . . . . . . . . . #",
			"# . ##### . ##### . # . ##### . ##### . #",
			"# . . . . . . . . . . . . . . . . . . . #",
			"# . ##### . # . ######### . # . ##### . #",
			"# , . . . . ###  .  #  .  ### . . . . , #",
			"######### . #. . . . . . . .# . #########",
			"# . . . . .  .             .  . . . . . #",
			"# . ### . ## . #         # . ## . ### . #",
			"# . ### . ## . ########### . ## . ### . #",
			"# . ### . ## . . . . . . . . ## . ### . #",
			"# . ### . ## . ########### . ## . ### . #",
			"# . . . .  . . .  . # . . . . . . . . . #",
			"# . ### . ####### . # . ####### . ### . #",
			"# . ### . . . . . . . . . . . . . ### . #",
			"# . ### . ## . ########## . ### . ### . #",
			"# . . . . ## .  . . # . . . ### . . . . #",
			"############ . ## . # . ####### . #######",
			"# , . . . . . . . . . . . . . . . . . , #",
			"#########################################",
		};
		int dir=0    , up=-1  , down=-2  , left=-3  , right=-4;  //directions for pacman
		int dir1=4 , up1=4  , down1=3  , left1=2  , right1=1;  //directions for enemy1
		int dir2=4 ;  //directions for enemy2
		int dir3=9 ;  //directions for enemy3
		system("color e9");
		int i;
		for (int k=0 ; k<=19; k++)      //Loop for loading the game setup
    		for (int j=0 ; j<=41 ; j++)
			{
				gotoxy(k,j);
     			cout<<' ';
			}
		gotoxy(30,17);
		cout<<"PAC MAN ";
		gotoxy(20,19);
		cout<<"Loading";
		for(int k=20; k<=50; k++)
		{
			gotoxy(k,20);
			cout<<'.';
		}
		for(int k=20; k<=50; k++)
		{
			gotoxy(k,20);
			cout<<'<';
			Sleep(70);
			gotoxy(k,20);
			cout<<' ';
		}
		while(game==true)   //Loop for complete pacman game
		{
			Sleep(50);   //condition for slowing the pacman movement
			system("cls");
			for(i=0; i<20; i++)  //loop for printing the map
			{
				cout<<map[i]<<endl;
			}
		   for(int k=0; k<=19 ; k++)
				for(int j=0; j<=41 ; j++)
				{
					if(map[k][j]=='#')   //prinitng the boundries of the map
						map[k][j]=219;
				}
			map[y][x]=pacman; //printing the position of the pacman
			if(GetAsyncKeyState(VK_DOWN))  //condition for input of arrow keys for movement down
			{
				dir=down;
				dir1=rand()%5+1;
				dir2=rand()%5+4;
				dir3=rand()%5+9;
			}
			if(GetAsyncKeyState(VK_UP))   //condition for input of arrow keys for movement up
			{
				dir=up;
				dir1=rand()%5+1;
				dir2=rand()%5+4;
				dir3=rand()%5+9;
			}
		    if(GetAsyncKeyState(VK_RIGHT))    //condition for input of arrow keys for movement right
			{
				dir=right;
				dir1=rand()%5+1;
				dir2=rand()%5+4;
				dir3=rand()%5+9;
			}
		   	if(GetAsyncKeyState(VK_LEFT))   //condition for input of arrow keys for movement left
			{
				dir=left;
		    	dir1=rand()%5+1;
				dir2=rand()%5+4;
				dir3=rand()%5+9;
			}
			if(GetAsyncKeyState(VK_ESCAPE)) //condition for leaving during the game by pressing escape
			{
				game==false;
		    	cout<<"Score: "<<fruit<<endl;
				return 0;
			}
			if(dir==up)  //Pacman movement if up arrow key is hit
			{
				if(map[y-1][x]==' '|| map[y-1][x]=='.' || map[y-1][x]==enemy1 || map[y-1][x]==enemy2 || map[y-1][x]==enemy3)
				{
					map[y][x]=' ';
					y--;
					map[y][x]=pacman;
		    	}
			}
			if(dir==down)  //Pacman movement if down arrow key is hit
			{
				if(map[y+1][x]==' '|| map[y+1][x]=='.' || map[y+1][x]==enemy1 || map[y+1][x]==enemy2 || map[y+1][x]==enemy3)
				{
					map[y][x]=' ';
					y++;
					map[y][x]=pacman;
				}
		   	}
			if(dir==right)  //Pacman movement if right arrow key is hit
		   	{
				if(map[y][x+1]==' '|| map[y][x+1]=='.' ||map[y][x+1]==enemy1 || map[y][x+1]==enemy2 || map[y][x+1]==enemy3)
				{
					map[y][x]=' ';
					x++;
					map[y][x]=pacman;
				}
			}
			if(dir==left)  //Pacman movement if left arrow key is hit
			{
				if(map[y][x-1]==' '|| map[y][x-1]=='.' || map[y][x-1]==enemy1 || map[y][x-1]==enemy2 || map[y][x-1]==enemy3)
				{
					map[y][x]=' ';
					x--;
					map[y][x]=pacman;
				}
		   	}
			if(x1==1  && y1==1) dir1=rand()%5+1;  //Enemy1 movement
			if(x1==10 && y1==1) dir1=rand()%5+1;
			if(x1==19 && y1==1) dir1=rand()%5+1;
			if(x1==28 && y1==1) dir1=rand()%5+1;
			if(x1==37 && y1==1) dir1=rand()%5+1;
			if(x1==1  && y1==9) dir1=rand()%5+1;
			if(x1==10 && y1==9) dir1=rand()%5+1;
			if(x1==19 && y1==9) dir1=rand()%5+1;
			if(x1==28 && y1==9) dir1=rand()%5+1;
			if(x1==37 && y1==9) dir1=rand()%5+1;
			if(x1==1  && y1==14) dir1=rand()%5+1;
			if(x1==19 && y1==14) dir1=rand()%5+1;
			if(x1==37 && y1==14) dir1=rand()%5+1;
			if(x1==1 && y1==18) dir1=rand()%5+1;
			if(x1==1  && y1==14) dir1=rand()%5+1;
			if(x1==19 && y1==18) dir1=rand()%5+1;
			if(x1==37 && y1==18) dir1=rand()%5+1;

			if(x1==x2 && y1==y2)   //enemys next movement 
			{
				dir1=rand()%5+1;
				dir2=rand()%5+4;
				dir3=rand()%5+9;
			}
     		if(x1+1==x2 && y1==y2)  //enemys next movement
			{
				dir1=rand()%5+1;
				dir2=rand()%5+4;
				dir3=rand()%5+9;
			}
     		if(x1-1==x2 && y1==y2)  //enemys next movement
			{
				dir1=rand()%5+1;
				dir2=rand()%5+4;
				dir3=rand()%5+9;
			}
			if(x1==x2 && y1+1==y2)  //enemys next movement
			{
				dir1=rand()%5+1;
				dir2=rand()%5+4;
				dir3=rand()%5+9;
			}
			if(x1==x2 && y1-1==y2)  //enemys next movement
			{
				dir1=rand()%5+1;
				dir2=rand()%5+4;
				dir3=rand()%5+9;
			}
			if(x1==x3 && y1==y3)  //enemys next movement
			{
				dir1=rand()%5+1;
				dir2=rand()%5+4;
				dir3=rand()%5+9;
			}
			if(x1+1==x3 && y1==y3)  //enemys next movement
			{
				dir1=rand()%5+1;
				dir2=rand()%5+4;
				dir3=rand()%5+9;
			}
			if(x1-1==x3 && y1==y3)  //enemys next movement
			{
				dir1=rand()%5+1;
				dir2=rand()%5+4;
			    dir3=rand()%5+9;
			}
			if(x1==x3 && y1+1==y3)  //enemys next movement
			{
				dir1=rand()%5+1;
				dir2=rand()%5+4;
				dir3=rand()%5+9;
			}
			if(x1==x3 && y1-1==y3)  //enemys next movement
			{
				dir1=rand()%5+1;
				dir2=rand()%5+4;
				dir3=rand()%5+9;
			}
			if(x2==x3 && y2==y3)  //enemys next movement
			{
				dir1=rand()%5+1;
				dir2=rand()%5+4;
				dir3=rand()%5+9;
			}
	    	if(x2+1==x3 && y2==y3)  //enemys next movement
			{
	      		dir1=rand()%5+1;
				dir2=rand()%5+4;
				dir3=rand()%5+9;
			}
			if(x2-1==x3 && y2==y3)  // enemys next movement
			{
				dir1=rand()%5+1;
				dir2=rand()%5+4;
				dir3=rand()%5+9;
			}
			if(x2==x3 && y2+1==y3)  // enemys next movement
			{
				dir1=rand()%5+1;
				dir2=rand()%5+4;
				dir3=rand()%5+9;
			}
			if(x2==x3 && y2-1==y3)  // enemys next movement
			{
				dir1=rand()%5+1;
				dir2=rand()%5+4;
				dir3=rand()%5+9;
			}
			if(dir1==up1)  //enemy1 up movement 
			{
				if(map[y1-1][x1]==' ' || map[y1-1][x1]==pacman)
				{
					map[y1][x1]=' ';
					y1--;
					map[y1][x1]=enemy1;
				}
				if(map[y1-1][x1]=='.' || map[y1-1][x1]==pacman)
				{
					map[y1][x1]='.';
	    			y1--;
					map[y1][x1]=enemy1;
				}
		    }
			if(dir1==down1)  //enemy1 down movement
			{
		    	if(map[y1+1][x1]==' ' || map[y1+1][x1]==pacman)
				{
					map[y1][x1]=' ';
					y1++;
					map[y1][x1]=enemy1;
				}
				if(map[y1+1][x1]=='.' || map[y1+1][x1]==pacman)
				{
					map[y1][x1]='.';
					y1++;
					map[y1][x1]=enemy1;
				}
			}
			if(dir1==left1)   //enemy1 left movement
			{
				if(map[y1][x1-1]==' ' || map[y1][x1-1]==pacman)
				{
					map[y1][x1]=' ';
					x1--;
					map[y1][x1]=enemy1;
				}
				if(map[y1][x1-1]=='.' || map[y1][x1-1]==pacman)
				{
					map[y1][x1]='.';
					x1--;
					map[y1][x1]=enemy1;
				}
		   	}
		   	if(dir1==right1)   //enemy1 right movement
			{
				if(map[y1][x1+1]==' ' || map[y1][x1+1]==pacman)
				{
					map[y1][x1]=' ';
					x1++;
					map[y1][x1]=enemy1;
				}
				if(map[y1][x1+1]=='.' || map[y1][x1+1]==pacman)
				{
					map[y1][x1]='.';
					x1++;
					map[y1][x1]=enemy1;
				}
			}
			if(x2==1  && y2==1) dir2=rand()%5+5;  //Movement of enemy 2
			if(x2==10 && y2==1) dir2=rand()%5+5;
			if(x2==19 && y2==1) dir2=rand()%5+5;
			if(x2==28 && y2==1) dir2=rand()%5+5;
			if(x2==37 && y2==1) dir2=rand()%5+5;
			if(x2==1  && y2==9) dir2=rand()%5+5;
			if(x2==10 && y2==9) dir2=rand()%5+5;
			if(x2==19 && y2==9) dir2=rand()%5+5;
			if(x2==28 && y2==9) dir2=rand()%5+5;
			if(x2==37 && y2==9) dir2=rand()%5+5;
			if(x2==1  && y2==14) dir2=rand()%5+5;
			if(x2==19 && y2==14) dir2=rand()%5+5;
			if(x2==37 && y2==14) dir2=rand()%5+5;
			if(x2==1 && y2==18) dir2=rand()%5+5;
			if(x2==1  && y2==14) dir2=rand()%5+5;
			if(x2==19 && y2==18) dir2=rand()%5+5;
			if(x2==37 && y2==18) dir2=rand()%5+5;

			if(dir1==down1)  //enemy 2 down movement
			{
				if(map[y2-1][x2]==' ' || map[y2-1][x2]==pacman)
				{
					map[y2][x2]=' ';
					y2--;
					map[y2][x2]=enemy2;
				}
				if(map[y2-1][x2]=='.' || map[y2-1][x2]==pacman)
				{
					map[y2][x2]='.';
					y2--;
					map[y2][x2]=enemy2;
				}
			}
			if(dir1==up1) //enemy 2 up movement
			{
				if(map[y2+1][x2]==' ' || map[y2+1][x2]==pacman)
				{
					map[y2][x2]=' ';
					y2++;
					map[y2][x2]=enemy2;
				}
	     		if(map[y2+1][x2]=='.' || map[y2+1][x2]==pacman)
				{
					map[y2][x2]='.';
					y2++;
					map[y2][x2]=enemy2;
				}
			}
			if(dir1==left1)  //enemy 2 left movement
			{
				if(map[y2][x2+1]==' ' || map[y2][x2+1]==pacman)
				{
					map[y2][x2]=' ';
					x2++;
					map[y2][x2]=enemy2;
				}
				if(map[y2][x2+1]=='.' || map[y2][x2+1]==pacman)
				{
					map[y2][x2]='.';
					x2++;
					map[y2][x2]=enemy2;
				}
		    }
			if(dir1==right1)   //enemy 2 down movement
			{
				if(map[y2][x2-1]==' ' || map[y2][x2-1]==pacman)
				{
					map[y2][x2]=' ';
					x2--;
					map[y2][x2]=enemy2;
				}
				if(map[y2][x2-1]=='.' || map[y2][x2-1]==pacman)
				{
					map[y2][x2]='.';
					x2--;
	        		map[y2][x2]=enemy2;
				}
			}
		    if(x3==1  && y3==1) dir3=rand()%5+9;  //movement of enemy 3
			if(x3==10 && y3==1) dir3=rand()%5+9;
			if(x3==19 && y3==1) dir3=rand()%5+9;
			if(x3==28 && y3==1) dir3=rand()%5+9;
			if(x3==37 && y3==1) dir3=rand()%5+9;
			if(x3==1  && y3==9) dir3=rand()%5+9;
			if(x3==10 && y3==9) dir3=rand()%5+9;
			if(x3==19 && y3==9) dir3=rand()%5+9;
			if(x3==28 && y3==9) dir3=rand()%5+9;
			if(x3==37 && y3==9) dir3=rand()%5+9;
			if(x3==1  && y3==14) dir3=rand()%5+9;
			if(x3==19 && y3==14) dir3=rand()%5+9;
			if(x3==37 && y3==14) dir3=rand()%5+9;
			if(x3==1  && y3==18) dir3=rand()%5+9;
			if(x3==1  && y3==14) dir3=rand()%5+9;
			if(x3==19 && y3==18) dir3=rand()%5+9;
			if(x3==37 && y3==18) dir3=rand()%5+9;
			
			if(dir1==down1)  //enemy 3 down movement
			{
				if(map[y3-1][x3]==' ' || map[y3-1][x3]==pacman)
				{
					map[y3][x3]=' ';
					y3--;
					map[y3][x3]=enemy3;
				}
				if(map[y3-1][x3]=='.' || map[y3-1][x3]==pacman)
				{
					map[y3][x3]='.';
	     			y3--;
					map[y3][x3]=enemy3;
				}
			}
			if(dir1==up1)  //enemy 3 up movement
			{
				if(map[y3+1][x3]==' ' || map[y3+1][x3]==pacman)
				{
					map[y3][x3]=' ';
					y3++;
					map[y3][x3]=enemy3;
				}
	    		if(map[y3+1][x3]=='.' || map[y3+1][x3]==pacman)
				{
					map[y3][x3]='.';
					y3++;
					map[y3][x3]=enemy3;
				}
			}
			if(dir1==left1)  //enemy 3 left movement
			{
				if(map[y3][x3+1]==' ' || map[y3][x3+1]==pacman)
				{
					map[y3][x3]=' ';
					x3++;
			    	map[y3][x3]=enemy3;
     			}
				if(map[y3][x3+1]=='.' || map[y3][x3+1]==pacman)
				{
					map[y3][x3]='.';
					x3++;
					map[y3][x3]=enemy3;
				}
			}
			if(dir1==right1)  //enemy 3 right movement
			{
				if(map[y3][x3-1]==' ' || map[y3][x3-1]==pacman)
				{
					map[y3][x3]=' ';
					x3--;
					map[y3][x3]=enemy3;
				}
				if(map[y3][x3-1]=='.' || map[y3][x3-1]==pacman)
				{
					map[y3][x3]='.';
					x3--;
					map[y3][x3]=enemy3;
				}
			}
			//condition for pacmans life decrement if hit by the enemy
		    if(map[y][x]==' ' || map[y1][x1]==' ' || map[y2][x2]==' ' || map[y3][x3]==' ' || map[y][x]==enemy1 || map[y][x]==enemy2 || map[y][x]==enemy3)
			{
				if(pacman=='c')
				{
					life--;
					if(life==0)   //gameover if life becomes zero
				    {					
		               cout<<"YOU LOSE"<<endl;
		               cout<<"SCORE: "<<fruit<<endl;
		               return 0;
				    }
				}
			}
			if(map[y+1][x]=='.')  //condition for increment of score as the pacman eats dots
			{
				map[y+1][x]=' ';
				fruit++;
			}
			if(map[y-1][x]=='.')  //condition for increment of score as the pacman eats dots
			{
	    		map[y-1][x]=' ';
				fruit++;
			}
			if(map[y][x+1]=='.')  //condition for increment of score as the pacman eats dots
			{
				map[y][x+1]=' ';
				fruit++;
			}
			if(map[y][x-1]=='.')  //condition for increment of score as the pacman eats dots
			{
		    	map[y][x-1]=' ';
				fruit++;
			}
			if(map[y+1][x]==',')  //condition for increment of score as the pacman eats special dots
			{
				map[y+1][x]=' ';  //pacman becomes bigger as it eats the special dot
				pacman='C';	  							  
				fruit+=5; 	
			}
			if(pacman=='C')    //pacman becomes smaller after 5 seconds
			{
				time--;
				if(time==225)
			    {
			    	pacman='c';
			    }
				else if(time==150)
				{
					pacman='c';
				}
				else if(time==75)
				{
					pacman='c';
				}
				else if(time==0)
				{
					pacman='c';
				}			
			}
		    if(map[y-1][x]==',')   //condition for increment of score as the pacman eats special dots
			{ 
				map[y-1][x]=' ';   //pacman becomes bigger as it eats the special dot
				pacman='C';	  		 				  
				fruit+=5;  		
			}
			if(pacman=='C')    //pacman becomes smaller after 5 seconds
			{
				time--;
				if(time==225)
			    {
			    	pacman='c';
			    }
				else if(time==150)
				{
					pacman='c';
				}
				else if(time==75)
				{
					pacman='c';
				}
				else if(time==0)
				{
					pacman='c';
				}					
			}	
		    if(map[y][x+1]==',')  //condition for increment of score as the pacman eats special dots
			{
				map[y][x+1]=' ';  //pacman becomes bigger as it eats the special dot
				pacman='C';
				fruit+=5;
			}
			if(pacman=='C')  //pacman becomes smaller after 5 seconds
			{
				time--;
			    if(time==225)
		        {
		        	pacman='c';
		        }
				else if(time==150)
				{
					pacman='c';
				}
				else if(time==75)
				{
					pacman='c';
				}
				else if(time==0)
				{
					pacman='c';
				}						
			}		
		    if(map[y][x-1]==',')  //condition for increment of score as the pacman eats special dots
			{
				map[y][x-1]=' ';  //pacman becomes bigger as it eats the special dot
				pacman='C';				 			
			    fruit+=5;   		
		    }
		    if(pacman=='C')  //pacman becomes smaller after 5 seconds
			{
				time--;
				if(time==225)
			    {
			       pacman='c';
		        }
				else if(time==150)
				{
					pacman='c';
				}
				else if(time==75)
				{
					pacman='c';
				}
				else if(time==0)
				{
					pacman='c';
				}							
			}	
			gotoxy(43,3);
			cout<<"Fruit = "<<fruit<<endl; //output of fruit 
			if(fruit==210)  //the user will win the level if the fruits are equal to 210
			{
				gotoxy(21,22);
				cout<<"YOU WIN    NEXT LEVEL"<<endl;  
				Sleep(2000);
				level2();  //next level will be reached 
						
				if(game2=true)  //if failed in level 2 the game will close
				{
					return 0;
				}
			}
			gotoxy(43,5);   
			cout<<"PAC MAN"<<endl;
			gotoxy(43,6);
			cout<<"CONSOLE GAME"<<endl;
			gotoxy(43,7);
			cout<<"Life: "<<life<<endl;
			gotoxy(43,8);
			cout<<"PACMAN: "<<"C"<<endl;
			gotoxy(43,9);
			cout<<"ENEMY1: "<<"E"<<endl;
			gotoxy(43,10);
			cout<<"ENEMY2: "<<"E"<<endl;
			gotoxy(43,11);
			cout<<"ENEMY3: "<<"E"<<endl;
		}
		int getch(void); //for invisible inputs
	}
	else
	cout<<"ERROR"<<endl;
}
