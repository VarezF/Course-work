#ifndef CONNECT_FOUR_H
#define CONNECT_FOUR_H

#include <stdio.h>

#define MAX_ROW 6
#define MAX_COL 7

typedef enum occupied
{
	FALSE, TRUE
} Occupied;

typedef struct location
{
	int row;
	int col;
} Location;

typedef struct cell
{
	char color;
	Occupied isOccupied;
	Location place;
} Cell;

void init_board(Cell board[MAX_ROW][MAX_COL], int rows, int cols);

void play_connect_4(Cell board[MAX_ROW][MAX_COL]);

void print_board(Cell board[MAX_ROW][MAX_COL]);

int is_winner(Cell board[MAX_ROW][MAX_COL], char symbol);

#endif