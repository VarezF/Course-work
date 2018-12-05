#include "Header.h"

/*
Function: shuffle()
Description: shuffles the deck of cards
Input Parameters: 4x13 empty array
Returns: 4x13 array with randomized numbers 1-52 denoting cards in a deck
*/
void shuffle(int wDeck[4][13])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */

					/* for each of the 52 cards, choose slot of deck randomly */
	for (int card = 1; card <= 52; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}

/*
Function: deal()
Description: deals 5 cards to each player
Input Parameters: randomized deck of cards as well as the cards face and suit. player1 and player2's hands (to hold 5 cards after dealing)
Returns: None (fills address array with cards)
*/
void deal(const int wDeck[4][13], const char *wFace[], const char *wSuit[], Hand *player1_hand, Hand *player2_hand)
{
	for (int card = 1; card <= 5; card++)	//player 1 hand
	{
		/* loop through rows of wDeck */
		for (int row = 0; row < 4; row++)
		{
			/* loop through columns of wDeck for current row */
			for (int column = 0; column < 13; column++)
			{
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card)
				{
					strcpy(player1_hand->card[card - 1].face, wFace[column]);
					strcpy(player1_hand->card[card - 1].suit, wSuit[row]);
				}
			}
		}
	}
	for (int card = 6; card <= 10; card++)
	{
		/* loop through rows of wDeck */
		for (int row = 0; row < 4; row++)
		{
			/* loop through columns of wDeck for current row */
			for (int column = 0; column < 13; column++)
			{
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card)
				{		
					strcpy(player2_hand->card[card - 6].face, wFace[column]);
					strcpy(player2_hand->card[card - 6].suit, wSuit[row]);
				}
			}
		}
	}
	next_card = 10;
}
///////////////////////////////////////Hand composition/scoring Functions///////////////////////////////////////////////////////////////////
/*
Function: is_pair()
Description: Determines if a pair exists within the players hand
Input Parameters: players hand (holding 5 cards) (each a type struct)
Returns: integer truth value: '0' for false (no pair found), or '1' for true (pair found)
*/
int is_pair(Hand player_hand)//determines if the hand contains a pair.
{
	int is_pair = 0;
	for (int n = 0; n < 4; n++)
	{
		for (int i = n + 1; n + i < 5; i++)
		{
			if (strcmp(player_hand.card[n].face, player_hand.card[n + i].face) == 0)
			{
				is_pair = 1;
				n = 5; //allows second for-loop to break 
				break;	//prevents further pairs (multiple pairs are counted in 2_pairs() function)
			}
		}
	}
	return is_pair;
}

/*
Function: is_2_pair()
Description: Determines if two pairs exist within the players hand
Input Parameters: players hand (holding 5 cards) (each a type struct)
Returns: integer truth value: '0' for false (no 2 pairs found), or '1' for true (2 pairs found)
*/
int is_2_pairs(Hand player_hand)//determines if the hand contains two pairs.
{
	int pair_count = 0, is_2_pair = 0;
	for (int n = 0; n < 4; n++)
	{
		for (int i = n + 1; n + i < 5; i++)
		{
			if (strcmp(player_hand.card[n].face, player_hand.card[n + i].face) == 0)
			{
				pair_count += 1;
				if (pair_count == 2)
				{
					is_2_pair = 1;
					n = 5; //allows second for-loop to break 
					break;	//prevents further pairs (multiple pairs are counted in 2_pairs() function)
				}
			}
		}
	}
	return is_2_pair;
}

