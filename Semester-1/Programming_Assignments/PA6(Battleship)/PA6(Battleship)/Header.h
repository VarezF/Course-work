#include <stdio.h>
#include <math.h>
 
/////////////Globally defined matrices///////////////////////////////////////////////////////////////////////////////
char player1_board[10][10];	//Players board

char player2_board[10][10];	//AI board

char enemy_board[10][10];	//players view of enemy board, representing successful hits and misses 

/////////////////Menu Screen//////////////////////////////////////////////////////////////////////////////////////////
/*
Function: welcome_screen()
Description: Menu and user prompt to enter a game of Battleship, view rules, or exit game (returns to menu screen after each game
Input Parameters: None
Returns: None
Preconditions: None
Postconditions: None
*/
void welcome_screen(); //displays an initial program welcome message along with the rules of Battleship.

/*
Function: print_rules()
Description: prints Battleship rules to user upon prompt
Input Parameters: None
Returns: None
Preconditions: User enters option 2 (view rules) from Menu screen
Postconditions: None
*/
void print_rules(); //Prints Battleship rules for the user

/////////////////Game Preperation///////////////////////////////////////////////////////////////////////////////////
/*
Function: prepare_game()
Description: prepares game, initializing boards, opening battleship.log file etc (see below functions in Game Preperation section)
Input Parameters: None
Returns: None
Preconditions: User enters option 1 (play Game) from menu screen 
Postconditions: None
*/
int prepare_game();	//function containing the preperation functions below

/*
Function: initialize_game_board()
Description: (re-)initializes player1_board and player2_board to show empty 'ocean', readied for ship placement
Input Parameters: None
Returns: None
Preconditions: None
Postconditions: None
*/
void initialize_game_board(); //sets each cell in a game board to '-'.

/*
Function: ship_placement_prompt()
Description: prompts user to automatically or randomly place ships, and calling below functions as neccessary
Input Parameters: None
Returns: None
Preconditions: None
Postconditions: None
*/
void ship_placement_prompt();

/*
Function: rand_direction()
Description: generates random direction (up, down, left or right) for ship placement
Input Parameters: None
Returns: random number 0,1,2 or 3 denoting direction right, up, left and down respectively
Preconditions: None
Postconditions: None
*/
int rand_direction();

/*
Function: select_who_starts_first()
Description: generates random number 1 or 2 denoting player 1 and player 2 respectively to start the first round
Input Parameters: None
Returns: random number 1 or 2
Preconditions: None
Postconditions: None
*/
int select_who_starts_first(); //determines if Player1 or Player2 goes first in the game.

/*
Function: manually_place_ships on board()
Description: Allows user to manually place ships on the board
Input Parameters: None
Returns: None
Preconditions: User chooses to place ships manually from ship_placement_prompt()
Postconditions: None
*/
void manually_place_ships_on_board(); //allows the user to place each of the 5 types of ships on his / her game board.

/*
Function: randomly_place_ships_on_board()
Description: randomly places ships on board
Input Parameters: player_array[10][10] denoting the array to which ships will be randomly placed
Returns: None
Preconditions: 
Postconditions: None
*/
void randomly_place_ships_on_board(); //randomly places the 5 types of ships on a given board.

/*
Function: print_ship()
Description: prints specified ship to specified board
Input Parameters: ship size, (x,y) coordinate of ship placement, direction of ship, ships symbol (c,r,s etc.) and array to which ship will be printed
Returns: None
Preconditions: none
Postconditions:None
*/
void print_ship(int ship_size, int x_coordinate, int y_coordinate, int direction, char symbol, char player_array[10][10]); //prints ship to board

//////////////////Play Game//////////////////////////////////////////////////////////////////////////////////////////
void play_game(int first_player);	//enters game

char check_shot(char player_board, int x_coordinate, int y_coordinate);

void print_symbol(int x_coordinate, int, char, char *enemy_board[10][10]);//updates the board every time a shot is taken. 
																			//'*' indicates a hit and 'm' indicates a miss.
int is_winner(); //determines if a winner exists.

void display_board(char [10][10]); //displays a board to the screen.Note that Player1's board should be displayed differently 
									//than Player2's board(see above).
void output_current_move(); //writes the position of the shot taken by the current player to the log file.
							//It also writes whether or not it was a hit, miss, and if the ship was sunk.
void check_if_sunk_ship(); //determines if a ship was sunk.

void output_stats(); //writes the statistics collected on each player to the log file.

/////////////////////MISC Functions/////////////////////////////////////////////////////////////////////////////////
int rand_coordinate();

int validate_position(int x_coordinate, int y_coordinate, int direction, char player_array[10][10], int ship_size);
