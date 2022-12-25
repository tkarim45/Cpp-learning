#include<iostream>
using namespace std;
char matrix[3][3] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char Player = 'X';
void Draw()
{
	system("cls");
	cout <<"\t" << "Tic Tac Toe Game " << endl << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "\t" << endl;
		for (int j = 0; j < 3; j++)
		{
			cout <<"\t"<< matrix[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl << endl;
}
void Input()
{
	int a;
	cout << "Player " << Player << " Turn " << endl << endl;
	cout << "Press he Number of the Field: "; cin >> a;
	if (a == 1)
		matrix[0][0] = Player;
	else if (a == 2)
		matrix[0][1] = Player;
	else if (a == 3)
		matrix[0][2] = Player;
	else if (a == 4)
		matrix[1][0] = Player;
	else if (a == 5)
		matrix[1][1] = Player;
	else if (a == 6)
		matrix[1][2] = Player;
	else if (a == 7)
		matrix[2][0] = Player;
	else if (a == 8)
		matrix[2][1] = Player;
	else if (a == 9)
		matrix[2][2] = Player;	
}
void TogglePlayer()
{
	if (Player == 'X')
		Player = 'O';
	else
		Player = 'X';
}
char win()
{
	//First Player
	if (matrix[0][0] == 'X' && matrix[0][1] == 'X' && matrix[0][2] == 'X')
		return 'X';
	if (matrix[1][0] == 'X' && matrix[1][1] == 'X' && matrix[1][2] == 'X')
		return 'X';
	if (matrix[2][0] == 'X' && matrix[2][1] == 'X' && matrix[2][2] == 'X')
		return 'X';
	if (matrix[0][0] == 'X' && matrix[1][0] == 'X' && matrix[2][0] == 'X')
		return 'X';
	if (matrix[0][1] == 'X' && matrix[1][1] == 'X' && matrix[2][1] == 'X')
		return 'X';
	if (matrix[0][2] == 'X' && matrix[1][2] == 'X' && matrix[2][2] == 'X')
		return 'X';
	if (matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X')
		return 'X';
	if (matrix[2][0] == 'X' && matrix[1][1] == 'X' && matrix[0][2] == 'X')
		return 'X';
	//Second Player
	if (matrix[0][0] == 'O' && matrix[0][1] == 'O' && matrix[0][2] == 'O')
		return 'O';
	if (matrix[1][0] == 'O' && matrix[1][1] == 'O' && matrix[1][2] == 'O')
		return 'O';
	if (matrix[2][0] == 'O' && matrix[2][1] == 'O' && matrix[2][2] == 'O')
		return 'O';
	if (matrix[0][0] == 'O' && matrix[1][0] == 'O' && matrix[2][0] == 'O')
		return 'O';
	if (matrix[0][1] == 'O' && matrix[1][1] == 'O' && matrix[2][1] == 'O')
		return 'O';
	if (matrix[0][2] == 'O' && matrix[1][2] == 'O' && matrix[2][2] == 'O')
		return 'O';
	if (matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O')
		return 'O';
	if (matrix[2][0] == 'O' && matrix[1][1] == 'O' && matrix[0][2] == 'O')
		return 'O';

	return '/';
}
int main()
{
	Draw();
	while (1)
	{
		Input();
		Draw();
		if (win() == 'X')
		{
			cout << "Player X Wins" << endl << endl;
			break;
		}
		else if (win() == 'O')
		{
			cout << "Player O Wins" << endl << endl;
			break;
		}
		TogglePlayer();
	}
	system("pause");
	return 0;
}