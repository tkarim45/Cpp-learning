/*

Abdul Sabbor
L20-1113
BDS-A1


This program works as following
	game starts with a graphical dispplay
	game proceeds and displays playing instructions
	when user hits space bar gameplay begins, pressing escape key after instructions exits from game
		gameplay consists of a space ship shooting bombs when user hits spacebar
		when bomb hit blocks of debris, score is increased according to te color of blocks
		if block hits ship, user looses one life
		when user loose all lives he loses th game
			user has to start again from level 1
			
		if user's score surpass (level no * 10), user proceeds to net level 
			more frequent space blocks
			faster gameplay
		
		when user completes all 5 levels, user wins the game and has an option to restart from levl 1

some features of game
	following are displayed in gameplay in a side panel
		game graphics
		level number
		total score of level 
		remaining lives
	
	block and colors are generated randomly
		there are four colors with each having specific increas in score
	there may be a random brick in each game which increases life count if life critically low
	when level increases, user win game, user lose game
		a prompt is shown with appropriate message along with total score of game
*/

#include<iostream>
#include<windows.h>
#include<conio.h>
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); // handle for colors
using namespace std;
// Global Variables
#define win_height 20
#define win_width 20
int total=0; // total score of each level
int game_total=0; // total High score of game
int ship_pos=(win_width/2); // ship position in array
int win=0; // variable if player wins
int lose=0; // variable if player loses
int life =3; // life count
int level = 1; // level
int Life_c=(rand()%10); // random number to increase life

//--------------------

// Array

int back[win_height][win_width]; // Defining of game array

//--------------

// Functions

void menu(); // Displaying Menu
void instructions(); // Dispaly Instructions
void prnt(); // Printing Array
void move_up(); // moving ball up
void move_down(); // shifting array down
void gen_row(); // generating random blocks
void lost(); // Game lose function
void won(); // Game win Function
void level_up(); // Level Up function
void play(); // main playing function


//---------------

int main()
{

// This is the scoring scheme

	// 7 is white color
	// 3 is blue color
	// 4 is red color
	// 2 is green color
	
	// 1 is 7 and adds 1
	// 2 is 2 and adds 2
	// 3 is 3 and adds 3
	// 4 is 4 and adds 4
	
	menu();
	system("pause");



}

