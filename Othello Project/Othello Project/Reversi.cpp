#include "Reversi.h"
#include <iostream>
#include<vector>
using namespace std;

//Desc: Sets the game to blanks
//Pre: The board array is declared
//Post: The board is set to blanks
Reversi::Reversi() {
	for (int row = 0; row <= 7; row++) {
		for (int column = 0; column <= 7; column++) {
			board[row][column] = ' ';
		}
	}
}

//Desc: count player pieces and return the number
//Pre: pieces must be on board and must be gameover
//Post: # of pieces is returned for each player
int Reversi::count(char color) {
	totalCount = 0;
	for (int row = 0; row <= 7; row++) {
			for (int column = 0; column <= 7; column++) {
				if (board[row][column] == color) {
					totalCount++;
				}
			}
	}
	return totalCount;
}

//Desc: Places the disc at the location
//Pre: The move has been checked by checkMove function and can be played
//Post: Piece is placed in the location the user chose
void Reversi::SetDisk(int row, int col, char color) {
	board[row][col] = color;	
}

//Desc: adds up all opponent pieces that will flip once player plays a specific move
//Pre: all opponent pieces that will be flipped are calculated before entering this function
//Post: returns the max number of flips calculated
int Reversi::ResultOfMove(int row, int col, char color) {
	totalFlipped = flippedRight + flippedLeft + flippedTop + flippedBottom + flippedRightUp + flippedRightDown + flippedLeftUp + flippedLeftDown;
	BestMove(row, col, totalFlipped, color);
	totalFlipped = 0;
	return highestFlipped;
}

//Desc: sets the row and col for the best move to display
//Pre: best move is calculated and is passed along with the row and col
//Post: row and col for the best move are set to be displayed to the user
void Reversi::BestMove(int& row, int& col, int& flipped, char color) {
	if (flipped > highestFlipped) {
		highestFlipped = flipped;
		highestRow = row;
		highestCol = col;
	}
}

