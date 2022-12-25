#include<iostream>     
#include<conio.h>
#include<windows.h>
#include "map2.h"
using namespace std;
void gotoxy(int x, int y)   
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x , y };
	SetConsoleCursorPosition(h, c);
}
bool game = true;
int main()
{
	system("color 3");  
	cout << "INSTRUCTION \n\n1: Press up arrow to move up\n";
	cout << "2: Press down arrow to move down \n3: Press left arrow to move left\n";
	cout << "4: Press right arrow to move right \n5: Avoid Junk Foods \n";
	cout << "6: Press ESC to leave during the game\n\n";
	cout << "As you progress towards next level the difficulty level will exced by decreasing 1 life in next level\n\n";
	char ch;                                    
	cout << "Press S(tart) \nPress E(nd):  ";
	cin >> ch;
	if (ch == 'E' || ch == 'e')
		return 0;
	else if (ch == 'S' || ch == 's')
	{
		int x = 1, y = 1;  
		int x1 = 20, y1 = 8; 
		int x2 = 21, y2 = 8;  
		int x3 = 16, y3 = 8;  
		int pacman = char(1);   
		int	enemy1 = char(4);   
		int enemy2 = char(5);  
		int enemy3 = char(6);  
		int Healthy_fruit_points = 0, life = 3;
		char w = 219;
		char map[500][500] = 
		{
			"#########################################",
			"# . . . . . . . . . # . . . . . . . . . #",
			"# . ##### . ##### . # . ##### . ##### . #",
			"# . . . . . . . . . . . . . . . . . . . #",
			"# . ##### . # . ######### . # . ##### . #",
			"# . . . . . ###  .  #  .  ### . . . . . #",
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
			"# . . . . . . . . . . . . . . . . . . . #",
			"#########################################",
		};
		int dir = 0, up = -1, down = -2, left = -3, right = -4; 
		int dir1 = 4, up1 = 4, down1 = 3, left1 = 2, right1 = 1;  
		int dir2 = 4; 
		int dir3 = 9;  
		system("color 3");
		int i;
		for (int k = 0; k <= 19; k++)     
			for (int j = 0; j <= 41; j++)
			{
				gotoxy(k, j);
				cout << ' ';
			}
		gotoxy(30, 17);
		cout << "Fiber Man ";
		gotoxy(20, 19);
		cout << "Loading";
		for (int k = 20; k <= 50; k++)
		{
			gotoxy(k, 20);
			cout << '.';
		}
		for (int k = 20; k <= 50; k++)
		{
			gotoxy(k, 20);
			cout << '<';
			Sleep(70);
			gotoxy(k, 20);
			cout << ' ';
		}
		while (game == true)  
		{
			Sleep(50); 
			system("cls");
			for (i = 0; i < 20; i++)  
			{
				cout << map[i] << endl;
			}
			for (int k = 0; k <= 19; k++)
				for (int j = 0; j <= 41; j++)
				{
					if (map[k][j] == '#')   
						map[k][j] = 219;
				}
			map[y][x] = pacman; 
			if (GetAsyncKeyState(VK_DOWN))  
			{
				dir = down;
				dir1 = rand() % 5 + 1;
				dir2 = rand() % 5 + 4;
				dir3 = rand() % 5 + 9;
			}
			if (GetAsyncKeyState(VK_UP))   
			{
				dir = up;
				dir1 = rand() % 5 + 1;
				dir2 = rand() % 5 + 4;
				dir3 = rand() % 5 + 9;
			}
			if (GetAsyncKeyState(VK_RIGHT))    
			{
				dir = right;
				dir1 = rand() % 5 + 1;
				dir2 = rand() % 5 + 4;
				dir3 = rand() % 5 + 9;
			}
			if (GetAsyncKeyState(VK_LEFT))   
			{
				dir = left;
				dir1 = rand() % 5 + 1;
				dir2 = rand() % 5 + 4;
				dir3 = rand() % 5 + 9;
			}
			if (GetAsyncKeyState(VK_ESCAPE)) 
			{
				game == false;
				cout << "Score: " << Healthy_fruit_points << endl;
				return 0;
			}
			if (dir == up)  
			{
				if (map[y - 1][x] == ' ' || map[y - 1][x] == '.' || map[y - 1][x] == enemy1 || map[y - 1][x] == enemy2 || map[y - 1][x] == enemy3)
				{
					map[y][x] = ' ';
					y--;
					map[y][x] = pacman;
				}
			}
			if (dir == down)  
			{
				if (map[y + 1][x] == ' ' || map[y + 1][x] == '.' || map[y + 1][x] == enemy1 || map[y + 1][x] == enemy2 || map[y + 1][x] == enemy3)
				{
					map[y][x] = ' ';
					y++;
					map[y][x] = pacman;
				}
			}
			if (dir == right)  
			{
				if (map[y][x + 1] == ' ' || map[y][x + 1] == '.' || map[y][x + 1] == enemy1 || map[y][x + 1] == enemy2 || map[y][x + 1] == enemy3)
				{
					map[y][x] = ' ';
					x++;
					map[y][x] = pacman;
				}
			}
			if (dir == left) 
			{
				if (map[y][x - 1] == ' ' || map[y][x - 1] == '.' || map[y][x - 1] == enemy1 || map[y][x - 1] == enemy2 || map[y][x - 1] == enemy3)
				{
					map[y][x] = ' ';
					x--;
					map[y][x] = pacman;
				}
			}
			if (x1 == 1 && y1 == 1) dir1 = rand() % 5 + 1; 
			if (x1 == 10 && y1 == 1) dir1 = rand() % 5 + 1;
			if (x1 == 19 && y1 == 1) dir1 = rand() % 5 + 1;
			if (x1 == 28 && y1 == 1) dir1 = rand() % 5 + 1;
			if (x1 == 37 && y1 == 1) dir1 = rand() % 5 + 1;
			if (x1 == 1 && y1 == 9) dir1 = rand() % 5 + 1;
			if (x1 == 10 && y1 == 9) dir1 = rand() % 5 + 1;
			if (x1 == 19 && y1 == 9) dir1 = rand() % 5 + 1;
			if (x1 == 28 && y1 == 9) dir1 = rand() % 5 + 1;
			if (x1 == 37 && y1 == 9) dir1 = rand() % 5 + 1;
			if (x1 == 1 && y1 == 14) dir1 = rand() % 5 + 1;
			if (x1 == 19 && y1 == 14) dir1 = rand() % 5 + 1;
			if (x1 == 37 && y1 == 14) dir1 = rand() % 5 + 1;
			if (x1 == 1 && y1 == 18) dir1 = rand() % 5 + 1;
			if (x1 == 1 && y1 == 14) dir1 = rand() % 5 + 1;
			if (x1 == 19 && y1 == 18) dir1 = rand() % 5 + 1;
			if (x1 == 37 && y1 == 18) dir1 = rand() % 5 + 1;

			if (x1 == x2 && y1 == y2)  
			{
				dir1 = rand() % 5 + 1;
				dir2 = rand() % 5 + 4;
				dir3 = rand() % 5 + 9;
			}
			if (x1 + 1 == x2 && y1 == y2) 
			{
				dir1 = rand() % 5 + 1;
				dir2 = rand() % 5 + 4;
				dir3 = rand() % 5 + 9;
			}
			if (x1 - 1 == x2 && y1 == y2)  
			{
				dir1 = rand() % 5 + 1;
				dir2 = rand() % 5 + 4;
				dir3 = rand() % 5 + 9;
			}
			if (x1 == x2 && y1 + 1 == y2)  
			{
				dir1 = rand() % 5 + 1;
				dir2 = rand() % 5 + 4;
				dir3 = rand() % 5 + 9;
			}
			if (x1 == x2 && y1 - 1 == y2)  
			{
				dir1 = rand() % 5 + 1;
				dir2 = rand() % 5 + 4;
				dir3 = rand() % 5 + 9;
			}
			if (x1 == x3 && y1 == y3)  
			{
				dir1 = rand() % 5 + 1;
				dir2 = rand() % 5 + 4;
				dir3 = rand() % 5 + 9;
			}
			if (x1 + 1 == x3 && y1 == y3) 
			{
				dir1 = rand() % 5 + 1;
				dir2 = rand() % 5 + 4;
				dir3 = rand() % 5 + 9;
			}
			if (x1 - 1 == x3 && y1 == y3)  
			{
				dir1 = rand() % 5 + 1;
				dir2 = rand() % 5 + 4;
				dir3 = rand() % 5 + 9;
			}
			if (x1 == x3 && y1 + 1 == y3) 
			{
				dir1 = rand() % 5 + 1;
				dir2 = rand() % 5 + 4;
				dir3 = rand() % 5 + 9;
			}
			if (x1 == x3 && y1 - 1 == y3)  
			{
				dir1 = rand() % 5 + 1;
				dir2 = rand() % 5 + 4;
				dir3 = rand() % 5 + 9;
			}
			if (x2 == x3 && y2 == y3)  
			{
				dir1 = rand() % 5 + 1;
				dir2 = rand() % 5 + 4;
				dir3 = rand() % 5 + 9;
			}
			if (x2 + 1 == x3 && y2 == y3) 
			{
				dir1 = rand() % 5 + 1;
				dir2 = rand() % 5 + 4;
				dir3 = rand() % 5 + 9;
			}
			if (x2 - 1 == x3 && y2 == y3)  
			{
				dir1 = rand() % 5 + 1;
				dir2 = rand() % 5 + 4;
				dir3 = rand() % 5 + 9;
			}
			if (x2 == x3 && y2 + 1 == y3)  
			{
				dir1 = rand() % 5 + 1;
				dir2 = rand() % 5 + 4;
				dir3 = rand() % 5 + 9;
			}
			if (x2 == x3 && y2 - 1 == y3)  
			{
				dir1 = rand() % 5 + 1;
				dir2 = rand() % 5 + 4;
				dir3 = rand() % 5 + 9;
			}
			if (dir1 == up1)  
			{
				if (map[y1 - 1][x1] == ' ' || map[y1 - 1][x1] == pacman)
				{
					map[y1][x1] = ' ';
					y1--;
					map[y1][x1] = enemy1;
				}
				if (map[y1 - 1][x1] == '.' || map[y1 - 1][x1] == pacman)
				{
					map[y1][x1] = '.';
					y1--;
					map[y1][x1] = enemy1;
				}
			}
			if (dir1 == down1)  
			{
				if (map[y1 + 1][x1] == ' ' || map[y1 + 1][x1] == pacman)
				{
					map[y1][x1] = ' ';
					y1++;
					map[y1][x1] = enemy1;
				}
				if (map[y1 + 1][x1] == '.' || map[y1 + 1][x1] == pacman)
				{
					map[y1][x1] = '.';
					y1++;
					map[y1][x1] = enemy1;
				}
			}
			if (dir1 == left1)  
			{
				if (map[y1][x1 - 1] == ' ' || map[y1][x1 - 1] == pacman)
				{
					map[y1][x1] = ' ';
					x1--;
					map[y1][x1] = enemy1;
				}
				if (map[y1][x1 - 1] == '.' || map[y1][x1 - 1] == pacman)
				{
					map[y1][x1] = '.';
					x1--;
					map[y1][x1] = enemy1;
				}
			}
			if (dir1 == right1)  
			{
				if (map[y1][x1 + 1] == ' ' || map[y1][x1 + 1] == pacman)
				{
					map[y1][x1] = ' ';
					x1++;
					map[y1][x1] = enemy1;
				}
				if (map[y1][x1 + 1] == '.' || map[y1][x1 + 1] == pacman)
				{
					map[y1][x1] = '.';
					x1++;
					map[y1][x1] = enemy1;
				}
			}
			if (x2 == 1 && y2 == 1) dir2 = rand() % 5 + 5;  
			if (x2 == 10 && y2 == 1) dir2 = rand() % 5 + 5;
			if (x2 == 19 && y2 == 1) dir2 = rand() % 5 + 5;
			if (x2 == 28 && y2 == 1) dir2 = rand() % 5 + 5;
			if (x2 == 37 && y2 == 1) dir2 = rand() % 5 + 5;
			if (x2 == 1 && y2 == 9) dir2 = rand() % 5 + 5;
			if (x2 == 10 && y2 == 9) dir2 = rand() % 5 + 5;
			if (x2 == 19 && y2 == 9) dir2 = rand() % 5 + 5;
			if (x2 == 28 && y2 == 9) dir2 = rand() % 5 + 5;
			if (x2 == 37 && y2 == 9) dir2 = rand() % 5 + 5;
			if (x2 == 1 && y2 == 14) dir2 = rand() % 5 + 5;
			if (x2 == 19 && y2 == 14) dir2 = rand() % 5 + 5;
			if (x2 == 37 && y2 == 14) dir2 = rand() % 5 + 5;
			if (x2 == 1 && y2 == 18) dir2 = rand() % 5 + 5;
			if (x2 == 1 && y2 == 14) dir2 = rand() % 5 + 5;
			if (x2 == 19 && y2 == 18) dir2 = rand() % 5 + 5;
			if (x2 == 37 && y2 == 18) dir2 = rand() % 5 + 5;

			if (dir1 == down1)  
			{
				if (map[y2 - 1][x2] == ' ' || map[y2 - 1][x2] == pacman)
				{
					map[y2][x2] = ' ';
					y2--;
					map[y2][x2] = enemy2;
				}
				if (map[y2 - 1][x2] == '.' || map[y2 - 1][x2] == pacman)
				{
					map[y2][x2] = '.';
					y2--;
					map[y2][x2] = enemy2;
				}
			}
			if (dir1 == up1) 
			{
				if (map[y2 + 1][x2] == ' ' || map[y2 + 1][x2] == pacman)
				{
					map[y2][x2] = ' ';
					y2++;
					map[y2][x2] = enemy2;
				}
				if (map[y2 + 1][x2] == '.' || map[y2 + 1][x2] == pacman)
				{
					map[y2][x2] = '.';
					y2++;
					map[y2][x2] = enemy2;
				}
			}
			if (dir1 == left1)  
			{
				if (map[y2][x2 + 1] == ' ' || map[y2][x2 + 1] == pacman)
				{
					map[y2][x2] = ' ';
					x2++;
					map[y2][x2] = enemy2;
				}
				if (map[y2][x2 + 1] == '.' || map[y2][x2 + 1] == pacman)
				{
					map[y2][x2] = '.';
					x2++;
					map[y2][x2] = enemy2;
				}
			}
			if (dir1 == right1)  
			{
				if (map[y2][x2 - 1] == ' ' || map[y2][x2 - 1] == pacman)
				{
					map[y2][x2] = ' ';
					x2--;
					map[y2][x2] = enemy2;
				}
				if (map[y2][x2 - 1] == '.' || map[y2][x2 - 1] == pacman)
				{
					map[y2][x2] = '.';
					x2--;
					map[y2][x2] = enemy2;
				}
			}
			if (x3 == 1 && y3 == 1) dir3 = rand() % 5 + 9;  
			if (x3 == 10 && y3 == 1) dir3 = rand() % 5 + 9;
			if (x3 == 19 && y3 == 1) dir3 = rand() % 5 + 9;
			if (x3 == 28 && y3 == 1) dir3 = rand() % 5 + 9;
			if (x3 == 37 && y3 == 1) dir3 = rand() % 5 + 9;
			if (x3 == 1 && y3 == 9) dir3 = rand() % 5 + 9;
			if (x3 == 10 && y3 == 9) dir3 = rand() % 5 + 9;
			if (x3 == 19 && y3 == 9) dir3 = rand() % 5 + 9;
			if (x3 == 28 && y3 == 9) dir3 = rand() % 5 + 9;
			if (x3 == 37 && y3 == 9) dir3 = rand() % 5 + 9;
			if (x3 == 1 && y3 == 14) dir3 = rand() % 5 + 9;
			if (x3 == 19 && y3 == 14) dir3 = rand() % 5 + 9;
			if (x3 == 37 && y3 == 14) dir3 = rand() % 5 + 9;
			if (x3 == 1 && y3 == 18) dir3 = rand() % 5 + 9;
			if (x3 == 1 && y3 == 14) dir3 = rand() % 5 + 9;
			if (x3 == 19 && y3 == 18) dir3 = rand() % 5 + 9;
			if (x3 == 37 && y3 == 18) dir3 = rand() % 5 + 9;

			if (dir1 == down1)  
			{
				if (map[y3 - 1][x3] == ' ' || map[y3 - 1][x3] == pacman)
				{
					map[y3][x3] = ' ';
					y3--;
					map[y3][x3] = enemy3;
				}
				if (map[y3 - 1][x3] == '.' || map[y3 - 1][x3] == pacman)
				{
					map[y3][x3] = '.';
					y3--;
					map[y3][x3] = enemy3;
				}
			}
			if (dir1 == up1)  
			{
				if (map[y3 + 1][x3] == ' ' || map[y3 + 1][x3] == pacman)
				{
					map[y3][x3] = ' ';
					y3++;
					map[y3][x3] = enemy3;
				}
				if (map[y3 + 1][x3] == '.' || map[y3 + 1][x3] == pacman)
				{
					map[y3][x3] = '.';
					y3++;
					map[y3][x3] = enemy3;
				}
			}
			if (dir1 == left1)  
			{
				if (map[y3][x3 + 1] == ' ' || map[y3][x3 + 1] == pacman)
				{
					map[y3][x3] = ' ';
					x3++;
					map[y3][x3] = enemy3;
				}
				if (map[y3][x3 + 1] == '.' || map[y3][x3 + 1] == pacman)
				{
					map[y3][x3] = '.';
					x3++;
					map[y3][x3] = enemy3;
				}
			}
			if (dir1 == right1)  
			{
				if (map[y3][x3 - 1] == ' ' || map[y3][x3 - 1] == pacman)
				{
					map[y3][x3] = ' ';
					x3--;
					map[y3][x3] = enemy3;
				}
				if (map[y3][x3 - 1] == '.' || map[y3][x3 - 1] == pacman)
				{
					map[y3][x3] = '.';
					x3--;
					map[y3][x3] = enemy3;
				}
			}
			if (map[y][x] == ' ' || map[y1][x1] == ' ' || map[y2][x2] == ' ' || map[y3][x3] == ' ' || map[y][x] == enemy1 || map[y][x] == enemy2 || map[y][x] == enemy3)
			{
				if (pacman == char(1))
				{
					life--;
					if (life == 0)   
					{
						cout << "YOU LOSE" << endl;
						cout << "FINAL SCORE: " << Healthy_fruit_points << endl;
						return 0;
					}
				}
			}
			if (map[y + 1][x] == '.')  
			{
				map[y + 1][x] = ' ';
				Healthy_fruit_points++;
			}
			if (map[y - 1][x] == '.')  
			{
				map[y - 1][x] = ' ';
				Healthy_fruit_points++;
			}
			if (map[y][x + 1] == '.')  
			{
				map[y][x + 1] = ' ';
				Healthy_fruit_points++;
			}
			if (map[y][x - 1] == '.')  
			{
				map[y][x - 1] = ' ';
				Healthy_fruit_points++;
			}
			gotoxy(43, 3);
			cout << "Healthy Fruit Points : " << Healthy_fruit_points << endl; 
			if (Healthy_fruit_points == 194)  
			{
				gotoxy(21, 22);
				cout << "YOU WIN    NEXT LEVEL" << endl;
				Sleep(2000);
				level2();  
				if (game2 = true)  
				{
					return 0;
				}
			}
			gotoxy(43, 5);
			cout << "Fiber MAN" << endl;
			gotoxy(43, 6);
			cout << "CONSOLE GAME" << endl;
			gotoxy(43, 7);
			cout << "Life: " << life << endl;
			gotoxy(43, 8);
			cout << "Fiber Man  : " << char(1) << endl;
			gotoxy(43, 9);
			cout << "Junk Food 1: " << char(4) << endl;
			gotoxy(43, 10);
			cout << "Junk Food 2: " << char(5) << endl;
			gotoxy(43, 11);
			cout << "Junk Food 3: " << char(6) << endl;
		}
		int getch(void); 
	}
	else
		cout << "ERROR" << endl;
}
