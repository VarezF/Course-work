#include "Header.h"

///////////////////////////////////Menu/////////////////////////////////////////////////////////////////////////////////////////////////
void welcome_screen()	//displays an initial program welcome message along with the menu options
{
	int exit = 0;
	while (exit == 0)
	{
		int prompt = 0;
		while (1)
		{
			printf("_______________Welcome to Battleship!__________________\n\n");	//displays welcome messege and menu for user
			printf("Please enter one of the following options:\n"
				"1.) Start Game!\n"
				"2.) View Rules\n"
				"3.) Quit Game\n");
			scanf(" %d", &prompt);
			system("cls");
			if (prompt == 1 || prompt == 2 || prompt == 3)	//checks for user error
			{
				break;
			}
			else printf("error: Please choose an option below: type '1', '2' or '3'.\n");	//if user error occurs, returns to main menu and re-prompts user
		}
		if (prompt == 1)	//If user chooses 'start game'
		{
			prepare_game(); //prepares game, initializing player matrices and choosing starting player
		}
		else if (prompt == 2)	//If player chooses to 'View Rules'
		{
			print_rules();	//prints rules of Battleship for user
		}
		else if (prompt == 3)	//if player chooses to exit game
		{
			exit = 1;	//returns to main to close the program
		}
	}
}

void print_rules()
{
	char prompt = '\0';
	printf("Battleship is a two player Navy game.\n"
		"The objective of the game is to sink all ships in your enemy's fleet.\nThe Player to sink his/her enemy's fleet first wins.\n"
		"Both players' fleets consist of 5 ships that are hidden from the enemy.\n"
		"Each ship may be differentiated by its \"size\" (besides the Cruiser and Submarine) or number of cells it expands on the game board:\n"
		"Carrier= 5 cells\nBattleship = 4 cells\nCruiser = 3 cells\nSubmarine = 3 cells\nDestroyer = 2 cells.\n\n");
	printf("Each players board is a 10x10 matrix containing 'ocean' squares and 'ship' squares (denoted by their respective first letter, or 'r' for cruiser).\n"
		"You may choose to place your ships manually, or have them placed for you randomly\n"
		"See below example:\n\n"

		"  0 1 2 3 4 5 6 7 8 9\n"
		"0 - - c c c c c - - -\n"
		"1 d d - - - - - - - -\n"
		"2 - - - - - - - - - s\n"
		"3 - - - - b - - - - s\n"
		"4 - - - - b - - - - s\n"
		"5 - - - - b - - - - -\n"
		"6 - - - - b - - - - -\n"
		"7 - - - r r r - - - -\n"
		"8 - - - - - - - - - -\n"
		"9 - - - - - - - - - -\n\n"

		"On your turn, simply enter an (x,y) coordinate where you'd like to attack.\nIf you successfully hit an enemy ship, a '*' will appear on your enemies board\n"
		"If you miss, a 'm' will appear\n"
		"(note: you will not see your enemies ship placement, only if you hit or miss a ship)\n\n");
	printf("Press any key to return to menu screen\n");
	scanf(" %c", &prompt);
	system("cls");
}

//////////////////////////////////Game preperation//////////////////////////////////////////////////////////////////////////////////////
int prepare_game()
{
	int first_player = 0;
	char prompt = '\0';

	FILE *infile = NULL;

	infile = fopen("battleship.log", "w");

	initialize_game_board();	//clears both boards

	randomly_place_ships_on_board(player2_board);	//places ships randomly across the AI board

	ship_placement_prompt();	//prompts user to manually or automatically place ships across the board

	printf("Your board is displayed below\n");

	display_board(player1_board);

	system("pause");

	system("cls");

	first_player = select_who_starts_first();	//select first player

	play_game(first_player, infile);	//enter gameplay	
}

