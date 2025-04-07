//Rio Kelly
//Group project
//28//03/2025

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };

void displayBoard() {
	system("CLS");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			printf(" %c ", board[i][j]);
		printf("\n");
	}
}

int checkWin(char p) {
	int i;
	for (i = 0; i < 3; i++) {
		if ((board[i][0] == p && board[i][1] == p && board[i][2] == p) ||
			(board[0][i] == p && board[1][i] == p && board[2][i] == p))
			return 1;
	}
	if ((board[0][0] == p && board[1][1] == p && board[2][2] == p) ||
		(board[0][2] == p && board[1][1] == p && board[2][0] == p))
		return 1;
	return 0;
}

int makeMove(char move, char player) {
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (board[i][j] == move) {
				board[i][j] = player;
				return 1;
			}
		}
	}
	return 0;
}

void computerMove() {
	char move = '0';
	while (move < '1' || move > '9' || makeMove(move, 'O') == 0)
		move = (rand() % 9) + '1';
}

int main() {
	char move;
	int gameOver = 0;
	srand(time(0));

	while (gameOver == 0) {
		displayBoard();
		printf("Enter move (1-9): ");
		scanf_s(" %c", &move);

		if (makeMove(move, 'X') == 1) {
			if (checkWin('X') == 1)
				gameOver = 1;
			else {
				computerMove();
				if (checkWin('O') == 1)
					gameOver = 2;
			}
		}
	}

	displayBoard();
	if (gameOver == 1)
		printf("You win!\n");
	if (gameOver == 2)
		printf("Computer wins!\n");

	return 0;
}