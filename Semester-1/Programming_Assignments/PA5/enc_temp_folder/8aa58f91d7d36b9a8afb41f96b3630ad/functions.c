#include "Header.h"

int game_menu()//(5 pts) Print a game menu for Yahtzee with the following options: 1.Print game rules, 2. Start a game of Yahtzee, 3. Exit                      
{
	int user_input = 0;
	while (user_input != 3)
	{
		printf("__________________Welcome to Yahtzee!_____________________\n\n"	//prints menu screen 
			"Game Menu... please type one of the following options:\n"
			"1. Print game rules\n"
			"2. Start a game of Yahtzee!\n"
			"3. Exit\n");
		scanf(" %d", &user_input);	//prompts user for input 1, 2 or 3 (see above printf() statement
		system("CLS");	//Clears screen for information respective to input
		if (user_input == 1)	//If user chooses to "Print game Rules"
		{
			printf("You entered \"1\", printing game rules:\n\n");	//Reaffirms input for user
			print_game_rules();	//prints game rules, see print_game_rules() for more information
			user_input = 0; //Resets input to zero for continuation of loop
		}
		else if (user_input == 2)	//If user chooses to "Start a game of Yahtzee!"
		{
			printf("You entered \"2\". Starting a game of Yahtzee!\n");	//reaffirms input for user
			play_yahtzee();	//Calls function to play Yahtzee (see below play_yahtzee() function for more info			
			user_input = 0; //resets user input to 0 for continuation of loop
		}
	}//If user input is "Exit", user_input = 3, break and return to main for goodbye() function
	return 0;
}

int print_game_rules()//basic print function containing rules for Yahtzee
{
	char continue_prompt = 0;
	printf("////////////////////RULES///////////////////////\nThe scorecard used for Yahtzee is composed of two sections.\n"
		"An upper section and a lower section for a total of thirteen boxes or thirteen scoring combinations are divided amongst the sections.\n"
		"The upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box.\n"
		"If a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which is 12.\n"
		"Once a player has chosen to score a box, it may not be changed and the combination is no longer in play for future rounds.\n"
		"If the sum of the scores in the upper section is greater than or equal to 63, then 35 more points are added to the players overall score as a bonus.\n"
		"The lower section contains a number of poker like combinations. See below:\n\n"
		"______Name________________Combination________________________Score______\n"
		"Three-of-a-kind        Three dice with the same face      Sum all 5 dice\n"
		"Four-of-a-kind          Four dice with the same face       Sum of all 5 dice\n"
		"Full House              One pair and three-of-a-kind            25          \n"
		"Small straight           A sequence of four dice                30          \n"
		"Large Straight           A sequence of five dice                40          \n"
		"Yahtzee                  Five dice with the same face           50          \n"
		"Chance                  May be used for any sequence      Sum of the all 5 dice\n"
		"________________________________________________________________________________\n\n");
	printf("Press any key to return to game menu\n");
	scanf(" %c", &continue_prompt);	//prompts the user to go back to main menu screen
	system("CLS");
	return continue_prompt;
}

void play_yahtzee()
{
	char main_menu = 0, roll_prompt = 0;
	int player1_score[14] = { 0 }, player2_score[14] = { 0 },
		player1_combinations[12] = { 0 }, player2_combinations[12] = { 0 };

	for (int i = 1; i <= 14; i++)
	{		
		printf("Starting round %d, player 1 begin!\n\n", i);
		player1_score[i-1] = play_round(player1_combinations);
			
		printf("Starting round %d, player 2 begin!\n\n", i);
		player2_score[i-1] = play_round(player2_combinations);
				
	}
/*
	(8) (5 pts) Alternate players
	(9) (10 pts) If each player has rolled for the round, then increment the round number
			 if the round number is equal to 14, then continue on to step (10)
			 otherwise repeat step (4)
		 otherwise repeat step (4)
	(10) (5 pts) If the total score in the upper section is greater than or equal to 63 for a player, then add 35 points to the total score
	(11) (5 pts) Print the scores for both players and print the winner
	(12) (5 pts) Repeat step (1)*/

	printf("Press any key to return to main menu\n");
	scanf(" %c", &main_menu);
	system("CLS");
}