void initialize_game_board()//At the beginning of the game each Players' game board initialized to all ' - ' 
							//indicating that no ships have been placed on either board.
{
	for (int row = 0; row <= 10; row++)
	{
		for (int column = 0; column < 10; column++)
		{
			player1_board[column][row] = '-';
			player2_board[column][row] = '-';
			enemy_board[column][row] = '-';
		}
	}
}

void ship_placement_prompt()	//Before the game starts, Player1 should have the option to either manually place each of the 
								//5 ships in his / her fleet or to have them randomly placed on the board.
{
	while (1)
	{
		char prompt = '\0';
		printf("Would you like to place your ships manually? (Y/N)\n\n"
			"(Note: If you choose (N) ship placement will be chosen randomly for you)\n");
		scanf(" %c", &prompt);
		system("cls");
		if (prompt == 'Y' || prompt == 'N')
		{
			if (prompt == 'Y')
			{
				manually_place_ships_on_board(player1_board);
				system("cls");
			}
			else if (prompt == 'N')
				randomly_place_ships_on_board(player1_board);
			system("cls");
			break;
		}
		else
		{
			system("cls");
			printf("Invalid option, please type 'Y' or 'N'\n");
		}
	}

}

void randomly_place_ships_on_board(char player_array[10][10]) //randomly places the 5 types of ships on a given board.
{
	int carrier_size = 5, battleship_size = 4, cruiser_size = 3, submarine_size = 3, destroyer_size = 2;
	int x_coordinate = 0, y_coordinate = 0, direction = 0, valid_position = 0;

	///////Carrier Placement
	while (valid_position == 0)	//continues to loop until rand() coordinates find a valid placement
	{
		x_coordinate = rand_coordinate(); //gathers random coordinates and direction on the board
		y_coordinate = rand_coordinate();	//Note: 0 = "to the right", 1 = "Up", 2 = "left" and 3 = "downwards"
		direction = rand_direction();

		valid_position = validate_position(x_coordinate, y_coordinate, direction, player_array, carrier_size);	//checks for valid position

		if (valid_position == 1)
		{
			print_ship(carrier_size, x_coordinate, y_coordinate, direction, 'c', player_array);
		}
	}
	
	///////Battleship Placement
	valid_position = 0;	//re-initializes position validity to 'false' for next ship placement
	while (valid_position == 0)	//continues to loop until rand() coordinates find a valid placement
	{
		x_coordinate = rand_coordinate(); //gathers random coordinates and direction on the board
		y_coordinate = rand_coordinate();	//Note: 0 = "to the right", 1 = "Up", 2 = "left" and 3 = "downwards"
		direction = rand_direction();

		valid_position = validate_position(x_coordinate, y_coordinate, direction, player_array, battleship_size);	//checks for valid position

		if (valid_position == 1)	//if valid position is found, validate_position() returns '1', entering statement (see previous line)
		{
			print_ship(battleship_size, x_coordinate, y_coordinate, direction, 'b', player_array);
		}
	}

	///////Cruiser Placement
	valid_position = 0;	//re-initializes position validity to 'false' for next ship placement
	while (valid_position == 0)	//continues to loop until rand() coordinates find a valid placement
	{
		x_coordinate = rand_coordinate(); //gathers random coordinates and direction on the board
		y_coordinate = rand_coordinate();	//Note: 0 = "to the right", 1 = "Up", 2 = "left" and 3 = "downwards"
		direction = rand_direction();

		valid_position = validate_position(x_coordinate, y_coordinate, direction, player_array, cruiser_size);	//checks for valid position

		if (valid_position == 1)	//if valid position is found, validate_position() returns '1', entering statement (see previous line)
		{
			print_ship(cruiser_size, x_coordinate, y_coordinate, direction, 'r', player_array);
		}
	}

	///////Submarine Placement
	valid_position = 0;	//re-initializes position validity to 'false' for next ship placement
	while (valid_position == 0)	//continues to loop until rand() coordinates find a valid placement
	{
		x_coordinate = rand_coordinate(); //gathers random coordinates and direction on the board
		y_coordinate = rand_coordinate();	//Note: 0 = "to the right", 1 = "Up", 2 = "left" and 3 = "downwards"
		direction = rand_direction();

		valid_position = validate_position(x_coordinate, y_coordinate, direction, player_array, submarine_size);	//checks for valid position

		if (valid_position == 1)	//if valid position is found, validate_position() returns '1', entering statement (see previous line)
		{
			print_ship(submarine_size, x_coordinate, y_coordinate, direction, 's', player_array);
		}
	}

	///////Destroyer Placement
	valid_position = 0;	//re-initializes position validity to 'false' for next ship placement
	while (valid_position == 0)	//continues to loop until rand() coordinates find a valid placement
	{
		x_coordinate = rand_coordinate(); //gathers random coordinates and direction on the board
		y_coordinate = rand_coordinate();	//Note: 0 = "to the right", 1 = "Up", 2 = "left" and 3 = "downwards"
		direction = rand_direction();

		valid_position = validate_position(x_coordinate, y_coordinate, direction, player_array, destroyer_size);	//checks for valid position

		if (valid_position == 1)	//if valid position is found, validate_position() returns '1', entering statement (see previous line)
		{
			print_ship(destroyer_size, x_coordinate, y_coordinate, direction, 'd', player_array);
		}
	}
}
		
