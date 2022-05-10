#pragma once

class Reversi {
private:
	const static int ROWS = 8;
	const static int COLS = 8;
	char board[ROWS][COLS];
	int highestFlipped = 0;
	int highestRow = 0;
	int highestCol = 0;
	int flippedRight = 0;
	int flippedLeft = 0;
	int flippedTop = 0;
	int flippedBottom = 0;
	int flippedRightUp = 0;
	int flippedRightDown = 0;
	int flippedLeftUp = 0;
	int flippedLeftDown = 0;
	int totalFlipped = 0;
	int totalCount = 0;
public:
	Reversi();
	int count(char color);
	void SetDisk(int row, int col, char color);
	int ResultOfMove(int row, int col, char color);
	void BestMove(int& row, int& col, int& flipped, char color);
	void PrintBoard();
	void ResetBoard();
	void SwitchPlayer(char &player, int decision);
	bool CheckMove(int row, int col, char color);
	void FlipRightSide(int row, int col, char color);
	void FlipLeftSide(int row, int col, char color);
	void FlipTopSide(int row, int col, char color);
	void FlipBottomSide(int row, int col, char color);
	void FlipRightUp(int row, int col, char color);
	void FlipLeftDown(int row, int col, char color);
	void FlipLeftup(int row, int col, char color);
	void FlipRightDown(int row, int col, char color);
	void CheckPossibleMoves(char color);
	void PlacePossibleMoves(int row, int col, char color);
	void LocateBestMove(char color);
	bool CheckGameStatus(char &color);
};