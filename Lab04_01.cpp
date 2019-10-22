//*****************************************************************************
//  Student Name: Archan Patel
//  Student Number:  20834719 
//  SYDE 121 Lab: 4 Assignment: 1
//  Filename: lab04_01
//  I hereby declare that this code, submitted for credit for the course
//  SYDE121, is a product of my own efforts.  This coded solution has
//  not been plagiarized from other sources and has not been knowingly
//  plagiarized by others.
//  Project:  Tic Tac Toe
//  Purpose:  Allows 2 players to play tic tac toe
//  Date:  Monday, October 14, 2019
//*****************************************************************************
	
/*Test scenarios: - played a game with someone else to see if the game matches real tic tac toe vibes
				  - had each player win in all possible configurations to ensure code works*/

//libraries
#include <iostream>
#include <cmath>
#include <unistd.h>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include<conio.h>
#include<string.h>
#include<stdio.h>

using namespace std;

//function declaration
void game_board();
//purpose: to set up the game board and reset it for new games
//inputs: no input
//output: the game board

int player_input(int game_num, int turn_num);
//purpose: to obtain the appropriate player's move
//input: the number of the game being played and number of turn
//output: the location of their choice

void update (int response, int turn_num, int game_num);
//purpose: to update the board according to user input
//input: location of the player's move and the turn number and the game number
//output: the updated board

bool is_win(int turn_num, int& x_wins, int& o_wins);
//purpose: to determine if the game is over
//input: number of turns and the number of wins each player has
//output: boolean if game is over

bool rematch(int& x_wins, int& o_wins);
//purpose: to determine whether the users want to play again
//input: the number of wins each player has
//output: 'y' for yes, or 'n' for no

//global arrays
string board[4][4];
int check[16] = {};

//main
int main ()
{
	//variable declaration
	bool play_again = true; //to determine whether to play another game
	int response; //the location of the users marker
	int game_num = 0; //number of games played
	int turn_num = 1; //the number of turns in the game
	int x_wins = 0; //wins by player X
	int o_wins = 0; //wins by player O
	
	while (play_again)
	{
		game_board(); //STEP 1: set up game board
		game_num ++; 
		do
		{	
			//STEP 2: adjust game board
			response = player_input(game_num, turn_num); //obtain location
			update(response, turn_num, game_num); //update game board accordingly
		} 
		while (is_win(turn_num++, x_wins, o_wins)); //keep looping until someone wins
		
		//STEP 3: output winner and score
		play_again = rematch(x_wins, o_wins); //ask if the want to play again
		turn_num = 1; //reset turns counter
	}
	
	//STEP 4: terminate
	return 0;
}

//function definition
bool is_win(int turn_num, int& x_wins, int& o_wins)
{
	//output tie if max number of moves achievec
	if (turn_num >= 16)
	{
		cout << "IT WAS A TIE!\n";
		return false;
	}
	//after 6 turns a winner is possible, so check if someone won
	else if (turn_num >= 7)
	{
		//check horizontal  
		for (int i = 0; i < 4; i++) //check for player X
		{
			if (board[i][0] == "X" && board[i][1] == "X" && board[i][2] == "X" && board[i][3] == "X")
			{
				cout << "PLAYER X HAS WON!\n";
				x_wins++;
				return false;
			}
		}
		for (int i = 0; i < 4; i++) //check for player O
		{
			if (board[i][0] == "O" && board[i][1] == "O" && board[i][2] == "O" && board[i][3] == "O")
			{
				cout << "\nPLAYER O HAS WON!\n";
				o_wins++;
				return false;
			}
		}
		
		//check vertical
		for (int i = 0; i < 4; i++) //check for player X
		{
			if (board[0][i] == "X" && board[1][i] == "X" && board[2][i] == "X" && board[3][i] == "X")
			{
				cout << "PLAYER X HAS WON!\n";
				x_wins++;
				return false;
			}
		}
		for (int i = 0; i < 4; i++) //check for player O
		{
			if (board[0][i] == "O" && board[1][i] == "O" && board[2][i] == "O" && board[3][i] == "O") 
			{
				cout << "PLAYER O HAS WON!\n";
				o_wins++;
				return false;
			}
		}
		
		//check diagonal left to right
		if (board[0][0] == "X" && board[1][1] == "X" && board[2][2] == "X" && board[3][3] == "X") //check for player X
		{
			cout << "PLAYER X HAS WON!\n";
			x_wins++;
			return false;
		}
		if (board[0][0] == "O" && board[1][1] == "O" && board[2][2] == "O" && board[3][3] == "O") //check for player O
		{
			cout << "PLAYER O HAS WON!\n";
			o_wins++;
			return false;
		}
		
		//check diagonal right to left
		if (board[0][3] == "X" && board[1][2] == "X" && board[2][1] == "X" && board[3][0] == "X") //check for player X
		{
			cout << "PLAYER X HAS WON!\n";
			x_wins++;
			return false;
		}
		if (board[0][3] == "O" && board[1][2] == "O" && board[2][1] == "O" && board[3][0] == "O") //check for player O
		{
			cout << "PLAYER O HAS WON!\n";
			o_wins++;
			return false;
		}
	}
	return true; //if no winner, return true
}