void menu() // function to display start up graphics
{
	// Changing console color and displaying startup
	SetConsoleTextAttribute(hStdOut, 2); 
	system("cls");
	cout<<endl<<endl<<endl;
	cout<<"           .................................................."<<endl;
	cout<<"           .................................................."<<endl;
	cout<<"           . .                                 "<<char(254)<<"          . ."<<endl;
	cout<<"           . .                                            . ."<<endl;
	cout<<"           . .                                            . ."<<endl;
	cout<<"           . .                Space Shooter               . ."<<endl;
	cout<<"           . .                                            . ."<<endl;
	cout<<"           . .                                            . ."<<endl;
	cout<<"           . .                                 "<<char(15)<<"          . ."<<endl;
	cout<<"           . .                                 "<<char(202)<<"          . ."<<endl;
	cout<<"           .................................................."<<endl;
	cout<<"           .................................................."<<endl;
	cout<<endl<<endl;
	Sleep(100);
	
	SetConsoleTextAttribute(hStdOut, 3);
	system("cls");
	cout<<endl<<endl<<endl;
	cout<<"           .................................................."<<endl;
	cout<<"           .................................................."<<endl;
	cout<<"           . .                                 "<<char(254)<<"          . ."<<endl;
	cout<<"           . .                                            . ."<<endl;
	cout<<"           . .                                            . ."<<endl;
	cout<<"           . .                Space Shooter               . ."<<endl;
	cout<<"           . .                                            . ."<<endl;
	cout<<"           . .                                 "<<char(15)<<"          . ."<<endl;
	cout<<"           . .                                            . ."<<endl;
	cout<<"           . .                                 "<<char(202)<<"          . ."<<endl;
	cout<<"           .................................................."<<endl;
	cout<<"           .................................................."<<endl;
	cout<<endl<<endl;
	Sleep(100);
	
	SetConsoleTextAttribute(hStdOut, 4);
	system("cls");
	cout<<endl<<endl<<endl;
	cout<<"           .................................................."<<endl;
	cout<<"           .................................................."<<endl;
	cout<<"           . .                                 "<<char(254)<<"          . ."<<endl;
	cout<<"           . .                                            . ."<<endl;
	cout<<"           . .                                            . ."<<endl;
	cout<<"           . .                Space Shooter               . ."<<endl;
	cout<<"           . .                                 "<<char(15)<<"          . ."<<endl;
	cout<<"           . .                                            . ."<<endl;
	cout<<"           . .                                            . ."<<endl;
	cout<<"           . .                                 "<<char(202)<<"          . ."<<endl;
	cout<<"           .................................................."<<endl;
	cout<<"           .................................................."<<endl;
	cout<<endl<<endl;
	Sleep(100);
	
	SetConsoleTextAttribute(hStdOut, 2);
	system("cls");
	cout<<endl<<endl<<endl;
	cout<<"           .................................................."<<endl;
	cout<<"           .................................................."<<endl;
	cout<<"           . .                                 "<<char(254)<<"          . ."<<endl;
	cout<<"           . .                                            . ."<<endl;
	cout<<"           . .                                            . ."<<endl;
	cout<<"           . .                Space Shooter    "<<char(15)<<"          . ."<<endl;
	cout<<"           . .                                            . ."<<endl;
	cout<<"           . .                                            . ."<<endl;
	cout<<"           . .                                            . ."<<endl;
	cout<<"           . .                                 "<<char(202)<<"          . ."<<endl;
	cout<<"           .................................................."<<endl;
	cout<<"           .................................................."<<endl;
	cout<<endl<<endl;
	Sleep(100);
	
	SetConsoleTextAttribute(hStdOut, 3);
	system("cls");
	cout<<endl<<endl<<endl;
	cout<<"           .................................................."<<endl;
	cout<<"           .................................................."<<endl;
	cout<<"           . .                                 "<<char(254)<<"          . ."<<endl;
	cout<<"           . .                                            . ."<<endl;
	cout<<"           . .                                 "<<char(15)<<"          . ."<<endl;
	cout<<"           . .                Space Shooter               . ."<<endl;
	cout<<"           . .                                            . ."<<endl;
	cout<<"           . .                                            . ."<<endl;
	cout<<"           . .                                            . ."<<endl;
	cout<<"           . .                                 "<<char(202)<<"          . ."<<endl;
	cout<<"           .................................................."<<endl;
	cout<<"           .................................................."<<endl;
	cout<<endl<<endl;
	Sleep(100);
	
	SetConsoleTextAttribute(hStdOut, 4);
	system("cls");
	cout<<endl<<endl<<endl;
	cout<<"           .................................................."<<endl;
	cout<<"           .................................................."<<endl;
	cout<<"           . .                                 "<<char(254)<<"          . ."<<endl;
	cout<<"           . .                                 "<<char(15)<<"          . ."<<endl;
	cout<<"           . .                                            . ."<<endl;
	cout<<"           . .                Space Shooter               . ."<<endl;
	cout<<"           . .                                            . ."<<endl;
	cout<<"           . .                                            . ."<<endl;
	cout<<"           . .                                            . ."<<endl;
	cout<<"           . .                                 "<<char(202)<<"          . ."<<endl;
	cout<<"           .................................................."<<endl;
	cout<<"           .................................................."<<endl;
	cout<<endl<<endl;
	Sleep(500);
	
	SetConsoleTextAttribute(hStdOut, 7); // canging color back to white
	
	instructions(); // Instructions to display
	
} // end of function

void instructions() // function to diplay instructions
{
	// Dispalying instructions to user with some time delay
	system("cls");
	cout<<endl<<endl<<endl<<endl;
	cout<<"                    I N S T R U C T I O N S"<<endl<<endl;
	Sleep(500);
	cout<<"            use ( arrow keys / A or D ) to move around  "<<endl<<endl;
	cout<<"            press space to fire bullets         "<<endl<<endl;
	cout<<"            avoid hitting space debris          "<<endl<<endl;
	cout<<"            different colored debris gives different score"<<endl<<endl;
	cout<<"            esc key during game restarts level          "<<endl<<endl<<endl;
	Sleep(1500);
	cout<<endl<<"                Press Space key to Start Level "<<level<<endl;
	cout<<endl<<"                Press Esc key to Exit "<<level<<endl;
	
	char ch = getch();
	
	if ( ch==32 ) // condition for starting game
	{
		game_total=0;
		play(); // calling play function
	}
	if ( ch==27) // condition for exiting game
	{ 
		exit(1); // exiting game
	}	
} // End of function