//Desc: the current best move for the user is searched for and displayed
//pre: all possible moves are marked with an X to search for which move is currently the best
//Post: all X's are removed. The best move is displayed to the user. This include the row, col, and the score differential
void Reversi::LocateBestMove(char color) {
	CheckPossibleMoves(color);
	char opponent;
	if (color == 'B') {
		opponent = 'W';
	}
	else {
		opponent = 'B';
	}
	for (int row = 0; row<= 7; row++) {
		for (int col = 0; col<= 7; col++) {
			if (board[row][col] == 'X') {
				bool isFriendlyColorFound = false;
				flippedRight = 0;
				flippedLeft = 0;
				flippedTop = 0;
				flippedBottom = 0;
				flippedRightUp = 0;
				flippedRightDown = 0;
				flippedLeftUp = 0;
				flippedLeftDown = 0;
				int increment = 1;
				//right
				while (col + increment <= 7 && board[row][col + increment] == opponent) {
					flippedRight++;
					if (board[row][col + increment + 1] == color) {
							isFriendlyColorFound = true;
							break;
					}
					if (board[row][col + increment + 1] == ' ' || board[row][col + increment + 1] == 'X') {
							flippedRight = 0;
							break;
					}
					increment++;
					if (isFriendlyColorFound == true) {
						break;
					}
				}
				if (isFriendlyColorFound == false) {
					flippedRight = 0;
				}
				//Left
				increment = 1;
				isFriendlyColorFound = false;
				while (col - increment > 0 && board[row][col - increment] == opponent) {
					flippedLeft++;
					if (board[row][col - increment - 1] == color) {
						isFriendlyColorFound = true;
						break;
					}
					if (board[row][col - increment - 1] == ' ' || board[row][col - increment - 1] == 'X') {
						flippedLeft = 0;
						break;
					}
					increment++;
					if (isFriendlyColorFound == true) {
						break;
					}
				}
				if (isFriendlyColorFound == false) {
					flippedLeft = 0;
				}
				//Top
				increment = 1;
				isFriendlyColorFound = false;
				while (row - increment > 0 && board[row - increment][col] == opponent) {
						flippedTop++;
					
					if (board[row - increment - 1][col] == color) {
						isFriendlyColorFound = true;
						break;
					}
					if (board[row - increment - 1][col] == ' ' || board[row - increment - 1][col] == 'X') {
						flippedTop = 0;
						break;
					}
					increment++;
					if (isFriendlyColorFound == true) {
						break;
					}
				}
				if (isFriendlyColorFound == false) {
					flippedTop = 0;
				}
				//Bottom
				increment = 1;
				isFriendlyColorFound = false;
				while (row + increment < 7 && board[row + increment][col] == opponent) {
					flippedBottom++;
					if (board[row + increment + 1][col] == color) {
						isFriendlyColorFound = true;
						break;
					}
					if (board[row + increment + 1][col] == ' ' || board[row + increment + 1][col] == 'X') {
						flippedBottom = 0;
						break;
					}
					increment++;
					if (isFriendlyColorFound == true) {
						break;
					}
				}
				if (isFriendlyColorFound == false) {
					flippedBottom = 0;
				}
				//Rightup
				increment = 1;
				isFriendlyColorFound = false;
				while ((row - increment >= 0) && (col + increment <= 7) && board[row - increment][col + increment] == opponent) {
						flippedRightUp++;
					
					if (board[row - increment - 1][col + increment + 1] == color) {
						isFriendlyColorFound = true;
						break;
					}
					if (board[row - increment - 1][col + increment + 1] == ' ' || board[row - increment - 1][col + increment + 1] == 'X') {
						flippedRightUp = 0;
						break;
					}
					increment++;
					if (isFriendlyColorFound == true) {
						break;
					}
				}
				if (isFriendlyColorFound == false) {
					flippedRightUp = 0;
				}
				//Rightdown
				increment = 1;
				isFriendlyColorFound = false;
				while ((row + increment <= 7) && (col + increment <= 7) && board[row + increment][col + increment] == opponent) {
					flippedRightDown++;
					
					if (board[row + increment + 1][col + increment + 1] == color) {
						isFriendlyColorFound = true;
						break;
					}
					if (board[row + increment + 1][col + increment + 1] == ' ' || board[row + increment + 1][col + increment + 1] == 'X') {
						flippedRightDown = 0;
						break;
					}
					increment++;
					if (isFriendlyColorFound == true) {
						break;
					}
				}
				if (isFriendlyColorFound == false) {
					flippedRightDown = 0;
				}
				//Leftup
				increment = 1;
				isFriendlyColorFound = false;
				while ((row - increment >= 0) && (col - increment >= 0) && board[row - increment][col - increment] == opponent) {
					flippedLeftUp++;
					
					if (board[row - increment - 1][col - increment - 1] == color) {
						isFriendlyColorFound = true;
						break;
					}
					if (board[row - increment - 1][col - increment - 1] == ' ' || board[row - increment - 1][col - increment - 1] == 'X') {
						flippedLeftUp = 0;
						break;
					}
					increment++;
					if (isFriendlyColorFound == true) {
						break;
					}
				}
				if (isFriendlyColorFound == false) {
					flippedLeftUp = 0;
				}
				//Leftdown
				increment = 1;
				isFriendlyColorFound = false;
				while ((row + increment <= 7) && (col - increment >= 0) && board[row + increment][col - increment] == opponent) {
					flippedLeftDown++;
					
					if (board[row + increment + 1][col - increment - 1] == color) {
						isFriendlyColorFound = true;
						break;
					}
					if (board[row + increment + 1][col - increment - 1] == ' ' || board[row + increment + 1][col - increment - 1] == 'X') {
						flippedLeftDown = 0;
						break;
					}
					increment++;
					if (isFriendlyColorFound == true) {
						break;
					}
				}
				if (isFriendlyColorFound == false) {
					flippedLeftDown = 0;
				}
				ResultOfMove(row, col, color);
			}
		}
	}
	//remove all X
	for (int rowIndex = 0; rowIndex <= 7; rowIndex++) {
		for (int colIndex = 0; colIndex <= 7; colIndex++) {
			if (board[rowIndex][colIndex] == 'X') {
				board[rowIndex][colIndex] = ' ';
			}
		}
	}
	cout << "Your best move is: " << highestRow << ", " << highestCol << " and will result int a + " << highestFlipped << " score differential" << endl;
	highestCol = 0;
	highestRow = 0;
	highestFlipped = 0;
}

