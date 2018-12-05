// Complete the game of Connect Four from this starter code to recieve
// bonus points!

#include "ConnectFour.h"

int main(void)
{
	Cell board[MAX_ROW][MAX_COL] = { {/*row 0*/{'\0', FALSE, {0, 0}}} };	//array of cells (cell structs)

	init_board(board, MAX_ROW, MAX_COL);

	/////////Game menu/////////////////////////////////////////////////
	int prompt = 0;

	while (1)
	{
		printf("_________Welcome to Connect Four!_____________\n\n"
			"Please select an option below:\n"
			"1.) Start Game\n"
			"2.) Quit\n");
		scanf(" %d", &prompt);
		system("cls");
		if (prompt == 1)	
		{
			init_board(board, MAX_ROW, MAX_COL);
			play_connect_4(board);	//Enter game (reenter game menu after user finishes game)
		}
		else if (prompt == 2)	//exit game menu, end program
			break;
		else
			printf("Error: please enter 1 or 2\n");
	}

	return 0;
}