#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<string.h>
#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4
void textcolor(int fc,int bc=-1){
	if(fc<0 || fc>15)
		return;
	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	if(bc>=0 && bc<16)
		SetConsoleTextAttribute(h,fc|bc*16);
	else
		SetConsoleTextAttribute(h,fc);
}
void textcolor(char *fc,char *bc=""){
	int x,y=16;
	char *colors[]={"Black","Blue","reen","Aqua","Red","Purple","Yellow","White","Gray'"
	"LightBlue","LightGreen","LightAqua","LightRed","LightPurple","LightYellow","BrightWhite"};
	for(x=0;x<16;x++)
		if(strcmpi(colors[x],fc)==0)
			break;
	if(strlen(bc)>0)
		for(y=0;y<16;y++)
			if(strcmpi(colors[y],bc)==0)
				break;
	textcolor(x,y);
}
void textcolor(char *fc,int bc){
	int x;
	char *colors[]={"Black","Blue","Green","Aqua","Red","Purple","Yellow","White","Gray",
	"LightBlue","LightGreen","LightAqua","LightRed","LightPurple","LightYellow","BrightWhite"};
	for(x=0;x<16;x++)
		if(strcmpi(colors[x],fc)==0)
			break;
	textcolor(x,bc);
}
void textcolor(int fc,char *bc){
	int y;
	char *colors[]={"Black","Blue","Green","Aqua","Red","Purple","Yellow","White","Gray",
	"LightBlue","LightGreen","LightAqua","LightRed","LightPurple","LightYellow","BrightWhite"};
	if(strlen(bc)>0)
		for(y=0;y<16;y++)
			if(strcmpi(colors[y],bc)==0)
				break;
	textcolor(fc,y);
}
void gotoxy(int x, int y)
{
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
} 
void getup(){
	HANDLE hout; 
	CONSOLE_CURSOR_INFO cursor;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	cursor.dwSize=1;
	cursor.bVisible=false;
	SetConsoleCursorInfo(hout, &cursor);
	system("mode con:cols=80 lines=25");
	system("title Snake Game - www.youtube.com/projectcoding");
	system("cls");
	textcolor("LightPurple");
	printf("\n  %c",218);
	int x;
	for(x=0;x<75;x++)
		printf("%c",196);
	printf("%c  ",191);
	for(x=0;x<17;x++){
		gotoxy(2,x+2);
		printf("%c",179);
		gotoxy(78,x+2);
		printf("%c ",179);
	}
	printf("  %c",192);
	for(x=0;x<75;x++)
		printf("%c",196);
	printf("%c  ",217);
	printf(" %c",218);
	for(x=0;x<21;x++)
	printf("%c",196);
	printf("%c\n",191);
	printf("  %c S N A K E   G A M E %c\n",179,179);
	printf("  %c",192);
	for(x=0;x<21;x++)
		printf("%c",196);
	printf("%c",217);
	
	gotoxy(59,20);
	printf("%c",218);
	for(x=0;x<18;x++)
		printf("%c",196);
	printf("%c",191);
	gotoxy(59,21);
	printf("%c SCORE : 100      %c",179,179);
	gotoxy(59,22);
	printf("%c STATUS: Playing  %c",179,179);
	gotoxy(59,23);
	printf("%c",192);
	for(x=0;x<18;x++)
		printf("%c",196);
	printf("%c",217);
	gotoxy(28,20);
	printf("Press 'x' to Exit");
	gotoxy(28,21);
	printf("Press Space to Pause and Play");
	gotoxy(10,23);
	textcolor("white","blue");
	
	textcolor(7);
}
void score(int sc){
	gotoxy(69,21);
	printf("%6d",sc*10);
}
void status(char *s,int c=7){
	gotoxy(69,22);
	textcolor(c);
	int x;
	for(x=0;x<strlen(s);x++)
		printf("%c",s[x]);
	for(;x<8;x++)
		printf(" ");
	textcolor(7);
}
int main(){
	getup();
	register int flow,size,i,xb,yb;
	int speed,restart=1,tmp,xpos[100],ypos[100],scr;
	srand(time(NULL));
	while(true){
		if(restart){
			status("Playing",10);
			for(int k=1;k<75;k+=2)
				for(int j=0;j<17;j++){
					gotoxy(k+3,j+2);
					printf(" ");
				}
			size=5;	
			speed=200;
			scr=0;
			score(scr);
			flow=RIGHT;
			xpos[0]=20;
			for(i=0;i<size;i++){
				xpos[i]=xpos[0]-i*2;
				ypos[i]=10;
			}
			for(i=0;i<size;i++){
				gotoxy(xpos[i],ypos[i]);
				printf("o");
			}
			for(tmp=1;true;){
				do{
					xb=rand()%75+3;
				}while(xb%2!=0);
				yb=rand()%17+2;
				for(i=0;i<size;i++)
					if(xb==xpos[i] && yb==ypos[i]){
						tmp=0; break;
					}
				if(tmp)
					break;
			}
			gotoxy(xb,yb);
			textcolor("lightgreen");
			printf("@");
			textcolor(7);
			restart=0;
		}
		while(!kbhit() && !restart)	{
			if(xpos[0]==xb && ypos[0]==yb){
				for(tmp=1;true;){
					do{
						xb=rand()%75+3;
					}while(xb%2!=0);
					yb=rand()%17+2;
					for(i=0;i<size;i++)
						if(xb==xpos[i] && yb==ypos[i]){
							tmp=0; break;
						}
					if(tmp)
						break;
				}
				gotoxy(xb,yb);
				textcolor("lightgreen");
				printf("@");
				textcolor(7);
				size++;
				scr++;
				speed-=3;
				score(scr);
			}
			gotoxy(xpos[size-1],ypos[size-1]);
			for(i=size-1;i>0;i--){				
				xpos[i]=xpos[i-1];
				ypos[i]=ypos[i-1];
			}
			switch(flow){
				case RIGHT :xpos[i]+=2; break;
				case LEFT :	xpos[i]-=2; break;
				case UP :	ypos[i]-=1; break;
				case DOWN :	ypos[i]+=1; 
			}
			tmp=1;
			for(i=1;i<size;i++)
				if(xpos[i]==xpos[0] && ypos[i]==ypos[0]){
					tmp=0;
					break;
				}
			if(xpos[0]>76 || xpos[0]<4 || ypos[0]<2 ||ypos[0]>18)
				tmp=0;
			if(tmp){
				printf(" ");
				gotoxy(xpos[0],ypos[0]);
				printf("O");	
				gotoxy(xpos[1],ypos[1]);
				printf("o");	
			}
			else{
				textcolor("LIGHTRED");
				printf("o");
				gotoxy(xpos[1],ypos[1]);
				printf("O");
				for(i=2;i<size;i++){
					gotoxy(xpos[i],ypos[i]);
					printf("o");
				}
				textcolor(7);
				status("GameOver",12);
				restart=1;
				getch();
			}
			//delay(speed);
			Sleep(speed);
		}
		char ch=getch();
		switch(tolower(ch)){
			case 'x' : 	system("cls");
						return 0;
			case ' ' : status("Paused"); 
						while(true){
							char z=getch();
							if(z=='x')
								return 0;
							if(z==' ')
								break;
						}
						status("Playing",10);
						break;
			case -32: {
				char chh=getch();
				if(chh==72 && flow!=DOWN)
					flow=UP;
				else if(chh==80 && flow!=UP)
					flow=DOWN;
				else if(chh==75 && flow!=RIGHT)
					flow=LEFT;
				else if(chh==77 && flow!=LEFT)
					flow=RIGHT;
				break;
			}
		}
	}
}