//Desc: opponents pieces are flipped on the right side
//Pre: opponent's pieces are validated to be flipped
//Post: the pieces on the right side are flipped to the current player's pieces
void Reversi::FlipRightSide(int row, int col, char color) {
	char opponent;
	if (color == 'B') {
		opponent = 'W';
	}
	else {
		opponent = 'B';
	}
	//Flip all right side
	if (col < 7) {
		for (int index = col + 1; index <= 7; index++) {
			if (board[row][index] == opponent) {
				board[row][index] = color;
			}
			else if (board[row][index] == color) {
				break;
			}
		}
	}
}

//Desc: opponents pieces are flipped on the left side
//Pre: opponent's pieces are validated to be flipped
//Post: the pieces on the left side are flipped to the current player's pieces
void Reversi::FlipLeftSide(int row, int col, char color) {
	char opponent;
	if (color == 'B') {
		opponent = 'W';
	}
	else {
		opponent = 'B';
	}
	//Flip all left side
	if (col > 0) {
		for (int index = col - 1; index >= 0; index--) {
			if (board[row][index] == opponent) {
				board[row][index] = color;
			}
			else if (board[row][index] == color) {
				break;
			}
		}
	}
}

//Desc: opponents pieces are flipped on the top side
//Pre: opponent's pieces are validated to be flipped
//Post: the pieces on the top side are flipped to the current player's pieces
void Reversi::FlipTopSide(int row, int col, char color) {
	char opponent;
	if (color == 'B') {
		opponent = 'W';
	}
	else {
		opponent = 'B';
	}
	//Flip all top side
	if (row > 0) {
		for (int index = row - 1; index >= 0; index--) {
			if (board[index][col] == opponent) {
				board[index][col] = color;
			}
			else if (board[index][col] == color) {
				break;
			}
		}
	}
}

//Desc: opponents pieces are flipped on the bottom side
//Pre: opponent's pieces are validated to be flipped
//Post: the pieces on the bottom side are flipped to the current player's pieces
void Reversi::FlipBottomSide(int row, int col, char color) {
	char opponent;
	if (color == 'B') {
		opponent = 'W';
	}
	else {
		opponent = 'B';
	}
	//Flip all bottom side
	if (row < 7) {
		for (int index = row + 1; index <= 7; index++) {
			if (board[index][col] == opponent) {
				board[index][col] = color;
			}
			else if (board[index][col] == color) {
				break;
			}
		}
	}
}

//Desc: opponents pieces are flipped on the right up side
//Pre: opponent's pieces are validated to be flipped
//Post: the pieces on the right up side are flipped to the current player's pieces
void Reversi::FlipRightUp(int row, int col, char color) {
	char opponent;
	if (color == 'B') {
		opponent = 'W';
	}
	else {
		opponent = 'B';
	}
	int increment = 0;
	if (row > 0 && col < 7) {
		while ((row - increment >= 0) && (col + increment <= 7)) {
			if (board[row - increment][col + increment] == opponent) {
				board[row - increment][col + increment] = color;
			}
			else if(board[row - increment][col + increment] == color) {
				break;
			}
			increment++;
		}
	}
}

//Desc: opponents pieces are flipped on the right down side
//Pre: opponent's pieces are validated to be flipped
//Post: the pieces on the right down side are flipped to the current player's pieces
void Reversi::FlipRightDown(int row, int col, char color) {
	char opponent;
	if (color == 'B') {
		opponent = 'W';
	}
	else {
		opponent = 'B';
	}
	int increment = 0;
	if (row < 7 && col < 7) {
		while ((row + increment >= 0) && (col + increment <= 7)) {
			if (board[row + increment][col + increment] == opponent) {
				board[row + increment][col + increment] = color;
			}
			else if (board[row + increment][col + increment] == color) {
				break;
			}
			increment++;
		}
	}
}