/*
Function: is_3_of_a_kind()
Description: Determines if 3 of the same types of faces exists within the players hand
Input Parameters: players hand (holding 5 cards) (each a type struct)
Returns: integer truth value: '0' for false (3 of a kind not found), or '1' for true (three of a kind found)
*/
int is_3_of_a_kind(Hand player_hand)//determines if the hand contains three of a kind(e.g.three jacks).
{
	int three_of_a_kind = 0, Ace = 0, Deuce = 0, Three = 0, Four = 0, Five = 0, Six = 0, Seven = 0, Eight = 0,
		Nine = 0, Ten = 0, Jack = 0, Queen = 0, King = 0;
	for (int i = 0; i < 5; i++)
	{
		if (strcmp(player_hand.card[i].face, "Ace") == 0)
			Ace += 1;
		if (strcmp(player_hand.card[i].face, "Deuce") == 0)
			Deuce += 1;
		if (strcmp(player_hand.card[i].face, "Three") == 0)
			Three += 1;
		if (strcmp(player_hand.card[i].face, "Four") == 0)
			Four += 1;
		if (strcmp(player_hand.card[i].face, "Five") == 0)
			Five += 1;
		if (strcmp(player_hand.card[i].face, "Six") == 0)
			Six += 1;
		if (strcmp(player_hand.card[i].face, "Seven") == 0)
			Seven += 1;
		if (strcmp(player_hand.card[i].face,"Eight") == 0)
			Eight += 1;
		if (strcmp(player_hand.card[i].face,"Nine") == 0)
			Nine += 1;
		if (strcmp(player_hand.card[i].face, "Ten") == 0)
			Ten += 1;
		if (strcmp(player_hand.card[i].face, "Jack") == 0)
			Jack += 1;
		if (strcmp(player_hand.card[i].face, "Queen") == 0)
			Queen += 1;
		if (strcmp(player_hand.card[i].face, "King") == 0)
			King += 1;
	}
	if (Ace == 3 || Deuce == 3 || Three == 3 || Four == 3 || Five == 3 || Six == 3 || Seven == 3 ||
		Eight == 3 || Nine == 3 || Ten == 3 || Jack == 3 || Queen == 3 || King == 3)
	{
		three_of_a_kind = 1;
	}
	return three_of_a_kind;
}

/*
Function: is_4_of_a_kind()
Description: Determines if four faces of a kind exists within the players hand
Input Parameters: players hand (holding 5 cards) (each a type struct)
Returns: integer truth value: '0' for false (not found), or '1' for true (found)
*/
int is_4_of_a_kind(Hand player_hand)//determines if the hand contains four of a kind(e.g.four aces).
{
	int four_of_a_kind = 0, Ace = 0, Deuce = 0, Three = 0, Four = 0, Five = 0, Six = 0, Seven = 0, Eight = 0,
		Nine = 0, Ten = 0, Jack = 0, Queen = 0, King = 0;
	for (int i = 0; i < 5; i++)
	{
		if (strcmp(player_hand.card[i].face, "Ace") == 0)
			Ace += 1;
		if (strcmp(player_hand.card[i].face, "Deuce") == 0)
			Deuce += 1;
		if (strcmp(player_hand.card[i].face, "Three") == 0)
			Three += 1;
		if (strcmp(player_hand.card[i].face, "Four") == 0)
			Four += 1;
		if (strcmp(player_hand.card[i].face, "Five") == 0)
			Five += 1;
		if (strcmp(player_hand.card[i].face, "Six") == 0)
			Six += 1;
		if (strcmp(player_hand.card[i].face, "Seven") == 0)
			Seven += 1;
		if (strcmp(player_hand.card[i].face, "Eight") == 0)
			Eight += 1;
		if (strcmp(player_hand.card[i].face, "Nine") == 0)
			Nine += 1;
		if (strcmp(player_hand.card[i].face, "Ten") == 0)
			Ten += 1;
		if (strcmp(player_hand.card[i].face, "Jack") == 0)
			Jack += 1;
		if (strcmp(player_hand.card[i].face, "Queen") == 0)
			Queen += 1;
		if (strcmp(player_hand.card[i].face, "King") == 0)
			King += 1;
	}
	if (Ace == 4 || Deuce == 4 || Three == 4 || Four == 4 || Five == 4 || Six == 4 || Seven == 4 ||
		Eight == 4 || Nine == 4 || Ten == 4 || Jack == 4 || Queen == 4 || King == 4)
	{
		four_of_a_kind = 1;
	}
	return four_of_a_kind;
}