int play_round(int combinations[])
{
	char user_prompt = '\0', roll_prompt = '\0';
	int dice[5] = { 0 }, combination_prompt = 0, score = 0;
	printf("press any key to roll");
	scanf(" %c", &roll_prompt);
	roll_dice(dice);
	system("CLS");
	for (int i = 1; i <= 3; i++)
	{
		print_dice_roll(dice);

		printf("1. Sum of 1's        7. Three-of-a-kind\n"
			   "2. Sum of 2's        8. Four-of-a-kind\n"
			   "3. Sum of 3's        9. Full house\n"
			   "4. Sum of 4's        10. Small straight\n"
			   "5. Sum of 5's        11. Large straight\n"
			   "6. Sum of 6's        12. Yahtzee\n"
			   "13. Chance\n");
		printf("Note: You have the following combinations left:\n");
		for (int i = 0; i <= 12; i++)
		{
			if (combinations[i] == 0)
				printf("%d, ", i+1);
		}
		printf("\nWould you like to select a combination? (Y/N)\n");
		scanf(" %c", &user_prompt);
		if (user_prompt == 'Y' || i == 3)
		{
			printf("Please choose from the above combinations\n");	//prompts the user for one of the above combinations
			scanf(" %d", &combination_prompt);
			while ((combination_prompt < 1 || combination_prompt > 13) || combinations[combination_prompt - 1] == 1)	//checks for user error
			{
				printf("You have entered an invalid combination, ( you have either not entered one of the above combinations (integer between 1-13)\n"
					"Or you have already chosen this combination");	//if user error is detected, re-prompts the user
				scanf(" %d", &combination_prompt);	
			}
			score += final_scoring(dice, combination_prompt);
			combinations[combination_prompt - 1] = 1;
			break;
		}
		else if (user_prompt == 'N')
		{
			char prompt = 1;
			for (int i = 0; i < 5; i++)
			{
				printf("Would you like to re-roll this dice (Y/N)?: %d\n\n", dice[i]);
				scanf(" %c", &prompt);
				if (prompt == 'Y')
				{
					dice[i] = rand() % 6 + 1;
				}
			}

		}
	
	}
	/*(7) (15 pts) If the number of rolls is three or "yes" is entered, then save the combination and it may not be selected again in the future
			  (Note: The selection of the combination must be verified. If the user selects full house, but does not have one, then your
			   must assign 0 points for the combination); 
			  continue on to step (8); clear the screen
		 otherwise if "no" is entered, ask the user which dice to re-roll (1 - 5); re-roll the selected die or dice; clear the screen; 
			 repeat step (6)
		 otherwise repeat step (6)*/
	printf("You gained %d points!\n", score);
	return score;
}

int final_scoring(int dice[], int combination)
{
	int score = 0;
	sort_rolls(dice);
	if (combination == 1)
	{
		for (int i = 0; i <= 4; i++)
		{
			if (dice[i] = 1)
				score += 1;
		}
	}
	if (combination == 2)
	{
		for (int i = 0; i <= 4; i++)
		{
			if (dice[i] = 2)
				score += 2;
		}
	}
	if (combination == 3)
	{
		for (int i = 0; i <= 4; i++)
		{
			if (dice[i] = 3)
				score += 3;
		}
	}
	if (combination == 4)
	{
		for (int i = 0; i <= 4; i++)
		{
			if (dice[i] = 4)
				score += 4;
		}
	}
	if (combination == 5)
	{
		for (int i = 0; i <= 4; i++)
		{
			if (dice[i] = 5)
				score += 5;
		}
	}
	if (combination == 6)
	{
		for (int i = 0; i <= 4; i++)
		{
			if (dice[i] = 6)
				score += 6;
		}
	}
	if ((combination == 7) && ((dice[0] == dice[1] && dice[1] == dice[2])	//Three-of-a-kind
		|| (dice[1] == dice[2] && dice[2] == dice[3])
		|| (dice[2] == dice[3] && dice[3] == dice[4])))
		{		
			score = sum_dice(dice);
		}
	if ((combination == 8) && ((dice[0] == dice[1] && dice[1] == dice[2] && dice[2] == dice[3])	//Four-of-a-kind
		|| (dice[1] == dice[2] && dice[2] == dice[3] && dice[3] == dice[4])))
		{
			score += sum_dice(dice);
		}
	if (combination == 9 && (((dice[0] == dice[1] && dice[1] == dice[2] && dice[3] == dice[4])	//Full house
		|| (dice[2] == dice[3] && dice[3] == dice[4] && dice[0] == dice[1]))))
		{
			score += 25;
		}
	if (combination == 10 && ((contains(dice, 1) && contains(dice, 2) && contains(dice, 3) && contains(dice, 4))
		|| (contains(dice, 2) && contains(dice, 3) && contains(dice, 4) && contains(dice, 5))
		|| (contains(dice, 3) && contains(dice, 4) && contains(dice, 5) && contains(dice, 6))))	//Small straight
		{
			score += 30;
		}
	if (combination == 11 && ((contains(dice, 1) && contains(dice, 2) && contains(dice, 3) && contains(dice, 4) && contains(dice, 5))
		|| (contains(dice, 2) && contains(dice, 3) && contains(dice, 4) && contains(dice, 5) && contains(dice, 6))))	//Large straight
		{
			score += 40;
		}
	if (combination == 12 && (dice[0] == dice[1] && dice[1] == dice[2] && dice[2] == dice[3] && dice[3] == dice[4])) //Yahtzee
		{
			score += 50;
		}
	if (combination == 13)	//Chance
		score += sum_dice(dice);
	return score;
}

int sum_dice(int dice[])
{
	int sum = 0;
	for (int i = 0; i <= 4; i++)
	{
		sum += dice[i];
	}
	return sum;
}

void sort_rolls(int dice[])	//bubble sort
{
	int temp = 0;
	for (int i = 0; i < 4; i++)
	{
		if (dice[i] > dice[i + 1])
		{
			temp = dice[i];
			dice[i] = dice[i + 1];
			dice[i + 1] = temp;
		}
	}
}

int contains(int dice[], int value)
{
	int contains = 0;
	for (int i = 0; i <= 4; i++)
	{
		if (dice[i] == value)
		{
			contains = 1;
			break;
		}		
	}
	return contains;
}

void roll_dice(int dice[])
{
	for (int i = 0; i <= 4; i++)
	{
		dice[i] = (rand() % 6) + 1;
	}
}

void print_dice_roll(int dice[])
{
	for (int i = 0; i <= 4; i++)
	{
		if (i == 0)
			printf("You rolled the following:\n");
		printf("%d.)%d\n", i + 1, dice[i]);
		if (i == 4)
			printf("______________________________________\n\n");
	}
}

void goodbye()
{
	printf("Thanks for playing Yahtzee!\n");
}