//Desc: opponents pieces are flipped on the left up side
//Pre: opponent's pieces are validated to be flipped
//Post: the pieces on the left up side are flipped to the current player's pieces
void Reversi::FlipLeftup(int row, int col, char color) {
	char opponent;
	if (color == 'B') {
		opponent = 'W';
	}
	else {
		opponent = 'B';
	}
	int increment = 0;
	if (row > 0 && col > 0) {
		while ((row - increment >= 0) && (col - increment <= 7)) {
			if (board[row - increment][col - increment] == opponent) {
				board[row - increment][col - increment] = color;
			}
			else if (board[row - increment][col - increment] == color) {
				break;
			}
			increment++;
		}
	}	
}

//Desc: opponents pieces are flipped on the left down side
//Pre: opponent's pieces are validated to be flipped
//Post: the pieces on the left down side are flipped to the current player's pieces
void Reversi::FlipLeftDown(int row, int col, char color) {
	char opponent;
	if (color == 'B') {
		opponent = 'W';
	}
	else {
		opponent = 'B';
	}
	int increment = 0;
	if (row < 7 && col > 0) {
		while ((row + increment >= 0) && (col - increment <= 7)) {
			if (board[row + increment][col - increment] == opponent) {
				board[row + increment][col - increment] = color;
			}
			else if (board[row + increment][col - increment] == color) {
				break;
			}
			increment++;
		}
	}
}

//Desc: finds current player's pieces to check for possible moves (beginning function)
//Pre: game has not ended (board is not completely full and no winners yet)
//Post: once the current player's piece is found, the next function is declared for further validation of a move
void Reversi::CheckPossibleMoves(char color) {
	for (int rowIndex = 0; rowIndex <= 7; rowIndex++) {
		for (int colIndex = 0; colIndex <= 7; colIndex++) {
			if (board[rowIndex][colIndex] == color) {
				PlacePossibleMoves(rowIndex, colIndex, color);
			}
		}
	}
}

//Desc: X's are placed for current player's possible moves
//Pre: a piece for the current player has been found
//Post: current player's move is further validated and an X is placed at the possible move (row and col)
void Reversi::PlacePossibleMoves(int row, int col, char color) {
	char opponent;
	if (color == 'B') {
		opponent = 'W';
	}
	else {
		opponent = 'B';
	}
	//Right
	if (col + 1 < 7 && board[row][col + 1] == opponent) {
		int increment = 2;
		while (col + increment <= 7) {
			if (board[row][col + increment] == color) {
				break;
			}
			if (board[row][col + increment] == 'X') {
				break;
			}
			if (board[row][col + increment] == ' ') {
				board[row][col + increment] = 'X';
				break;
			}
			increment++;
		}
	}
	//Left
	if (col > 0 && board[row][col - 1] == opponent) {
		int increment = 2;
		while (col - increment >= 0) {
			if (board[row][col - increment] == color) {
				break;
			}
			if (board[row][col - increment] == 'X') {
				break;
			}
			if (board[row][col - increment] == ' ') {
				board[row][col - increment] = 'X';
				break;
			}
			increment++;
		}
	}
	//top
	if (row > 0 && board[row - 1][col] == opponent) {
		int increment = 2;
		while (row - increment >= 0) {
			if (board[row - increment][col] == color) {
				break;
			}
			if (board[row - increment][col] == 'X') {
				break;
			}
			if (board[row - increment][col] == ' ') {
				board[row - increment][col] = 'X';
				break;
			}
			increment++;
		}
	}
	//Bottom
	if (row < 7 && board[row + 1][col] == opponent) {
		int increment = 2;
		while (row + increment <= 7) {
			if (board[row + increment][col] == color) {
				break;
			}
			if (board[row + increment][col] == 'X') {
				break;
			}
			if (board[row + increment][col] == ' ') {
				board[row + increment][col] = 'X';
				break;
			}
			increment++;
		}
	}
	//Rightup
	if (row > 0 && col < 7 && board[row - 1][col + 1] == opponent) {
		int increment = 2;
		while ((row - increment >= 0) && (col + increment <= 7)) {
			if (board[row - increment][col + increment] == color) {
				break;
			}
			if (board[row - increment][col + increment] == 'X') {
				break;
			}
			if (board[row - increment][col + increment] == ' ') {
				board[row - increment][col + increment] = 'X';
				break;
			}
			increment++;
		}
	}
	//Rightdown
	if (row < 7 && col < 7 && board[row + 1][col + 1] == opponent) {
		int increment = 2;
		while ((row + increment <= 7) && (col + increment <= 7)) {
			if (board[row + increment][col + increment] == color) {
				break;
			}
			if (board[row + increment][col + increment] == 'X') {
				break;
			}
			if (board[row + increment][col + increment] == ' ') {
				board[row + increment][col + increment] = 'X';
				break;
			}
			increment++;
		}
	}
	//Leftup
	if (row > 0 && col > 0 && board[row - 1][col - 1] == opponent) {
		int increment = 2;
		while ((row - increment >= 0) && (col - increment >= 0)) {
			if (board[row - increment][col - increment] == color) {
				break;
			}
			if (board[row - increment][col - increment] == 'X') {
				break;
			}
			if (board[row - increment][col - increment] == ' ') {
				board[row - increment][col - increment] = 'X';
				break;
			}
			increment++;
		}
	}
	//Leftdown
	if (row < 7 && col > 0 && board[row + 1][col - 1] == opponent) {
		int increment = 2;
		while ((row + increment <= 7) && (col - increment >= 0)) {
			if (board[row + increment][col - increment] == color) {
				break;
			}
			if (board[row + increment][col - increment] == 'X') {
				break;
			}
			if (board[row + increment][col - increment] == ' ') {
				board[row + increment][col - increment] = 'X';
				break;
			}
			increment++;
		}
	}
}

