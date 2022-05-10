#include <iostream>
#include "Reversi.h"

using namespace std;

//Desc: play a move
//Pre: user chose 1 to play a move
//Post: the user's chosen move is played if validated, otherwise resets to menu
void Choice1(Reversi &othello, char &player) {
	int rowLocation = 0, colLocation = 0;
		cout << "Select the row (0-7) and column (0-7) of where you want to place the disk" << endl;
		cin >> rowLocation >> colLocation;
		if (othello.CheckMove(rowLocation, colLocation, player) == true) {
			othello.SwitchPlayer(player, 2);
		}
}

//Desc: displays game rules
//Pre: user chose 2 to view game rules
//Post: game rules are displayed
void Choice2() {
	cout << endl;
	cout << "Movement Rules:" << endl;
	cout << "1. It creates a straight line (horizontally, vertically, or diagonally) between the newly placed " << endl
		<< "   disk and another of the player's disk currently on the board."
		<< endl << endl << "2. There must be one or more of the opponent's disks between the current player's disks. (A disk must get flipped)" << endl << endl;
}

//Desc: checks possible moves the current player can make
//Pre: user chose 3 to view possible plays
//Post: board is displayed with X's to indicate possible moves
void Choice3(Reversi &othello, char player) {
	othello.CheckPossibleMoves(player);
}

int main() {
	bool isGameOver = false;
	int choice;
	char playAgain = ' ';
	Reversi othello;
	othello.ResetBoard();
	char player = 'B';
	int totalBlack = 0;
	int totalWhite = 0;
	
	do {
		othello.PrintBoard();
		cout << "Menu: 1) Place a disk" << endl;
		cout << "      2) See movement rules" << endl;
		cout << "      3) Display possible moves" << endl;
		cout << "      4) Display best move" << endl << endl;

		if (othello.CheckGameStatus(player) == true) {
			isGameOver = true;
			break;
		}
		othello.SwitchPlayer(player, 1);
		cout << endl;
		cout << "Selection: ";
		cin >> choice;
			if (choice == 1) {
				Choice1(othello, player);
				cout << endl;
			} 
			if (choice == 2) {
				Choice2();
			}
			if (choice == 3) {
				Choice3(othello, player);
			}
			if (choice == 4) {
				othello.LocateBestMove(player);
			}


	} while (isGameOver == false);

	othello.PrintBoard();
	cout << "GAMEOVER" << endl;
	cout << "--------" << endl;
	totalBlack = othello.count('B');
	totalWhite = othello.count('W');
	
	if (totalWhite > totalBlack) {
		player = 'W';
		cout << "Congrats! ";
		othello.SwitchPlayer(player, 1);
		cout << " has won the game! (" << totalBlack << "-" << totalWhite << ")" << endl;
	}
	if (totalBlack > totalWhite) {
		player = 'B';
		cout << "Congrats! ";
		othello.SwitchPlayer(player, 1);
		cout << " has won the game! (" << totalWhite << "-" << totalBlack << ")" << endl;
	}
	while (toupper(playAgain) != 'Y' || toupper(playAgain) != 'N') {
		cout << "Would you like to play again (Y/N)?" << endl;
		cin >> playAgain;
		if (toupper(playAgain) == 'Y') {
			main();
		}
		if (toupper(playAgain) == 'N') {
			cout << "Thank you for playing!" << endl;
			return 0;
		}
	}
}