void play() // function to start playing
{
	// Generating an empty array
	for(int c=0;c<win_height;c++)
	{
		for(int i=0;i<win_width;i++)
		{
			back[c][i]=0;
		}
	} // end of array generation
	
	
	back[win_height-1][ship_pos]=6; // Placing space ship into position
	
	lose=0;win=0;life=3; // value of variables to be used in program
	
	int flag = 0; // Flag for win or lose
	
	// Loop for repeating game
	for(int c=0;flag!=1;c++)
	{
		system("cls");
		prnt(); // printing array
		Sleep(70-(level*10)); // Time delay
		move_down(); // shifting elements down
		
		// validation if gameplay should be halted
		if (total>=(level*10))
		{
		  	if (level<5)
			  level_up();
			else
			  won();
		}
		if(win==1||lose==1)
		{
			flag=1;
			system("cls");
			if (lose==1)
			{lost();
			}
			instructions();
		}
		// end of validation
		
		
		move_up(); // shifting bomb up
		
		// COndition to call generating function
		if (c%(level*(6-level))==0)
		gen_row(); // row being generated
		// end of condition
		
		// function to check if key is pressed to perform desired action
		if (kbhit()){
			char ch = getch();
			if ( ch=='d'||ch=='D'||ch==77) // shifting ship right
			{
				if (ship_pos<win_width-1)
				{
				back[win_height-1][ship_pos+1]=back[win_height-1][ship_pos];
				back[win_height-1][ship_pos]=0;
				ship_pos+=1;
				}
			}
			if ( ch=='a'||ch=='A'||ch==75) // shifting ship left
			{
				if (ship_pos>0)
				{
				back[win_height-1][ship_pos-1]=back[win_height-1][ship_pos];
				back[win_height-1][ship_pos]=0;
				ship_pos-=1;
				}
			}
			if ( ch==32 ) // condition for firing bomb
			{
				back[win_height-2][ship_pos]=5;
			}
			if ( ch==27) // condition for restarting level
			{ 
				Sleep(2000);
				instructions();
			}
		}
		}
} // End of function

void prnt() // function to print array
{
	cout<<"\n\n\n\n"<<"               ";
	for (int x=0;x<=(win_width*2)+21;x++)
	{
		cout<<char(177);
	}
	cout<<endl;
	// Printing First row
	
	// Printing array
	for(int c=0;c<win_height;c++)
	{
		cout<<"               "<<char(177)<<char(177)<<" ";
		// First Column printed
		
		// Printing of objects according to integer values
		for(int i=0;i<win_width;i++)
		{
			switch (back[c][i])
			{
			case 0: // Empty space
			{
				cout << " " << " "; break;
			}
			case 1: // White Brick
			{
				cout << char(254) << " "; break;
			}
			case 2: // Green Brick
			{
				SetConsoleTextAttribute(hStdOut, 2);
				cout<<char(254)<<" "; 
				SetConsoleTextAttribute(hStdOut, 7);
				break;
			}
			case 3: // Blue Brick
			{
				SetConsoleTextAttribute(hStdOut, 3);
				cout<<char(254)<<" "; 
				SetConsoleTextAttribute(hStdOut, 7);
				break;
			}
			case 4: // Red Brick
			{
				SetConsoleTextAttribute(hStdOut, 4);
				cout<<char(254)<<" "; 
				SetConsoleTextAttribute(hStdOut, 7);
				break;
			}
			case 5: // Bomb
			{
				cout<<char(15)<<" "; break;
			}
			case 6: // Space ship
			{
				cout<<char(202)<<" ";
				break;
			}
			case 9: // Life
			{
				cout<<char(240)<<" "; break;
			}
			};
		}
		switch(c)
		{
			case 2:
			{
				cout<<char(177)<<char(177)<<"   S P "<<char(202)<<" C E   "<<char(177)<<char(177)<<endl;
				break;
			}
			case 4:
			{
				cout<<char(177)<<char(177)<<" S H O O T E R "<<char(177)<<char(177)<<endl;
				break;
			}
			case 6:
			{
				for (int x=0;x<19;x++)
				{
					cout<<char(177);
				}
				cout<<endl;
				break;
			}
			case 8:
			{
				cout<<char(177)<<char(177)<<"    Level "<<level<<"    "<<char(177)<<char(177)<<endl;
				break;
			}
			case 10:
			{
				for (int x=0;x<19;x++)
				{
					cout<<char(177);
				}
				cout<<endl;
				break;
			}
			case 14:
			{
				if(total<10){
					cout<<char(177)<<char(177)<<"  SCORE = 00"<<total<<"  "<<char(177)<<char(177)<<endl;
				}
				else
				{
					cout<<char(177)<<char(177)<<"  SCORE = 0"<<total<<"  "<<char(177)<<char(177)<<endl;
				}
				break;
			}
			case 16:
			{
				cout<<char(177)<<char(177)<<"   LIVES = "<<life<<"   "<<char(177)<<char(177)<<endl;
				break;
			}
		
		default:
			{
			cout<<char(177)<<char(177)<<"               "<<char(177)<<char(177)<<endl; // Last Column
			break;
			}
		};
	}
	
	// Printing of last Row
	cout<<"               ";
	for (int x=0;x<=(win_width*2)+21;x++)
	{
		cout<<char(177);
	}
	cout<<endl;
} // End of printing function