void manually_place_ships_on_board() //allows the user to place each of the 5 types of ships on his / her game board.
{
	int carrier_size = 5, battleship_size = 4, cruiser_size = 3, submarine_size = 3, destroyer_size = 2;
	int x_coordinate = 0, y_coordinate = 0, direction = 0, valid_position = 0, user_error = 1;

	///////Carrier Placement/////////////////////////////////////
	while (valid_position == 0)	//continues to loop until rand() coordinates find a valid placement
	{
		printf("_____________Carrier Placement_________(Size: 5)_______\n\n");
		while (user_error == 1)
		{
			display_board(player1_board);
			printf("Please enter x coordinate for your ship:\n");
			scanf("%d", &x_coordinate);
			printf("Please enter y coordinate for your ship:\n");
			scanf("%d", &y_coordinate);
			printf("Please enter a direction for your ship (0 = \"to the right\", 1 = \"Up\", 2 = \"left\" and 3 = \"downwards\"):\n");
			scanf("%d", &direction);
			system("cls");
			if (x_coordinate >= 0 && x_coordinate <= 9 && y_coordinate >= 0 && y_coordinate <= 9 &&
				(direction == 0 || direction == 1 || direction == 2 || direction == 3))
			{
				user_error = 0;
			}
			else printf("Error: please enter a coordinate between 0-9 and a direction between 0-3\n");
		}

		valid_position = validate_position(x_coordinate, y_coordinate, direction, player1_board, carrier_size);	//checks for valid position

		if (valid_position == 0)
		{
			printf("Error: these coordinates are invalid, please enter different coordinates:\n");
			user_error = 1;	//re-initializes user_error to 'true' in preperation for re-prompt
		}

		else if (valid_position == 1)
		{
			print_ship(carrier_size, x_coordinate, y_coordinate, direction, 'c', player1_board);
		}
	}
	system("cls");	//clears screen for next ship placement

	///////Battleship Placement/////////////////////////////////
	valid_position = 0;	//re-initializes variable for next ship position
	user_error = 1; //re-initializes user error to true 
	while (valid_position == 0)	//continues to loop until rand() coordinates find a valid placement
	{
		printf("_____________Carrier Placement_________(Size: 4)_______\n\n");
		while (user_error == 1)
		{
			display_board(player1_board);
			printf("Please enter x coordinate for your ship:\n");
			scanf("%d", &x_coordinate);
			printf("Please enter y coordinate for your ship:\n");
			scanf("%d", &y_coordinate);
			printf("Please enter a direction for your ship (0 = \"to the right\", 1 = \"Up\", 2 = \"left\" and 3 = \"downwards\"):\n");
			scanf("%d", &direction);
			system("cls");
			if (x_coordinate >= 0 && x_coordinate <= 9 && y_coordinate >= 0 && y_coordinate <= 9 &&
				(direction == 0 || direction == 1 || direction == 2 || direction == 3))
			{
				user_error = 0;
			}
			else printf("Error: please enter a coordinate between 0-9 and a direction between 0-3\n");
		}

		valid_position = validate_position(x_coordinate, y_coordinate, direction, player1_board, battleship_size);	//checks for valid position

		if (valid_position == 0)
		{
			printf("Error: these coordinates are invalid, please enter different coordinates:\n");
			user_error = 1;	//re-initializes user_error to 'true' in preperation for re-prompt
		}

		else if (valid_position == 1)
		{
			print_ship(battleship_size, x_coordinate, y_coordinate, direction, 'b', player1_board);
		}
	}
	system("cls");	//clears screen for next ship placement

	///////Cruiser Placement////////////////////////////////////
	valid_position = 0;	//re-initializes variable for next ship position
	user_error = 1; //re-initializes user error to true 
	while (valid_position == 0)	//continues to loop until rand() coordinates find a valid placement
	{
		printf("_____________Cruiser Placement_________(Size: 3)_______\n\n");
		while (user_error == 1)
		{
			display_board(player1_board);
			printf("Please enter x coordinate for your ship:\n");
			scanf("%d", &x_coordinate);
			printf("Please enter y coordinate for your ship:\n");
			scanf("%d", &y_coordinate);
			printf("Please enter a direction for your ship (0 = \"to the right\", 1 = \"Up\", 2 = \"left\" and 3 = \"downwards\"):\n");
			scanf("%d", &direction);
			system("cls");
			if (x_coordinate >= 0 && x_coordinate <= 9 && y_coordinate >= 0 && y_coordinate <= 9 &&
				(direction == 0 || direction == 1 || direction == 2 || direction == 3))
			{
				user_error = 0;
			}
			else printf("Error: please enter a coordinate between 0-9 and a direction between 0-3\n");
		}

		valid_position = validate_position(x_coordinate, y_coordinate, direction, player1_board, cruiser_size);	//checks for valid position

		if (valid_position == 0)
		{
			printf("Error: these coordinates are invalid, please enter different coordinates:\n");
			user_error = 1;	//re-initializes user_error to 'true' in preperation for re-prompt
		}

		else if (valid_position == 1)
		{
			print_ship(cruiser_size, x_coordinate, y_coordinate, direction, 'r', player1_board);
		}
	}
	system("cls");	//clears screen for next ship placement

	///////Submarine Placement///////////////////////////////////
	valid_position = 0;	//re-initializes variable for next ship position
	user_error = 1; //re-initializes user error to true 
	while (valid_position == 0)	//continues to loop until rand() coordinates find a valid placement
	{
		printf("_____________Submarine Placement_________(Size: 3)_______\n\n");
		while (user_error == 1)
		{
			display_board(player1_board);
			printf("Please enter x coordinate for your ship:\n");
			scanf("%d", &x_coordinate);
			printf("Please enter y coordinate for your ship:\n");
			scanf("%d", &y_coordinate);
			printf("Please enter a direction for your ship (0 = \"to the right\", 1 = \"Up\", 2 = \"left\" and 3 = \"downwards\"):\n");
			scanf("%d", &direction);
			system("cls");
			if (x_coordinate >= 0 && x_coordinate <= 9 && y_coordinate >= 0 && y_coordinate <= 9 &&
				(direction == 0 || direction == 1 || direction == 2 || direction == 3))
			{
				user_error = 0;
			}
			else printf("Error: please enter a coordinate between 0-9 and a direction between 0-3\n");
		}

		valid_position = validate_position(x_coordinate, y_coordinate, direction, player1_board, submarine_size);	//checks for valid position

		if (valid_position == 0)
		{
			printf("Error: these coordinates are invalid, please enter different coordinates:\n");
			user_error = 1;	//re-initializes user_error to 'true' in preperation for re-prompt
		}

		else if (valid_position == 1)
		{
			print_ship(submarine_size, x_coordinate, y_coordinate, direction, 's', player1_board);
		}
	}
	system("cls");	//clears screen for next ship placement

	///////Destroyer Placement//////////////////////////////////////
	valid_position = 0;	//re-initializes variable for next ship position
	user_error = 1; //re-initializes user error to true 
	while (valid_position == 0)	//continues to loop until rand() coordinates find a valid placement
	{
		printf("_____________Destroyer Placement_________(Size: 2)_______\n\n");
		while (user_error == 1)
		{
			display_board(player1_board);
			printf("Please enter x coordinate for your ship:\n");
			scanf("%d", &x_coordinate);
			printf("Please enter y coordinate for your ship:\n");
			scanf("%d", &y_coordinate);
			printf("Please enter a direction for your ship (0 = \"to the right\", 1 = \"Up\", 2 = \"left\" and 3 = \"downwards\"):\n");
			scanf("%d", &direction);
			system("cls");
			if (x_coordinate >= 0 && x_coordinate <= 9 && y_coordinate >= 0 && y_coordinate <= 9 &&
				(direction == 0 || direction == 1 || direction == 2 || direction == 3))
			{
				user_error = 0;
			}
			else printf("Error: please enter a coordinate between 0-9 and a direction between 0-3\n");
		}

		valid_position = validate_position(x_coordinate, y_coordinate, direction, player1_board, destroyer_size);	//checks for valid position

		if (valid_position == 0)
		{
			printf("Error: these coordinates are invalid, please enter different coordinates:\n");
			user_error = 1;	//re-initializes user_error to 'true' in preperation for re-prompt
		}

		else if (valid_position == 1)
		{
			print_ship(destroyer_size, x_coordinate, y_coordinate, direction, 'd', player1_board);
		}
	}
	system("cls");	//clears screen after ships are placed, end function
}