/*
Function: is_flush()
Description: Determines if a flush exists within the players hand
Input Parameters: players hand (holding 5 cards) (each a type struct)
Returns: integer truth value: '0' for false (no pair found), or '1' for true (pair found)
*/
int is_flush(Hand player_hand)//determines if the hand contains a flush(i.e.all five cards of the same suit).
{
	int flush = 0;
	for (int i = 1; i < 5; i++)
	{
		if (strcmp(player_hand.card[0].suit, player_hand.card[i].suit) != 0)
		{
			break;
		}			
		else if (i == 4)
		{
			flush = 1;
		}
	}
	return flush;
}

/*
Function: is_straight()
Description: Determines if a straight exists within the players hand
Input Parameters: players hand (holding 5 cards) (each a type struct)
Returns: integer truth value: '0' for false (no pair found), or '1' for true (pair found)
*/
int is_straight(Hand player_hand)//determines if the hand contains a straight(i.e.five cards of consecutive face values).
{
	int straight = 0, Ace = 0, Deuce = 0, Three = 0, Four = 0, Five = 0, Six = 0, Seven = 0, Eight = 0,
		Nine = 0, Ten = 0, Jack = 0, Queen = 0, King = 0;
	for (int i = 0; i < 5; i++)	//finds type (and amount of each type)
	{
		if (strcmp(player_hand.card[i].face, "Ace") == 0)
			Ace += 1;
		if (strcmp(player_hand.card[i].face, "Deuce") == 0)
			Deuce += 1;
		if (strcmp(player_hand.card[i].face, "Three") == 0)
			Three += 1;
		if (strcmp(player_hand.card[i].face, "Four") == 0)
			Four += 1;
		if (strcmp(player_hand.card[i].face, "Five") == 0)
			Five += 1;
		if (strcmp(player_hand.card[i].face, "Six") == 0)
			Six += 1;
		if (strcmp(player_hand.card[i].face, "Seven") == 0)
			Seven += 1;
		if (strcmp(player_hand.card[i].face, "Eight") == 0)
			Eight += 1;
		if (strcmp(player_hand.card[i].face, "Nine") == 0)
			Nine += 1;
		if (strcmp(player_hand.card[i].face, "Ten") == 0)
			Ten += 1;
		if (strcmp(player_hand.card[i].face, "Jack") == 0)
			Jack += 1;
		if (strcmp(player_hand.card[i].face, "Queen") == 0)
			Queen += 1;
		if (strcmp(player_hand.card[i].face, "King") == 0)
			King += 1;
	}
	if (Ace == 1 && Deuce == 1 && Three == 1 && Four == 1 && Five == 1)	//A-5
	{
		straight = 1;
	}

	if (Deuce == 1 && Three == 1 && Four == 1 && Five == 1 && Six == 1)	//2-6
	{
		straight = 1;
	}

	if (Three == 1 && Four == 1 && Five == 1 && Six == 1 && Seven == 1)	//3-7
	{
		straight = 1;
	}

	if (Four == 1 && Five == 1 && Six == 1 && Seven == 1 && Eight == 1)	//4-8
	{
		straight = 1;
	}

	if (Five == 1 && Six == 1 && Seven == 1 && Eight == 1 && Nine == 1)	//5-9
	{
		straight = 1;
	}

	if (Six == 1 && Seven == 1 && Eight == 1 && Nine == 1 && Ten == 1)	//6-10
	{
		straight = 1;
	}

	if (Seven == 1 && Eight == 1 && Nine == 1 && Ten == 1 && Jack == 1)	//7-J
	{
		straight = 1;
	}

	if (Eight == 1 && Nine == 1 && Ten == 1 && Jack == 1 && Queen == 1)	//8-Q
	{
		straight = 1;
	}

	if (Nine == 1 && Ten == 1 && Jack == 1 && Queen == 1 && King == 1)	//9-K
	{
		straight = 1;
	}

	return straight;
}