void move_down() // Function to shift array down
{
	for (int c=(win_height-1);c>0;c--) // Loop for rows
	{
		for (int i=0;i<win_width;i++) // Loop for Columns
		{
			// Validation condition to decerease life count or lose game
			if (c==(win_height-2) && i==ship_pos && (back[c][i]==1 || back[c][i]==2 || back[c][i]==3 || back[c][i]==4 || back[c][i]==9))
			{
			if( life>1) // Condition for decreasing life
			life--;
			
			else
			lose=1; // condition for losing game
			}
			// End detection
			
			// Validation condition to detect collision of bullet with block and score increased according to block value
			if (back[c][i] == 5)
			{
				//checking for each block separately
				if (back[c-1][i]==1)
				{
					back[c][i]=0;
					back[c-1][i]=0;
					total++;
					game_total++;
				}
				if (back[c-1][i]==2)
				{
					back[c][i]=0;
					back[c-1][i]=0;
					total+=2;
					game_total+=2;
				}
				if (back[c-1][i]==3)
				{
					back[c][i]=0;
					back[c-1][i]=0;
					total+=3;
					game_total+=3;
				}
				if (back[c-1][i]==4)
				{
					back[c][i]=0;
					back[c-1][i]=0;
					total+=4;
					game_total+=4;
				}
				if (back[c-1][i]==9)
				{
					back[c][i]=0;
					back[c-1][i]=0;
					life++;
				}
			} // end of validation
			
			else if (back[c - 1][i] == 5); // to skip shifting down bullet
			else if (back[c][i]==6); // to skip shifting down ship
			
			else // shipting down all remaining blocks
			back[c][i]=back[c-1][i];
			
		}
	} // end of loop
	
	// Initialising First row with empty spaces
	for(int c=0;c<win_width;c++)
	{
		back[0][c]=0;
	}
} // end of function

void gen_row() // function to shift arrray down
{
	int count=(rand()%(win_width)); // geenrating a random column number
	
	if ((rand()==rand()) && (life<2) && (Life_c<1)) // validation if life should be given
	{back[0][count]=9;
	Life_c++;
	}
	
	else // printing of one of four colors
	back[0][count]=(rand()%5);
} // end of function