//Desc: checks if any player still has possible moves
//Pre: a move has been played
//Post: if no possible moves are available for both players, return true (gameover)
bool Reversi::CheckGameStatus(char& color) {
	char opponent;
	if (color == 'B') {
		opponent = 'W';
	}
	else {
		opponent = 'B';
	}
	CheckPossibleMoves(color);
	for (int rowIndex = 0; rowIndex <= 7; rowIndex++) {
		for (int colIndex = 0; colIndex <= 7; colIndex++) {
			if (board[rowIndex][colIndex] == 'X') {
				//remove all x
				for (int rowIndex = 0; rowIndex <= 7; rowIndex++) {
					for (int colIndex = 0; colIndex <= 7; colIndex++) {
						if (board[rowIndex][colIndex] == 'X') {
							board[rowIndex][colIndex] = ' ';
						}
					}
				}
				return false;
			}
			else if (board[rowIndex][colIndex] == color || board[rowIndex][colIndex] == opponent || board[rowIndex][colIndex] == ' ') {
				continue;
			}

		}
	}
	CheckPossibleMoves(opponent);
	for (int rowIndex = 0; rowIndex <= 7; rowIndex++) {
		for (int colIndex = 0; colIndex <= 7; colIndex++) {
			if (board[rowIndex][colIndex] == 'X') {
				//remove all x
				for (int rowIndex = 0; rowIndex <= 7; rowIndex++) {
					for (int colIndex = 0; colIndex <= 7; colIndex++) {
						if (board[rowIndex][colIndex] == 'X') {
							board[rowIndex][colIndex] = ' ';
						}
					}
				}
				cout << "Player's turn is passed!" << endl;
				SwitchPlayer(color, 2);
				return false;
			}
			else if (board[rowIndex][colIndex] == color || board[rowIndex][colIndex] == opponent || board[rowIndex][colIndex] == ' ') {
				continue;
			}
		}
	}
	return true;	
}

//Desc: Prints Board to the screen
//Pre: Board needs to be initialized and reset
//Post: Board is printed to the screen
void Reversi::PrintBoard() {
	cout << " -------------------------------" << endl;
	for (int row = 0; row <= 7; row++) {
		for (int column = 0; column <= 7; column++) {
			cout << board[row][column] << " | ";
		}
		cout << endl << " -------------------------------" << endl;
	}
}

//Desc: Resets all positions on the board
//Pre: Board must be initialized as blanks
//Post: Pieces on the board are reset to start a new game
void Reversi::ResetBoard() {
	board[3][3] = 'W';
	board[4][4] = 'W';
	board[3][4] = 'B';
	board[4][3] = 'B';

	//USED FOR TESTING
	/*for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++) {
			board[row][col] = 'W';
		}
	}
	board[0][0] = ' ';
	
	board[0][7] = 'B';
	
	board[0][5] = 'W';*/
}

