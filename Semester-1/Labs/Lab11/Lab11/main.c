#include "Header.h"



int main(void)
{
	char maze[8][8];

	for (int row = 0; row < 8; row++)
	{
		for (int column = 0; column < 8; column++)
			maze[row][column] = rand_symbol();
	}
	maze[0][0] = ' ';
	maze[7][7] = ' ';

	display_maze(maze);

	if (find_path(maze, 6, 7) == 0)
		printf("Cannot solve the maze :(\n");

	display_maze(maze);

	return 0;
}