/*
Function: print_possible_combinations()
Description: Prints all available combinations to the user
Input Parameters: players hand (holding 5 cards) (each a type struct)
Returns: N/A (prints to screen only)
*/
void print_possible_combinations(Hand player_hand)
{
	printf("You have the following combinations in your hand:\n");

	int combination = 0;

	if (is_pair(player_hand) == 1)
	{
		printf("Pair\n");
		combination += 1;
	}
	if (is_2_pairs(player_hand) == 1)
	{
		combination += 1;
		printf("Two pairs \n");
	}
	if (is_3_of_a_kind(player_hand) == 1)
	{
		printf("Three-of-a-kind\n");
		combination += 1;
	}
	if (is_4_of_a_kind(player_hand) == 1)
	{
		printf("Four-of-a-kind\n");
		combination += 1;
	}
	if (is_flush(player_hand) == 1)
	{
		printf("Flush\n");
		combination += 1;
	}
	if (is_straight(player_hand) == 1)
	{
		printf("Straight\n");
		combination += 1;
	}
	if (combination == 0)
		printf("Sorry, you have no combinations available...\n");
}

/*
Function: determine_better_hand()
Description: Determines which hand is better
Input Parameters: players hand (holding 5 cards) (each a type struct)
Returns: 1 = player1 wins, 2 = player2 wins, 3 = tie between both players
*/
int determine_better_hand(Hand player1_hand, Hand player2_hand)
{
	int winner = 0;	//determines better hand/winner or otherwise. 1 = player1 wins, 2 = player2 wins, 3 = tie
	int player1_points = 0, player2_points = 0;

	///////////////////////////////////////////PLAYER 1 Hand/////////////////////////////////////////
	if (is_4_of_a_kind(player1_hand) == 1)	//Four-of-a-kind (5 points)
		player1_points += 5;
	else if (is_3_of_a_kind(player1_hand) == 1)	//Three-of-a-kind (3 points)
		player1_points += 3;
	
	if (is_straight(player1_hand) == 1)	//Straight (4 points)
		player1_points += 4;

	if (is_2_pairs(player1_hand) == 1)	//Two pairs (2 points)
		player1_points += 2;
	else if (is_pair(player1_hand) == 1)	//One pair (2 points)
		player1_points += 1;

	///////////////////////////////////////////PLAYER 1 Hand/////////////////////////////////////////
	if (is_4_of_a_kind(player2_hand) == 1)	//Four-of-a-kind (5 points)
		player2_points += 5;
	else if (is_3_of_a_kind(player2_hand) == 1)	//Three-of-a-kind (3 points)
		player2_points += 3;

	if (is_straight(player2_hand) == 1)	//Straight (4 points)
		player2_points += 4;

	if (is_2_pairs(player2_hand) == 1)	//Two pairs (2 points)
		player2_points += 2;
	else if (is_pair(player2_hand) == 1)	//One pair (2 points)
		player2_points += 1;

	//////////////////////////////////////////COMPARE////////////////////////////////////
if (player1_points < player2_points)
	winner = 2;
else if (player1_points > player2_points)
winner = 1;
else if (player1_points == player2_points)
winner = 3;

return winner;
}