//Desc: Switch between players or declare player's turn
//pre: Previous player played a move or the move was passed
//post: Player is switched based on current player or declare player's turn
void Reversi::SwitchPlayer(char &player, int decision) {
	if (decision == 1) {
		if (player == 'B') {
			cout << "Player 1: Black";
		}
		else {
			cout << "Player 2: White";
		}
	}
	else if (decision == 2) {
		if (player == 'B') {
			player = 'W';
		}
		else {
			player = 'B';
		}
	}
}

//Desc:Check if the player move is valid
//Pre: A row and col are selected by player
//Post: Returns true if the player was able to move to the user specified position
bool Reversi::CheckMove(int row, int col, char color) {
	//Remove all X
	for (int rowIndex = 0; rowIndex <= 7; rowIndex++) {
		for (int colIndex = 0; colIndex <= 7; colIndex++) {
			if (board[rowIndex][colIndex] == 'X') {
				board[rowIndex][colIndex] = ' ';
			}
		}
	}
	bool isMoveValid = false;
	int increment = 0;
	char opponent;
	if (color == 'B') {
		opponent = 'W';
	}
	else {
		opponent = 'B';
	}
	if (board[row][col] == ' ') {
		//Check right side
		if (col < 7) {
			if (board[row][col + 1] == opponent) {
				increment = 1;
				while (col + increment <= 7) {
					if (board[row][col + increment] == color) {
						FlipRightSide(row, col, color);
						isMoveValid = true;
						
					}
					increment++;
				}
			}
		}
		//Check left side
		if (col > 0) {
			if (board[row][col - 1] == opponent) {
				increment = 1;
				while (col - increment >= 0) {
					if (board[row][col - increment] == color) {
						FlipLeftSide(row, col, color);
						isMoveValid = true;
					}
					increment++;
				}
			}
		}
		//Check bottom side
		if (row < 7) {
			if (board[row + 1][col] == opponent) {
				increment = 1;
				while (row + increment <= 7) {
					if (board[row + increment][col] == color) {
						FlipBottomSide(row, col, color);
						isMoveValid = true;
					}
					increment++;
				}
			}
		}
		//Check top side
		if (row > 0) {
			if (board[row - 1][col] == opponent) {
				increment = 1;
				while (row - increment >= 0) {
					if (board[row - increment][col] == color) {
						FlipTopSide(row, col, color);
						isMoveValid = true;
					}
					increment++;
				}
			}
		}
		//Check rightup diagonal
		if (row > 0 && col < 7) {
			if (board[row - 1][col + 1] == opponent) {
				increment = 0;
				while ((row - increment >= 0) && (col + increment <= 7)) {
					if (board[row - increment][col + increment] == color) {
						FlipRightUp(row, col, color);
						isMoveValid = true;
					}
					increment++;
				}
			}
		}
		//Check rightdown diagonal
		if (row < 7 && col < 7) {
			if (board[row + 1][col + 1] == opponent) {
				increment = 0;
				while ((row + increment <= 7) && (col + increment <= 7)) {
					if (board[row + increment][col + increment] == color) {
						FlipRightDown(row, col, color);
						isMoveValid = true;
					}
					increment++;
				}
			}
		}
		//Check leftup diagonal
		if (row > 0 && col > 0) {
			if (board[row - 1][col - 1] == opponent) {
				increment = 0;
				while ((row - increment >= 0) && (col - increment >= 0)) {
					if (board[row - increment][col - increment] == color) {
						FlipLeftup(row, col, color);
						isMoveValid = true;
					}
					increment++;
				}
			}
		}
		//check leftdown diagonal
		if (row < 7 && col > 0) {
			if (board[row + 1][col - 1] == opponent) {
				increment = 0;
				while ((row + increment <= 7) && (col - increment >= 0)) {
					if (board[row + increment][col - increment] == color) {
						FlipLeftDown(row, col, color);
						isMoveValid = true;
					}
					increment++;
				}
			}
		}
		if (isMoveValid == true) {
			SetDisk(row, col, color);
			return true;
		}
		cout << "Invalid move: Not a valid position!" << endl;
		return false;
	}
	else if (board[row][col] != ' ') {
		cout << "Invalid move: Position already taken!" << endl;
		return false;
	}
}