void print_ship(int ship_size, int x_coordinate, int y_coordinate, int direction, char symbol, char player_board[10][10])
{
	for (int i = 0; i < ship_size; i++)	//Only enters loop once valid position is found, prints respective letter on the board-
	{										//ending when size of ship is met

		if (direction == 0)	//if direction is to the right
		{
			player_board[y_coordinate][x_coordinate + i] = symbol;
		}
		if (direction == 1)	//if direction is upwards
		{
			player_board[y_coordinate - i][x_coordinate] = symbol;
		}
		if (direction == 2)	//if direction is left
		{
			player_board[y_coordinate][x_coordinate - i] = symbol;
		}
		if (direction == 3)	//if direction is downwards
		{
			player_board[y_coordinate + i][x_coordinate] = symbol;
		}
	}	//repeats until size of ship is met
}

int select_who_starts_first()	//selects starting player
{
	int selection = 0;
	selection = (rand() % 2) + 1;
	return selection;
}

int rand_direction()
{
	int direction = 0;
	direction = rand() % 4;
	return direction;
}

int validate_position(int x_coordinate, int y_coordinate, int direction, char player_array[10][10], int ship_size)
{
	int valid_position = 0;
	if (x_coordinate < 10 && y_coordinate < 10)
	{
		for (int i = 0; i < ship_size; i++)
		{
			if (direction == 0)	//directed to the right
			{
				if (x_coordinate + i > 9 || x_coordinate + i < 0)
					break;
				if (player_array[y_coordinate][x_coordinate + i] != '-')
					break;
				if (player_array[y_coordinate][x_coordinate + i] == '-' && (i + 1) == ship_size)
					valid_position = 1;
			}
			if (direction == 1) //directed up
			{
				if (y_coordinate - i > 9 || y_coordinate - i < 0)
					break;
				if (player_array[y_coordinate - i][x_coordinate] != '-')
					break;
				if (player_array[y_coordinate - i][x_coordinate] == '-' && (i + 1) == ship_size)
					valid_position = 1;
			}
			if (direction == 2) //directed left
			{
				if (x_coordinate - i > 9 || x_coordinate - i < 0)
					break;
				if (player_array[y_coordinate][x_coordinate - i] != '-')
					break;
				if (player_array[y_coordinate][x_coordinate - i] == '-' && (i + 1) == ship_size)
					valid_position = 1;
			}
			if (direction == 3)	//directed down
			{
				if (y_coordinate + i > 9 || y_coordinate + i < 0)
					break;
				if (player_array[y_coordinate + i][x_coordinate] != '-')
					break;
				if (player_array[y_coordinate + i][x_coordinate] == '-' && (i + 1) == ship_size)
					valid_position = 1;
			}
		}
	}
	return valid_position;
}

