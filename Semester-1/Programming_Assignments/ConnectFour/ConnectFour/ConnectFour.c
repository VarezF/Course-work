#include "ConnectFour.h"

/*
functiom:init_board()
details:inializes board before each round
input: game board and row/column specifications
output: N/A (returns inialized board
*/
void init_board(Cell board[MAX_ROW][MAX_COL], int rows, int cols)
{
	for (int row_index = 0; row_index < rows; ++row_index)
	{
		for (int col_index = 0; col_index < cols; ++col_index)
		{
			board[row_index][col_index].color = '-';
			board[row_index][col_index].isOccupied = FALSE;
			board[row_index][col_index].place.row = row_index;
			board[row_index][col_index].place.col = col_index;
		}
	}
}

/*
functiom: play_connect()
details:similates gameplay for the user
input:game board
output:N/A
*/
void play_connect_4(Cell board[MAX_ROW][MAX_COL])
{
	while (1)/////////determine winner????
	{
		////////////////////////Player 1 turn-Red//////////////////////////////////
		printf("_______________________Player 1: Your turn______________________________\n");
		print_board(board);

		int prompt = 0;

		while (1)	//prompt user for column
		{
			printf("Enter a column to drop your disk\n");
			scanf(" %d", &prompt);
			system("cls");
			if (prompt >= 0 && prompt <= 6)
			{
				place_disk(board, prompt, 'R');
				break;
			}
			else printf("Error: please enter an integer 0-6\n");
		}

		print_board(board);

		if (is_winner(board, 'R') == 1)
		{
			printf("Player 1, YOU WIN!!\n\n");
			system("pause");
			system("cls");
			break;
		}
		system("pause");
		system("cls");
		////////////////////////Player 2 - Yellow //////////////////////////////////

		int player2_column = rand() % MAX_COL;	//chooses random column

		place_disk(board, player2_column, 'Y');
		printf("Player 2 chooses column %d\n", player2_column);
		print_board(board);
		is_winner(board, 'Y');
	}
}

/*
functiom: print_board()
details:displays board to screen
input:board
output:N/A
*/
void print_board(Cell board[MAX_ROW][MAX_COL])
{
	printf("\n    0 1 2 3 4 5 6");
	for (int row_index = 0; row_index < MAX_ROW; ++row_index)
	{
		printf("\n  %d ", row_index);
		for (int col_index = 0; col_index < MAX_COL; ++col_index)
		{
			printf("%c ", board[row_index][col_index].color);
		}
	}
	printf("\n\n");
}

/*
functiom:place_disk()
details:places disk into respecibe column by finding the next open space
input: gameplay board
output:returns 1 if placement was successful
		0 if placement was unsuccesful (if chosen column is full)
*/
int place_disk(Cell board[MAX_ROW][MAX_COL], int column, char color)
{
	for (int row = MAX_ROW - 1; row >= 0; row--)	//itereates throught each row within the chosen column to find the next available spot (where disk falls)
	{
		if (board[row][column].color == '-')
		{
			board[row][column].color = color;	//
			return 1;
		}
	}
	return 0;	//if column is full, return 0
}

/*
functiom: is_winner()
details: determines if a winner exists on the board by scanning the board for 4-of-a-kind
input: board and color (player) being searched
output:0 if no winner is found
		1 if a winner is found
*/
int is_winner(Cell board[MAX_ROW][MAX_COL], char color)
{
	for (int row = 0; row < MAX_ROW && row >= 0; row++)
	{
		for (int column = 0; column < MAX_COL && column >= 0; column++)
		{
			int count = 0;
			for (int i = 0; i < 4 && column - 3 >= 0; i++)	//left/right
			{				
				if (board[row][column - i].color == color)	//scans current and next 3 spots for matching symbol
				{
					count++;
					if (count >= 4)	//if four matches are found, 1 is returned (denoting a winner is found)
						return 1;
				}
				else break;
			}
			for (int i = 0; i < 4 && row - 3 >= 0; i++)	//up/down
			{
				if (board[row - 3][column].color == color)	//scans current and next 3 spots for matching symbol
				{
					count++;
					if (count >= 4)	//if four matches are found, 1 is returned (denoting a winner is found)
						return 1;
				}
				else break;
			}
			for (int i = 0; i < 4 && row - 3 >= 0 && column + 3 < MAX_COL; i++)	//diagonal (/)
			{
				if (board[row - i][column + i].color == color)	//scans current and next 3 spots for matching symbol
				{
					count++;
					if (count >= 4)	//if four matches are found, 1 is returned (denoting a winner is found)
						return 1;
				}
				else break;
			}
			for (int i = 0; i < 4 && row + 3 < MAX_ROW && column - 3 >= 0; i++)	//diagonal (\)
			{
				if (board[row + i][column - i].color == color)	//scans current and next 3 spots for matching symbol
				{
					count++;
					if (count >= 4)	//if four matches are found, 1 is returned (denoting a winner is found)
						return 1;
				}
				else break;
			}
		}
	}
	return 0;	//if no winners are found throughout the search, return 0
}