bool rematch(int& x_wins, int& o_wins)
{
	//variable declaration
	char answer;
	char yes = 'y';
	
	//display wins score
	cout << "Player X wins: " << x_wins << "\nPlayer O wins: " << o_wins;
	
	//determine whether users want to play again
	cout << "\nWould you like to play again? ('y' for yes, 'n' for no): ";
	cin >> answer;
	system("cls");
	if(answer == yes)
		return true;
	else
		return false;
}

void update (int response, int turn_num, int game_num)
{
	//variable declaration
	string x = "X";
	string o = "O";
	string mark;
	
	//determine which is the appropriate marker
	if (game_num % 2 == 1)
	{
		if (turn_num % 2 == 1)
			mark = x;
		else
			mark = o;
	}
	if (game_num % 2 == 0) 
	{
		if (turn_num % 2 == 1)
			mark = o;
		else 
			mark = x;
	}
	
	//determine where to update the array based on user inputted location
	if (response >= 1 && response <= 4)
		board[0][response - 1] = mark;
	else if (response >= 5 && response <= 8)
		board[1][response - 5] = mark;
	else if (response >= 9 && response <= 12)
		board[2][response - 9] = mark;
	else if (response >= 13 && response <= 16)
		board[3][response - 13] = mark;
		
	system("cls");
	
	//output the modified game board
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << board [i][j] << "\t";
		}
		cout << "\n";
	}
	
}

int player_input(int game_num, int turn_num)
{
	//variable declaration
	string x = "X";
	string o = "O";
	int location;
	bool valid_entry = false;
	
	//determine who has the first turn
	if (game_num % 2 == 1)
	{
		if (turn_num % 2 == 1)
			cout << "Player: X take your turn. ";
		else
			cout << "Player: O take your turn. ";
	}
	if (game_num % 2 == 0) 
	{
		if (turn_num % 2 == 1)
			cout << "Player: O take your turn. ";
		else 
			cout << "Player: X take your turn. ";
	}
	
	//determine where the user wants to place their marker
	cout << "Where would you like to place your marker (input the number): ";
	do {
		cin >> location;
		//check whether the entry is outside the bounds or whether it has been repeated
		if (location > 0 && location < 17)
			valid_entry = true;
		for (int i = 0; i < turn_num; i++)
		{
			if (location == check[i])
			{
				valid_entry = false;
			}
		}
		check[turn_num - 1] = location; //store response for future checking
	   }
	while (valid_entry == false);
	
	return location;
}
void game_board()
{
	//variable declaration
	int counter = 1;
	
	//draw the game board
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			ostringstream temp;  // 'temp' as in temporary
			temp << counter ++; 
			board [i][j] = temp.str(); //convert 'i' to string to be able to manipulate later
			cout << board [i][j] << "\t";
		}
		cout << "\n";
	}
}