////////////////////////////////////////////////GAMEPLAY//////////////////////////////////////////////////////////////////////////////////

void play_game(int first_player, FILE *infile)//enters game
{
	int x_coordinate = 0, y_coordinate = 0, user_error = 1, valid_position = 0, winner = 0, is_shot = 1;
	char symbol = '\0', prompt = '\0';

	if (first_player == 1)	//if player_1 starts first (single round-no loop)
	{
		while (user_error == 1)
		{
			printf("____________________Player 1: It's your turn!_________________________\n\n");
			display_board(player1_board);
			printf("Your board displayed above\n\n");

			printf("Enemy board displayed below: Take a shot!\n");
			display_board(enemy_board); 

			printf("Enter x coordinate:\n");
			scanf("%d", &x_coordinate);
			printf("Enter y coordinate:\n");
			scanf("%d", &y_coordinate);
			system("cls");
			if (x_coordinate >= 0 && x_coordinate <= 9 && y_coordinate >= 0 && y_coordinate <= 9)
			{
				user_error = 0;
			}
			else printf("Error: please enter a coordinate between 0-9\n");
		}

		symbol = check_shot(player2_board, x_coordinate, y_coordinate);

		if (symbol == '*')
		{
			printf("You got a hit!\n");
			print_symbol(x_coordinate, y_coordinate, symbol, enemy_board);
			print_symbol(x_coordinate, y_coordinate, symbol, player2_board);
		}
		else if (symbol == 'm')
		{
			printf("Sorry, you missed\n");
			print_symbol(x_coordinate, y_coordinate, symbol, enemy_board);

		}
		display_board(enemy_board);
		check_if_sunk_ship();
		output_current_move(infile, "player_1", x_coordinate, y_coordinate, symbol);	//outputs current move to logfile
		system("pause");
		system("cls");
	}

	//if AI starts first, then game continues until winner is detected
	for (int i = 0; (winner = is_winner())== 0; i++)
	{
		/////////////////////////AI////////////////////////////////////
		is_shot = 1;
		while (is_shot == 1)
		{
			x_coordinate = rand_coordinate();
			y_coordinate = rand_coordinate();
			is_shot = previously_taken_shots(player1_board, x_coordinate, y_coordinate);
		}

		symbol = check_shot(player1_board, x_coordinate, y_coordinate);

		if (symbol == '*')
			printf("Your enemy got a hit!\n");

		else if (symbol == 'm')
			printf("Your enemy missed!\n");

		print_symbol(x_coordinate, y_coordinate, symbol, player1_board);
		display_board(player1_board);
		output_current_move(infile, "player_2", x_coordinate, y_coordinate, symbol);	//outputs current move to logfile
		system("pause");
		system("cls");

		////////////////////////////Player 1////////////////////////////
		user_error = 1;	//reinitializes user error to 'true'
		is_shot = 1; //re-initializes is_shot to 'true'
		while (user_error == 1 || is_shot == 1)
		{
			printf("____________________Player 1: It's your turn!_________________________\n\n");
			printf("Enemy board displayed below: Take a shot!\n");
			display_board(enemy_board);
			printf("Enter x coordinate:\n");
			scanf("%d", &x_coordinate);
			printf("Enter y coordinate:\n");
			scanf("%d", &y_coordinate);
			system("cls");
			is_shot = previously_taken_shots(player2_board, x_coordinate, y_coordinate) == 1;

			if (x_coordinate >= 0 && x_coordinate <= 9 && y_coordinate >= 0 && y_coordinate <= 9)
			{
				user_error = 0;
			}
			else if (x_coordinate < 0 || x_coordinate > 9 || y_coordinate < 0 || y_coordinate > 9)
			{
				printf("Error: please enter a coordinate between 0-9\n");
			}
			if (is_shot == 1)
				printf("Error: This shot has already been taken, please choose a different coordinate\n");
		}

		symbol = check_shot(player2_board, x_coordinate, y_coordinate);

		if (symbol == '*')
		{
			printf("You got a hit!\n");
			print_symbol(x_coordinate, y_coordinate, symbol, enemy_board);
			print_symbol(x_coordinate, y_coordinate, symbol, player2_board);
		}
		else if (symbol == 'm')
		{
			printf("Sorry, you missed\n");
			print_symbol(x_coordinate, y_coordinate, symbol, enemy_board);
			print_symbol(x_coordinate, y_coordinate, symbol, enemy_board);
		}
		display_board(enemy_board);
		check_if_sunk_ship();
		output_current_move(infile, "player_1", x_coordinate, y_coordinate, symbol);
		system("pause");
		system("cls");
	}
	if (winner == 1)	//Announces player 1 as winner
	{
		printf("\n\n\n\n\n___________________Player 1... You've Won!____________________\n\n\n");
		printf("Type any character to return to main menu\n");
		scanf(" %c", &prompt);
		system("cls");
	}
	else  //Announces loss to player 1 
	{
		printf("\n\n\n_______________________Player 1... Sorry, you've lost_______________\n\n\n");
		printf("Type any character to return to the main menu\n");
		scanf(" %c", &prompt);
		system("cls");
	}
	fclose(infile);
}