void move_up() // function to move up bomb
{
	for (int c=0;c<win_height;c++) // Loop for Rows
	{
		for (int i=0;i<(win_width-1);i++) // Loop for Columns
		{
			if (back[c+1][i]==5) // validation if array element is bomb
			{
				switch (back[c][i]) // reading element above bomb
				{   
					case 0: // no action if empty
						{
							back[c+1][i]=0;
							back[c][i]=5;
							break;
						}
						
					// Specific increase in score according to block type
					case 1:
						{
							back[c][i]=0;
							back[c+1][i]=0;
							total++;
							game_total++;
							break;
						}
					case 2:
						{
							back[c][i]=0;
							back[c+1][i]=0;
							total+=2;
							game_total+=2;
							break;
						}
					case 3:
						{
							back[c][i]=0;
							back[c+1][i]=0;
							total+=3;
							game_total+=3;
							break;
						}
					case 4:
						{
							back[c][i]=0;
							back[c+1][i]=0;
							total+=4;
							game_total+=4;
							break;
						}
					// end of scoring
					
					case 9: // increasing life if ball hits life brick
						{
							back[c][i]=0;
							back[c+1][i]=0;
							life++;
							break;
						}
				}
			}			
		}
	}
} // end of function

void lost() // function for prompt if user losses the game
{
	total=0;
	system("cls");
	cout<<"\n\n\n\n";
	cout<<"               "<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<endl;
	cout<<"               "<<char(177)<<char(177)<<"                "<<char(177)<<char(177)<<endl;
	cout<<"               "<<char(177)<<char(177)<<"    You Lost    "<<char(177)<<char(177)<<endl;
	cout<<"               "<<char(177)<<char(177)<<"                "<<char(177)<<char(177)<<endl;
	if(game_total<10)
	cout<<"               "<<char(177)<<char(177)<<"   Total = "<<game_total<<"    "<<char(177)<<char(177)<<endl;
	else if ((game_total>9)&&(game_total<100))
	cout<<"               "<<char(177)<<char(177)<<"   Total = "<<game_total<<"   "<<char(177)<<char(177)<<endl;
	else if (game_total>99)
	cout<<"               "<<char(177)<<char(177)<<"   Total = "<<game_total<<"  "<<char(177)<<char(177)<<endl;
	cout<<"               "<<char(177)<<char(177)<<"                "<<char(177)<<char(177)<<endl;
	cout<<"               "<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<endl;
	Sleep(2000);
	cout<<endl<<endl<<"           Press any key to go to Menu       "<<endl;
	game_total=0;
	getch();
	instructions();
} // end of function

void won() // function for prompt if user wins the game
{
	system("cls");
	cout<<"\n\n\n\n";
	cout<<"               "<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<endl;
	cout<<"               "<<char(177)<<char(177)<<"                "<<char(177)<<char(177)<<endl;
	cout<<"               "<<char(177)<<char(177)<<"    You Won     "<<char(177)<<char(177)<<endl;
	cout<<"               "<<char(177)<<char(177)<<"                "<<char(177)<<char(177)<<endl;
	if(game_total<10)
	cout<<"               "<<char(177)<<char(177)<<"   Total = "<<game_total<<"    "<<char(177)<<char(177)<<endl;
	else if ((game_total>9)&&(game_total<100))
	cout<<"               "<<char(177)<<char(177)<<"   Total = "<<game_total<<"   "<<char(177)<<char(177)<<endl;
	else if (game_total>99)
	cout<<"               "<<char(177)<<char(177)<<"   Total = "<<game_total<<"  "<<char(177)<<char(177)<<endl;
	cout<<"               "<<char(177)<<char(177)<<"                "<<char(177)<<char(177)<<endl;
	cout<<"               "<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<endl;
	Sleep(2000);
	cout<<endl<<endl<<"           Press any key to go to Menu       "<<endl;
	game_total=0;
	level=1; // setting level to begining
	
	getch();
	instructions(); // going to instructions
} // end of function

void level_up() // function for prompt when level is increased
{
	level++; // increasing level
	life=3; // setting lif count
	total=0; // setting total score
	system("cls");
	cout<<"\n\n\n\n";
	cout<<"               "<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<endl;
	cout<<"               "<<char(177)<<char(177)<<"                "<<char(177)<<char(177)<<endl;
	cout<<"               "<<char(177)<<char(177)<<"    Level Up    "<<char(177)<<char(177)<<endl;
	cout<<"               "<<char(177)<<char(177)<<"                "<<char(177)<<char(177)<<endl;
	cout<<"               "<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<endl;
	Sleep(2000);
	cout<<endl<<endl<<"        Press any key to go to Next Level       "<<endl;
	getch();
	play();
} // end of function

// End of program
