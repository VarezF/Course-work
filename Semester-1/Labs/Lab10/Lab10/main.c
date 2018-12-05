#include "Header.h"

// Write a two - player interactive game to play Tic Tac Toe.The game board for Tic Tac Toe will be represented by a 2 - Dimensional array of structs.
//The underlying game board struct should be represented as follows :
int main(void)
{
	int size = 0;

	typedef struct coordinate
	{
		int row;
		int column;
	} Coordinate;

	typedef struct cell
	{
		int occupied; // 1 if an X or O is in this cell; 0 otherwise
		char symbol; // X for one player, O for the other player
		Coordinate location; // A struct defined above, which represents the position of the cell within the game board
	} Cell;

	printf("Enter the size of the board:\n");	//board consists of a total of n x n Cells, where n is selected by the user of the game.
	scanf("%d", &size);


	strcpy(Coordinate1.column, '\0');


	if (first_player() == 1)
	{
		printf("Enter row:\n");
	}
	else 

	//Your program should randomly select who goes first, X or O.Once a player has been chosen, your program should prompt the player 
	//for a position(row and column) in which to draw his / her symbol.
	//Players continue to alternate moves until either a winner has been determined or a "scratch" game occurs.
	//A player wins if his / her symbols align with n in a row diagonally, vertically, or horizontally.
	//A "scratch" game occurs if all cells on the board are occupied and no player aligned n of his / her symbols in a row.

	//The program should prompt the users to determine if they want to play another game.Keep track of each player’s number of wins, losses, and total game played in a struct defined as follows :

	typedef struct game_info
	{
		int wins;
		int losses;
		int total_games_played.
	} Game_info;
}
//random sentence
/*int main(void)
{
	const char *article[5] = { "the", "a", "one", "some", "any" }, *noun[5] = { "boy", "girl", "dog", "town", "car" },
		*verb[5] = { "drove", "jumped", "ran", "walked", "skipped" }, *preposition[5] = { "to", "from", "over", "under", "on" };

	for (int i = 0; i < 20; i++)
	{
		char sentence[50] = { '\0' };
		strcat(sentence, article[rand_value()]);
		strcat(sentence, " ");
		strcat(sentence, noun[rand_value()]);
		strcat(sentence, " ");
		strcat(sentence, verb[rand_value()]);
		strcat(sentence, " ");
		strcat(sentence, preposition[rand_value()]);
		strcat(sentence, " ");
		strcat(sentence, article[rand_value()]);
		strcat(sentence, " ");
		strcat(sentence, noun[rand_value()]);
		strcat(sentence, "!\n");
		printf("%s\n", sentence);
	}


}*/