int previously_taken_shots(char enemy[10][10], int x_coordinate, int y_coordinate)
{
	char shot = 0;
	if (enemy[y_coordinate][x_coordinate] == '*' || enemy[y_coordinate][x_coordinate] == 'm')
		shot = 1;
	return shot;
}

int is_winner() //determines if a winner exists (and if so, who has won).
{
	int winner = 0;

	for (int row = 0; row < 10; row++)// checks is player_1 has won
	{
		for (int column = 0; column < 10; column++)	
		{
			if (player2_board[row][column] == 'd' || player2_board[row][column] == 'c' ||
				player2_board[row][column] == 'b' || player2_board[row][column] == 's' ||
				player2_board[row][column] == 'r')
			{
				row = 11;	//allows second loop to break
				break;
			}
			else if (row == 9 && column == 9 && (player2_board[row][column] != 'd' || player2_board[row][column] != 'c' ||
				player2_board[row][column] != 'b' || player2_board[row][column] != 's' ||
				player2_board[row][column] != 'r'))
			{
				winner = 1;
			}
		}
	}

	for (int row = 0; row < 10; row++)// checks is player_2 has won
	{
		for (int column = 0; column < 10; column++)
		{
			if (player1_board[row][column] == 'd' || player1_board[row][column] == 'c' ||
				player1_board[row][column] == 'b' || player1_board[row][column] == 's' ||
				player1_board[row][column] == 'r')
			{
				row = 11;	//allows second loop to break
				break;
			}
			else if (row == 9 && column == 9 && (player1_board[row][column] != 'd' || player1_board[row][column] != 'c' ||
				player1_board[row][column] != 'b' || player1_board[row][column] != 's' ||
				player1_board[row][column] != 'r'))
			{
				winner = 2;
			}
		}
	}

	return winner;
}