///////////////////////////////////////GAMEPLAY///////////////////////////////////////////////////////////////////////////////
/*
Function: play_poker()
Description: simulates a round of poker
Input Parameters: player1 and player2's hand (holding 5 cards) (each a type struct), randomized deck as well as suit and face information
Returns: N/A (prints to screen only)
*/
void play_poker(Hand player1_hand, Hand player2_hand, int deck[4][13], char *suit[], char *face[])
{
	int user_error = 1, draw = 0, winner = 0;
	char prompt = '\0';

	print_hand(player1_hand);
	print_possible_combinations(player1_hand);

	////////////////////User preperation///////////////////////////
	while (user_error == 1)	//prompts the user for a chance to redraw some of their cards
	{
		printf("Would you like to redraw some of your cards? (Y/N)\n");
		scanf(" %c", &prompt);
		system("cls");
		if (prompt == 'Y')
		{
			for (int i = 0; i < 3; i++)
			{
				user_error = 1;	//re-initialize user error to 'True'
				while (user_error == 1)
				{
					print_hand(player1_hand);
					printf("Please enter a card you would like to re-draw (or enter '0' to continue)\n");
					scanf(" %d", &draw);
					system("cls");
					if (draw != 0 && draw != 1 && draw != 2 && draw != 3 && draw != 4 && draw != 5)
					{
						printf("Error: please enter an integer 0-5\n");
					}
					if (draw == 0)
						break;
					else
					{
						redraw(&player1_hand, draw, deck, suit, face);
						user_error = 0;
					}
				}
			}
		}
		else if (prompt == 'N')
			user_error = 0;
		else printf("Error: Please Enter Y or N\n");
	}
	system("cls");

	//////////////////////AI PREPERATION////////////////////////////////////////////
	for (int i = 0; i < 3; i++)
	{
		draw = determine_redraw(player2_hand);
		redraw(&player2_hand, draw, deck, suit, face);
	}
	//////////////////////DETERMINE WINNER//////////////////////////////////////////
	winner = determine_better_hand(player1_hand, player2_hand);
	if (winner == 1)
		printf("You win!!\n\n");
	else if (winner == 2)
		printf("Player 2 wins, better luck next time...\n\n");
	else if (winner == 3)
		printf("A tie between you and player 2!\n\n");
	system("pause");
	system("cls");
	printf("Thanks for playing!\n");
}

/*
Function: redraw()
Description: Replaces chosen card with a newly delt card 
Input Parameters: players hand (holding 5 cards) (each a type struct), card# to be re-drawn as well as suit and face information for each card
Returns: N/A (prints to screen only)
*/
void redraw(Hand *player_hand, int draw, int deck[4][13], char *suit[4], char *face[13])
{
	int card = next_card;
	next_card += 1;
	/* loop through rows of wDeck */
	for (int row = 0; row < 4; row++)
	{
		/* loop through columns of wDeck for current row */
		for (int column = 0; column < 13; column++)
		{
			/* if slot contains current card, display card */
			if (deck[row][column] == card)
			{
				strcpy(player_hand->card[draw - 1].face, face[column]);
				strcpy(player_hand->card[draw - 1].suit, suit[row]);
			}
		}
	}
}

/*
Function: determine_redraw()
Description: Acts as AI decision to redraw
Input Parameters: players hand (holding 5 cards) (each a type struct)
Returns: returns card to be re-delt
*/
int determine_redraw(Hand player_hand)
{
	int draw = 0; //determines which card should be redrawn

	if (is_flush(player_hand) == 1 || is_4_of_a_kind(player_hand) == 1 || is_straight(player_hand) == 0 || is_2_pairs(player_hand)
		|| is_3_of_a_kind(player_hand) == 0)
		//does not redraw if flush, straight, or 4-of-a-kind are available
	{
		draw = rand() % 5 + 1;
	}
	return draw;
}

/*
Function: print_hand()
Description: Prints given hand struct	
Input Parameters: players hand (holding 5 cards) (each a type struct)
Returns: N/A (prints to screen only)
*/
void print_hand(Hand player_hand)	//prints player hand
{
	printf("Your Hand:\n");
	for (int i = 0; i < 5; i++)
	{
		printf("%d.) %s of %s\n", i + 1, player_hand.card[i].face, player_hand.card[i].suit);
	}
	printf("\n\n");
}