using namespace std;
void gotoxy3(int x , int y)
{
	static HANDLE h = NULL; 
	if(!h)
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x , y };
	SetConsoleCursorPosition(h,c);
}
bool game3=true; 
int level3()
{
	int x=1   , y=1;  
	int x1=20 , y1=8; 
	int x2=21 , y2=8;  
	int x3=16 , y3=8;  
	int pacman= char(1);   
	int	enemy1= char(4);   
	int enemy2= char(5);   
	int enemy3= char(6);   
	int fruit3=0, life3=1; 
	char w=219;
	char map3[500][500] = 
    {  
        "######################################",
		"#. . #.  .## . .##. .#. . .## . .## .#", 
		"#. . . . ### . # . ##### . #####.  . #", 
		"#. . . . ##. . . . . . . # . . .### .#", 
		"#.#####. .##. . . #### .## .##. . .  #", 
		"#. # . . .  ##. . #. . ##### .# #. . #", 
		"##. . . ###. . ##### . #. . . #   .  #", 
		"# . . . . . . ## . . . . #  . . ##  .#", 
		"# . ## . ## . ##. . . #### . # .  .  #", 
		"# . # . ## . . . #  . # . # . . # .  #", 
		"# . ## . ## . #. .# . . . ### . ## . #", 
		"# . . . # . # . . . # . . # # . # .  #", 
		"#. . ### . # . . . ### . . #### . . .#", 
		"#. # #. ####### . # . ###### . ### . #", 
		"#. .  # . ### . . . # # . .## . . . .#", 
		"#. . # . . ## . # . # . . .  ## .  . #", 
		"#. .  ##. . . # . . . ### . . . ## . #", 
		"#. . . #### . ###. . ### . . ##  . . #", 
		"#. ## . . . . . ####### . . . ### . .#", 
		"######################################",
	};
		
	int dir=0    , up=-1  , down=-2  , left=-3  , right=-4;
	int dir1=4 , up1=4  , down1=3  , left1=2  , right1=1; 
	int dir2=4; 
	int dir3=9; 
    int i;
	while(game3==true)
	{
		Sleep(50); 
		system("cls");
		for(i=0; i<20; i++) 
		{
			cout<<map3[i]<<endl;
		}
	    for(int k=0; k<=19 ; k++) 
		    for(int j=0; j<=41 ; j++)  
		    {
				if(map3[k][j]=='#')
				map3[k][j]=219;
			}
			map3[y][x]=pacman;
			if(GetAsyncKeyState(VK_DOWN))
			{
				dir=down;
				dir1=rand()%5+1;
				dir2=rand()%5+4;
				dir3=rand()%5+9;
			}
			if(GetAsyncKeyState(VK_UP))  
			{
				dir=up;
				dir1=rand()%5+1;
				dir2=rand()%5+4;
				dir3=rand()%5+9;
			}
			if(GetAsyncKeyState(VK_RIGHT))  
			{
				dir=right;
				dir1=rand()%5+1;
				dir2=rand()%5+4;
				dir3=rand()%5+9;
			}
			if(GetAsyncKeyState(VK_LEFT))  
			{
				dir=left;
				dir1=rand()%5+1;
				dir2=rand()%5+4;
				dir3=rand()%5+9;
			}
			if(GetAsyncKeyState(VK_ESCAPE)) 
			{
				game3==false;
				cout<<"SCORE: "<<fruit3<<endl;
				break;
			}
			if(dir==up) 
			{
				if(map3[y-1][x]==' '|| map3[y-1][x]=='.' ||map3[y-1][x]==enemy1 || map3[y-1][x]==enemy2 || map3[y-1][x]==enemy3)
					{
						map3[y][x]=' ';
			        	y--;
						map3[y][x]=pacman;
					}
			}
			if(dir==down) 
			{
				if(map3[y+1][x]==' '|| map3[y+1][x]=='.' || map3[y+1][x]==enemy1 || map3[y+1][x]==enemy2 || map3[y+1][x]==enemy3)
				{
					map3[y][x]=' ';
					y++;
					map3[y][x]=pacman;
				}
			}
			if(dir==right) 
			{
				if(map3[y][x+1]==' '|| map3[y][x+1]=='.' || map3[y][x+1]==enemy1 || map3[y][x+1]==enemy2 || map3[y][x+1]==enemy3)
					{
						map3[y][x]=' ';
						x++;
						map3[y][x]=pacman;
					}
			}
			if(dir==left) 
			{
				if(map3[y][x-1]==' '|| map3[y][x-1]=='.' || map3[y][x-1]==enemy1 || map3[y][x-1]==enemy2 || map3[y][x-1]==enemy3)
				{
					map3[y][x]=' ';
					x--;
					map3[y][x]=pacman;
				}
	    	}
			if(x1==1  && y1==1) dir1=rand()%5+1; 
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

			if(x1==x2 && y1==y2)   
			{
				dir1=rand()%5+1;
				dir2=rand()%5+4;
				dir3=rand()%5+9;
			}
			if(x1+1==x2 && y1==y2)   
			{
				dir1=rand()%5+1;
				dir2=rand()%5+4;
				dir3=rand()%5+9;
			}
			if(x1-1==x2 && y1==y2)   
			{
				dir1=rand()%5+1;
				dir2=rand()%5+4;
				dir3=rand()%5+9;
			}
			if(x1==x2 && y1+1==y2)   
			{
				dir1=rand()%5+1;
				dir2=rand()%5+4;
				dir3=rand()%5+9;
			}
			if(x1==x2 && y1-1==y2)   
			{
				dir1=rand()%5+1;
				dir2=rand()%5+4;
				dir3=rand()%5+9;
			}
			if(x1==x3 && y1==y3)   
			{
				dir1=rand()%5+1;
				dir2=rand()%5+4;
				dir3=rand()%5+9;
			}
		    if(x1+1==x3 && y1==y3)    
			{
				dir1=rand()%5+1;
				dir2=rand()%5+4;
				dir3=rand()%5+9;
			}
			if(x1-1==x3 && y1==y3)   
			{
				dir1=rand()%5+1;
				dir2=rand()%5+4;
				dir3=rand()%5+9;
			}
			if(x1==x3 && y1+1==y3)   
			{
				dir1=rand()%5+1;
				dir2=rand()%5+4;
				dir3=rand()%5+9;
			}
			if(x1==x3 && y1-1==y3)   
			{
				dir1=rand()%5+1;
				dir2=rand()%5+4;
				dir3=rand()%5+9;
			}
	    	if(x2==x3 && y2==y3)   
			{
				dir1=rand()%5+1;
				dir2=rand()%5+4;
				dir3=rand()%5+9;
			}
			if(x2+1==x3 && y2==y3)   
			{
				dir1=rand()%5+1;
				dir2=rand()%5+4;
				dir3=rand()%5+9;
		    }
			if(x2-1==x3 && y2==y3)   
			{
				dir1=rand()%5+1;
				dir2=rand()%5+4;
				dir3=rand()%5+9;
			}
		    if(x2==x3 && y2+1==y3)  
			{
				dir1=rand()%5+1;
				dir2=rand()%5+4;
				dir3=rand()%5+9;
			}
			if(x2==x3 && y2-1==y3)  
			{
				dir1=rand()%5+1;
				dir2=rand()%5+4;
				dir3=rand()%5+9;
			}
			if(dir1==up1) 
			{
				if(map3[y1-1][x1]==' ' || map3[y1-1][x1]==pacman)
				{
					map3[y1][x1]=' ';
					y1--;
					map3[y1][x1]=enemy1;
				}
				if(map3[y1-1][x1]=='.' || map3[y1-1][x1]==pacman)
				{
					map3[y1][x1]='.';
					y1--;
					map3[y1][x1]=enemy1;
				}
			}
			if(dir1==down1) 
			{
				if(map3[y1+1][x1]==' ' || map3[y1+1][x1]==pacman)
				{
					map3[y1][x1]=' ';
					y1++;
					map3[y1][x1]=enemy1;
				}
				if(map3[y1+1][x1]=='.' || map3[y1+1][x1]==pacman)
				{
					map3[y1][x1]='.';
					y1++;
					map3[y1][x1]=enemy1;
				}
			}
		    if(dir1==left1)
			{
				if(map3[y1][x1-1]==' ' || map3[y1][x1-1]==pacman)
				{
					map3[y1][x1]=' ';
					x1--;
					map3[y1][x1]=enemy1;
				}
				if(map3[y1][x1-1]=='.' || map3[y1][x1-1]==pacman)
				{
					map3[y1][x1]='.';
					x1--;
					map3[y1][x1]=enemy1;
				}
			}
			if(dir1==right1) 
			{
				if(map3[y1][x1+1]==' ' || map3[y1][x1+1]==pacman)
				{
					map3[y1][x1]=' ';
					x1++;
	     			map3[y1][x1]=enemy1;
		    	}
				if(map3[y1][x1+1]=='.' || map3[y1][x1+1]==pacman)
				{
					map3[y1][x1]='.';
					x1++;
					map3[y1][x1]=enemy1;
				}
			}
			if(x2==1  && y2==1) dir2=rand()%5+5; 
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

			if(dir1==down1) 
			{
				if(map3[y2-1][x2]==' ' || map3[y2-1][x2]==pacman)
				{
					map3[y2][x2]=' ';
					y2--;
					map3[y2][x2]=enemy2;
				}
				if(map3[y2-1][x2]=='.' || map3[y2-1][x2]==pacman)
				{
					map3[y2][x2]='.';
					y2--;
					map3[y2][x2]=enemy2;
				}
			}
		    if(dir1==up1) 
			{
				if(map3[y2+1][x2]==' ' || map3[y2+1][x2]==pacman)
				{
					map3[y2][x2]=' ';
					y2++;
					map3[y2][x2]=enemy2;
				}
		    	if(map3[y2+1][x2]=='.' || map3[y2+1][x2]==pacman)
				{
					map3[y2][x2]='.';
					y2++;
					map3[y2][x2]=enemy2;
				}
		    }
			if(dir1==left1)  
			{
				if(map3[y2][x2+1]==' ' || map3[y2][x2+1]==pacman)
				{
					map3[y2][x2]=' ';
					x2++;
					map3[y2][x2]=enemy2;
	    		}
				if(map3[y2][x2+1]=='.' || map3[y2][x2+1]==pacman)
				{
					map3[y2][x2]='.';
					x2++;
					map3[y2][x2]=enemy2;
				}
			}
			if(dir1==right1)  
			{
				if(map3[y2][x2-1]==' ' || map3[y2][x2-1]==pacman)
				{
					map3[y2][x2]=' ';
					x2--;
					map3[y2][x2]=enemy2;
	     		}
				if(map3[y2][x2-1]=='.' || map3[y2][x2-1]==pacman)
				{
					map3[y2][x2]='.';
					x2--;
					map3[y2][x2]=enemy2;
				}
			}
		    if(x3==1  && y3==1) dir3=rand()%5+9; 
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

			if(dir1==down1)   
			{
				if(map3[y3-1][x3]==' ' || map3[y3-1][x3]==pacman)
				{
					map3[y3][x3]=' ';
					y3--;
					map3[y3][x3]=enemy3;
				}
			    if(map3[y3-1][x3]=='.' || map3[y3-1][x3]==pacman)
				{
					map3[y3][x3]='.';
					y3--;
					map3[y3][x3]=enemy3;
				}
	    	}
			if(dir1==up1)  
			{
				if(map3[y3+1][x3]==' ' || map3[y3+1][x3]==pacman)
				{
					map3[y3][x3]=' ';
					y3++;
					map3[y3][x3]=enemy3;
				}
				if(map3[y3+1][x3]=='.' || map3[y3+1][x3]==pacman)
				{
					map3[y3][x3]='.';
					y3++;
					map3[y3][x3]=enemy3;
				}
			}
			if(dir1==left1)  
			{
				if(map3[y3][x3+1]==' ' || map3[y3][x3+1]==pacman)
				{
					map3[y3][x3]=' ';
					x3++;
					map3[y3][x3]=enemy3;
				}
		    	if(map3[y3][x3+1]=='.' || map3[y3][x3+1]==pacman)
				{
					map3[y3][x3]='.';
					x3++;
					map3[y3][x3]=enemy3;
				}
			}
			if(dir1==right1)  
			{
				if(map3[y3][x3-1]==' ' || map3[y3][x3-1]==pacman)
				{
					map3[y3][x3]=' ';
					x3--;
					map3[y3][x3]=enemy3;
				}
			    if(map3[y3][x3-1]=='.' || map3[y3][x3-1]==pacman)
			    {
			     	map3[y3][x3]='.';
			    	x3--;
     		    	map3[y3][x3]=enemy3;
		    	}
	    	}
			if(map3[y][x]==' ' || map3[y1][x1]==' ' || map3[y2][x2]==' ' || map3[y3][x3]==' ' || map3[y][x]==enemy1 || map3[y][x]==enemy2 || map3[y][x]==enemy3)
			{
				if(pacman=='c')
				{
					life3--;
			        if(life3==0)  
			    	{							
				    	cout<<"YOU LOSE "<<endl;
				    	cout<<"FINAL SCORE: "<<fruit3<<endl;
				    	game3=false;
				    	return 1;	
			    	}		
				}	
			}
			if(map3[y+1][x]=='.')  
			{
				map3[y+1][x]=' ';
				fruit3++;
			}
	    	if(map3[y-1][x]=='.') 
			{
				map3[y-1][x]=' ';
				fruit3++;
			}
		    if(map3[y][x+1]=='.')  
			{
				map3[y][x+1]=' ';
				fruit3++;
			}
			if(map3[y][x-1]=='.')  
			{
				map3[y][x-1]=' ';
				fruit3++;
			}
			gotoxy3(43,3);
	    	cout<<"Healthy Fruit Points = "<<fruit3<<endl; 
			if(fruit3==195)  
			{
				gotoxy3(20,20);
				cout<<"YOU WIN"<<endl;
				return 1;	  	
			}
			gotoxy3(43,5);
			cout<<"Fiber MAN"<<endl;
			gotoxy3(43,6);
			cout<<"CONSOLE GAME"<<endl;
			gotoxy3(43,7);
			cout<<"Life: "<<life3<<endl;
			gotoxy3(43,8);
			cout<<"Fiber Man  : "<< char(1) <<endl;
			gotoxy3(43,9);
			cout<<"Junk Food 1: "<< char(4) <<endl;
			gotoxy3(43,10);
			cout<<"Junk Food 2: "<< char(5) <<endl;
			gotoxy3(43,11);
			cout<<"Junk Food 3:  "<< char(6) <<endl;
		}
    int getch(void);
}

