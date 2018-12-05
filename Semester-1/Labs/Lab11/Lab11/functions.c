#include "Header.h"

char rand_symbol()
{
	int num = 0;
	char symbol = '\0';

	num = rand() % 3;
	if (num == 0 || num == 1)
	{
		return ' ';
	}
	else return 'X';
}

void display_maze(char print_array[8][8])
{
	printf("  0 1 2 3 4 5 6 7\n");
	for (int row = 0; row < 7; row++)
	{
		printf("%d ", row);
		for (int column = 0; column < 7; column++)
		{
			printf("%c ", print_array[row][column]);
			if (column == 6)
				printf("\n");
		}
	}
}

int find_path(char maze[8][8], int row, int column)
{
	maze[row][column] = '*';
	printf("(%d, %d)\n", column, row);

	if (row == 7 && column == 7)
	{
		return 1;
	}

	if (maze[row][column + 1] == ' ') //right
	{
		if (find_path(maze, row, column + 1) == 1)
		{
			return 1;
		}
	}
	if (maze[row - 1][column] == ' ') //up
	{
		if (find_path(maze, row - 1, column) == 1)
		{
			return 1;
		}
	}
	if (maze[row][column - 1] == ' ') //left
	{
		if (find_path(maze, row, column - 1) == 1)
		{
			return 1;
		}
	}
	if (maze[row + 1][column] == ' ') //down
	{
		if (find_path(maze, row + 1, column) == 1)
		{
			return 1;
		}
	}
	return 0;
}