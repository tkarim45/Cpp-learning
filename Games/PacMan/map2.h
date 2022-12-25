#include "map3.h"
using namespace std;
void gotoxy2(int x , int y)       
{
	static HANDLE h = NULL;
	if(!h)
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x , y };
	SetConsoleCursorPosition(h,c);
}
bool game2=true;    
int level2()    
{
   	int x=1   , y=1;  
	int x1=20 , y1=8;
	int x2=21 , y2=8;  
	int x3=16 , y3=8;  
	int pacman=char(1);   
	int	enemy1= char(4);   
	int enemy2= char(5);   
	int enemy3= char(6);   
	int fruit2=0, life2=2; 
	char w=219;
	char map2[500][500] = 
    {
	    "#######################################",
	   	"#. . . #####. . .###### . . .# . . . .#",  
		"#.##### . ##### . . . ##### . #####. .#",  
		"#. . . .####### . #######. . . . . . .#",  
		"#.#####. .#. . .##. . .#.  . . . ##. .#",  
		"#. .##### . . . # .## .#. .####. . . .#",  
		"#####. . .###. . .##### . . . . .# . .#",
		"# . . . . . .#### . . . . . . . . .# .#",  
		"# . #### . # . . . .# . # . . . . ## .#", 
		"# .  ### . # . # . # . # . . ##. . . .#",  
		"# . ### . # . #. . . ####. . . . # . .#",  
		"# . . . . ########### . # . #. . . . .#",
		"#. #######. . . . . . . .# .  ## . . .#",  
		"#.#### . ###### . # . ###### . ####. .#",  
		"#. . # . . .  ######. . . . . . . .  .#",  
		"#. . # . ## . ##### . ####. #. . . . .#",  
		"#. . . . ## . . . . .### . . . . . . .#",  
		"#.###### . . . ## . ###. . . .###. . .#",  
		"#. . ###.##. .## . ##. . . . ### . . .#",  
		"#######################################",
	};
			
	int dir=0    , up=-1  , down=-2  , left=-3  , right=-4; 
	int dir1=4 , up1=4  , down1=3  , left1=2  , right1=1;  
	int dir2=4;  
	int dir3=9; 
	int i;
	while(game2==true)  
	{
		Sleep(50);  
		system("cls");
		for(i=0; i<20; i++)  
		{
			cout<<map2[i]<<endl;
		}
	    for(int k=0; k<=19 ; k++)
			for(int j=0; j<=41 ; j++)
			{
				if(map2[k][j]=='#')  
				map2[k][j]=219;  
			}
			map2[y][x]=pacman;  
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
				game2==false;
				cout<<"Score: "<<fruit2<<endl;
				break;
			}
			if(dir==up)  
			{
				if(map2[y-1][x]==' '|| map2[y-1][x]=='.' ||map2[y-1][x]==enemy1 || map2[y-1][x]==enemy2 || map2[y-1][x]==enemy3)
				{
					map2[y][x]=' ';
					y--;
					map2[y][x]=pacman;
				}
			}
			if(dir==down)  
			{
				if(map2[y+1][x]==' '|| map2[y+1][x]=='.' || map2[y+1][x]==enemy1 || map2[y+1][x]==enemy2 || map2[y+1][x]==enemy3)
				{
					map2[y][x]=' ';
					y++;
					map2[y][x]=pacman;
				}
			}
		    if(dir==right)  
			{
				if(map2[y][x+1]==' '|| map2[y][x+1]=='.' || map2[y][x+1]==enemy1 || map2[y][x+1]==enemy2 || map2[y][x+1]==enemy3)
					{
						map2[y][x]=' ';
						x++;
						map2[y][x]=pacman;
					}
			}
			if(dir==left) 
			{
				if(map2[y][x-1]==' '|| map2[y][x-1]=='.' || map2[y][x-1]==enemy1 || map2[y][x-1]==enemy2 || map2[y][x-1]==enemy3)
					{
						map2[y][x]=' ';
						x--;
			        	map2[y][x]=pacman;
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
				if(map2[y1-1][x1]==' ' || map2[y1-1][x1]==pacman)
				{
					map2[y1][x1]=' ';
					y1--;
					map2[y1][x1]=enemy1;
				}
				if(map2[y1-1][x1]=='.' || map2[y1-1][x1]==pacman)
				{
					map2[y1][x1]='.';
				   	y1--;
					map2[y1][x1]=enemy1;
				}
		   	}
			if(dir1==down1)   
			{
				if(map2[y1+1][x1]==' ' || map2[y1+1][x1]==pacman)
				{
					map2[y1][x1]=' ';
					y1++;
					map2[y1][x1]=enemy1;
				}
				if(map2[y1+1][x1]=='.' || map2[y1+1][x1]==pacman)
				{
					map2[y1][x1]='.';
					y1++;
					map2[y1][x1]=enemy1;
				}
			}
			if(dir1==left1)   
			{
				if(map2[y1][x1-1]==' ' || map2[y1][x1-1]==pacman)
				{
					map2[y1][x1]=' ';
					x1--;
					map2[y1][x1]=enemy1;
				}
				if(map2[y1][x1-1]=='.' || map2[y1][x1-1]==pacman)
				{
					map2[y1][x1]='.';
					x1--;
					map2[y1][x1]=enemy1;
				}
			}
			if(dir1==right1)   
			{
				if(map2[y1][x1+1]==' ' || map2[y1][x1+1]==pacman)
				{
					map2[y1][x1]=' ';
					x1++;
					map2[y1][x1]=enemy1;
				}
		    	if(map2[y1][x1+1]=='.' || map2[y1][x1+1]==pacman)
				{
					map2[y1][x1]='.';
					x1++;
					map2[y1][x1]=enemy1;
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
				if(map2[y2-1][x2]==' ' || map2[y2-1][x2]==pacman)
				{
					map2[y2][x2]=' ';
					y2--;
					map2[y2][x2]=enemy2;
				}
		    	if(map2[y2-1][x2]=='.' || map2[y2-1][x2]==pacman)
				{
					map2[y2][x2]='.';
					y2--;
			    	map2[y2][x2]=enemy2;
				}
			}
			if(dir1==up1) 
			{
				if(map2[y2+1][x2]==' ' || map2[y2+1][x2]==pacman)
				{
					map2[y2][x2]=' ';
					y2++;
					map2[y2][x2]=enemy2;
				}
		    	if(map2[y2+1][x2]=='.' || map2[y2+1][x2]==pacman)
				{
					map2[y2][x2]='.';
					y2++;
					map2[y2][x2]=enemy2;
				}
			}
			if(dir1==left1) 
			{
				if(map2[y2][x2+1]==' ' || map2[y2][x2+1]==pacman)
				{
					map2[y2][x2]=' ';
					x2++;
					map2[y2][x2]=enemy2;
				}
			    if(map2[y2][x2+1]=='.' || map2[y2][x2+1]==pacman)
				{
					map2[y2][x2]='.';
					x2++;
		     		map2[y2][x2]=enemy2;
				}
			}
			if(dir1==right1)  
			{
				if(map2[y2][x2-1]==' ' || map2[y2][x2-1]==pacman)
				{
					map2[y2][x2]=' ';
					x2--;
					map2[y2][x2]=enemy2;
				}
			   if(map2[y2][x2-1]=='.' || map2[y2][x2-1]==pacman)
		    	{
					map2[y2][x2]='.';
					x2--;
					map2[y2][x2]=enemy2;
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
				if(map2[y3-1][x3]==' ' || map2[y3-1][x3]==pacman)
				{
					map2[y3][x3]=' ';
					y3--;
					map2[y3][x3]=enemy3;
				}
				if(map2[y3-1][x3]=='.' || map2[y3-1][x3]==pacman)
				{
					map2[y3][x3]='.';
					y3--;
					map2[y3][x3]=enemy3;
				}
			}
		    if(dir1==up1)   
			{
				if(map2[y3+1][x3]==' ' || map2[y3+1][x3]==pacman)
				{
					map2[y3][x3]=' ';
					y3++;
					map2[y3][x3]=enemy3;
				}
				if(map2[y3+1][x3]=='.' || map2[y3+1][x3]==pacman)
				{
					map2[y3][x3]='.';
					y3++;
					map2[y3][x3]=enemy3;
				}
			}
			if(dir1==left1)  
			{
				if(map2[y3][x3+1]==' ' || map2[y3][x3+1]==pacman)
				{
					map2[y3][x3]=' ';
					x3++;
	     			map2[y3][x3]=enemy3;
				}
				if(map2[y3][x3+1]=='.' || map2[y3][x3+1]==pacman)
				{
					map2[y3][x3]='.';
		     		x3++;
		    		map2[y3][x3]=enemy3;
				}
			}
			if(dir1==right1)   
			{
				if(map2[y3][x3-1]==' ' || map2[y3][x3-1]==pacman)
				{
					map2[y3][x3]=' ';
					x3--;
					map2[y3][x3]=enemy3;
				}
			    if(map2[y3][x3-1]=='.' || map2[y3][x3-1]==pacman)
			    {
					map2[y3][x3]='.';
					x3--;
					map2[y3][x3]=enemy3;
	     	    }
			}
			if(map2[y][x]==' ' || map2[y1][x1]==' ' || map2[y2][x2]==' ' || map2[y3][x3]==' ' || map2[y][x]==enemy1 || map2[y][x]==enemy2 || map2[y][x]==enemy3)
			{
				if(pacman==char(1))
				{
					life2--;
					if(life2==0)  
				    {							
					    cout<<"YOU LOSE "<<endl;
				    	cout<<"FINAL SCORE: "<<fruit2<<endl;
				    	game2=false;
				    	return 1;
				    }
				}	  	
			}
			if(map2[y+1][x]=='.') 
			{
				map2[y+1][x]=' ';
				fruit2++;
			}
	    	if(map2[y-1][x]=='.')  
			{
				map2[y-1][x]=' ';
				fruit2++;
			}
	    	if(map2[y][x+1]=='.')  
			{
				map2[y][x+1]=' ';
				fruit2++;
			}
	    	if(map2[y][x-1]=='.')
			{
				map2[y][x-1]=' ';
				fruit2++;
			}
			gotoxy2(43,3);
			cout<<"Healthy Fruit Points = "<<fruit2<<endl; 
			if(fruit2==219)  
			{
				gotoxy2(21,22);
				cout<<"YOU WIN   NEXT LEVEL"<<endl;
				Sleep(2000);
				level3();  
							
				if(game3=true)
				{
					return 0; 
		    	}	  	
			}
			gotoxy2(43,5);
			cout<<"Fiber MAN"<<endl;
	    	gotoxy2(43,6);
			cout<<"CONSOLE GAME"<<endl;
			gotoxy2(43,7);
			cout<<"Life: "<<life2<<endl;
			gotoxy2(43,8);
			cout<<"Fiber Man  : "<<char(1)<<endl;
			gotoxy2(43,9);
			cout<<"Junk Food 1: "<< char(4) <<endl;
	    	gotoxy2(43,10);
			cout<<"Junk Food 1: "<< char(5) <<endl;
			gotoxy2(43,11);
			cout<<"Junk Food 1: "<< char(6) <<endl;
	}
    int getch(void);
}