char check_shot(char enemy[10][10], int x_coordinate, int y_coordinate)//determines if the shot taken was a hit or a miss.
{
	char symbol = '\0';
	if (enemy[y_coordinate][x_coordinate] == '-')
		symbol = 'm';
	else if (enemy[y_coordinate][x_coordinate] == 'c' || enemy[y_coordinate][x_coordinate] == 'b' || enemy[y_coordinate][x_coordinate] == 'r' ||
		enemy[y_coordinate][x_coordinate] == 's' || enemy[y_coordinate][x_coordinate] == 'd')
		symbol = '*';
	return symbol;
}

void print_symbol(int x_coordinate, int y_coordinate, char symbol, char enemy_board[10][10])
{
	enemy_board[y_coordinate][x_coordinate] = symbol;
}

void check_if_sunk_ship() //determines if carrier, battleship, cruiser, destroyer or submarine was sunk (printing information to user
{
	printf("________Enemy Ships_________\n");
	for (int row = 0; row < 10; row++)	//Destroyer check
	{
		for (int column = 0; column < 10; column++)
		{
			if (player2_board[row][column] == 'd')
			{
				printf("Destroyer: Not sunk\n");
				row = 11;	//allows second loop to break
				break;
			}
			else if (row == 9 && column == 9 && (player2_board[row][column] != 'd'))
			{
				printf("Destroyer: Sunk!\n");
			}
		}
	}

	for (int row = 0; row < 10; row++)	// Carrier check
	{
		for (int column = 0; column < 10; column++)
		{
			if (player2_board[row][column] == 'c')
			{
				printf("Carrier: Not sunk\n");
				row = 11;	//allows second loop to break
				break;
			}
			else if (row == 9 && column == 9 && (player2_board[row][column] != 'c'))
			{
				printf("Carrier: Sunk!\n");
			}
		}
	}

	for (int row = 0; row < 10; row++)	// Battleship check
	{
		for (int column = 0; column < 10; column++)
		{
			if (player2_board[row][column] == 'b')
			{
				printf("Battleship: Not sunk\n");
				row = 11;	//allows second loop to break
				break;
			}
			else if (row == 9 && column == 9 && (player2_board[row][column] != 'b'))
			{
				printf("Battleship: Sunk!\n");
			}
		}
	}

	for (int row = 0; row < 10; row++)	//Cruiser check
	{
		for (int column = 0; column < 10; column++)
		{
			if (player2_board[row][column] == 'r')
			{
				printf("Cruiser: Not sunk\n");
				row = 11;	//allows second loop to break
				break;
			}
			else if (row == 9 && column == 9 && (player2_board[row][column] != 'r'))
			{
				printf("Cruiser: Sunk!\n");
			}
		}
	}

	for (int row = 0; row < 10; row++)	// Submarine check
	{
		for (int column = 0; column < 10; column++)
		{
			if (player2_board[row][column] == 's')
			{
				printf("Submarine: Not sunk\n");
				row = 11;	//allows second loop to break
				break;
			}
			else if (row == 9 && column == 9 && (player2_board[row][column] != 's'))
			{
				printf("Submarine: Sunk!\n");
			}
		}
	}
}

void output_current_move(FILE *infile, char player[8], int x_coordinate, int y_coordinate, char symbol) //writes the position of the shot taken by the current player to the log file
						   //It also writes whether or not it was a hit, miss, and if the ship was sunk.
{
	fprintf(infile, "%c\n", player);	//player
	fprintf(infile, "(%d, %d)\n", x_coordinate, y_coordinate);
	fprintf(infile, "%c\n\n", symbol);
}

//////////////////////////////////////////////MISC FUNCTIONS////////////////////////////////////////////////////////////////////////////////
int rand_coordinate()	//generates random coordinate
{
	int coordinate = 0;
	coordinate = rand() % 10;
	return coordinate;
}

void display_board(char print_array[10][10])
{
	printf("  0 1 2 3 4 5 6 7 8 9\n");
	for (int row = 0; row < 10; row++)
	{
		printf("%d ", row);
		for (int column = 0; column < 10; column++)
		{
			printf("%c ", print_array[row][column]);
			if (column == 9)
				printf("\n");
		}
	}
}
