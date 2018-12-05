#include "Header.h"

/*
description: Prints out the rules of the game of "craps" to the user.
input: N/A
output: N/A
*/
void print_game_rules(void) 
{
	printf("A player rolls two dice.\nEach die has six faces. These faces contain 1, 2, 3, 4, 5, and 6 spots.\
\nAfter the dice have come to rest, the sum of the spots on the two upward faces is calculated.\nIf the sum is 7 or 11 on the first throw, the player wins. \
\nIf the sum is 2, 3, or 12 on the first throw (called \"craps\"), the player loses (i.e.the \"house\" wins). \
\nIf the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's \"point.\
\" \nTo win, you must continue rolling the dice until you \"make your point.\" \nThe player loses by rolling a 7 before making the point.\n\n\n");
}


/*
Description: Prompts the player for an initial bank balance from which wagering will be added or subtracted. 
			 The player entered bank balance(in dollars, i.e.$100.00) is returned.
Input: N/A
Output: Users initial bank account balance
*/
double get_bank_balance(void)
{
	double balance = 0.00;

	printf("Enter bank balance below (USD):\n");
	scanf("%lf", &balance);

	return balance;
}


/*
Description: Prompts the player for a wager on a particular roll. The wager is returned.
Input: N/A
Output: Users bet (wager) for the round
*/
double get_wager_amount(void) //
{
	double wager = 0;

	printf("Enter your wager (USD) below:\n");
	scanf("%lf", &wager);

	return wager;
}


/*
Description: Checks to see if the wager is within the limits of the player's available balance. 
			 If the wager exceeds the player's allowable balance, then 0 is returned; otherwise 1 is returned.
Input: Users wager and account balance
Output: integer truth value corrosponding to whether wager amount is valid
*/
int check_wager_amount(double wager, double balance) //
{
	int acceptable_limit = 0;

	if ((balance - wager) >= 0)
	{
		acceptable_limit = 1;
	}
	return acceptable_limit;
}


/*
Description: Rolls one die.This function should randomly generate a value between 1 and 6, inclusively.
			 Returns the value of the die.
Input: N/A
Output: random value from 1-6
*/
int roll_die(void)
{
	int die = 0;
	char key = '\0';
	
	printf("Press any key to roll the dice. Good Luck!\n");
	scanf(" %c", &key);

	die = (rand() % 6) + 1;

	printf("You rolled a %d\n", die);
	
	return die;
}


/*
Description:Sums together the values of the two dice and returns the result.
			(Note: this result may become the player's point in future rolls.)
Input: Two die values (calculated from the roll_die() function
Output: Sum of the two die values
*/
int calculate_sum_dice(int die1_value, int die2_value) 
{
	int sum = 0;
	sum = die1_value + die2_value;
	return sum;
}


/*
Description: Determines the result of the first dice roll. If the sum is 7 or 11 on the roll, the player wins and 1 is returned.
			 If the sum is 2, 3, or 12 on the first throw (called "craps"), the player loses(i.e.the "house" wins) and 0 is returned.
			 If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's "point" and -1 is returned.
Input: Sum of two dice rolls
Output: If the sum is 7 or 11 on the roll, the player wins and 1 is returned.
		If the sum is 2, 3, or 12 on the first throw (called "craps"), the player loses(i.e.the "house" wins) and 0 is returned.
		If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's "point" and -1 is returned.
*/
int is_win_loss_or_point(int sum_dice)
{
	int win = 0;

	if (sum_dice == 7 || sum_dice == 11)
		win = 1;

	else if (sum_dice == 4 || sum_dice == 5 || sum_dice == 6 || sum_dice == 8 || sum_dice == 9 || sum_dice == 10)
		win = -1;
	
	else win = 0;

	return win;
}


/*
Description: Determines the result of any successive roll after the first roll.			
Input: sum of dice and point_value (sum of previous two rolls, if the user hasn't initially won or lost
Output: If the sum of the roll is the point_value, then 1 is returned.
		If the sum of the roll is a 7, then 0 is returned. 
		Otherwise, -1 is returned.
*/
int is_point_loss_or_neither(int sum_dice, int point_value)
{
	int value = 0;
	if (sum_dice == point_value)
		value = 1;
	else if (sum_dice != 7)
		value = -1;

	return value;
}


/*
Description: If add_or_subtract is 1, then the wager amount is added to the bank_balance.
		     If add_or_subtract is 0, then the wager amount is subtracted from the bank_balance.
			 Otherwise, the bank_balance remains the same.The bank_balance result is returned.
Input: Users current bank balance (after bets won or lost from previous rounds), wager amount, 
	   and variable describing whether the user won or lost the current round
Output: current (updated) bank balance
*/
double adjust_bank_balance(double current_bank_balance, double wager_amount, int add_or_subtract) 
{
	if (add_or_subtract == 1)
		current_bank_balance += wager_amount;
	else if (add_or_subtract == -1)
		current_bank_balance -= wager_amount;

	return current_bank_balance;
}


/*
Description: Prints an appropriate message dependent on the number of rolls taken so far by the player,
			the current balance, and whether or not the player just won his roll.
			The parameter win_loss_neither indicates the result of the previous roll.
Input: Number of rolls, variable describing whether the user has won the current round,
		initial bank balance (before starting the game), and current balance (after won or lost bets from previous rounds)
Output: various "chatter" messages with neccessary information.
*/
void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance)
{
	if (number_rolls == 1 && win_loss_neither == 1)//if the user has won after the forst roll
	{
		printf("Lucky you! You won the round on the first roll!.\n");
		show_balance(initial_bank_balance, current_bank_balance);
	}
	else if (number_rolls == 1 && win_loss_neither == 0)//if the user has lost after the first roll
	{
		printf("Sorry! You busted! \n");
		show_balance(initial_bank_balance, current_bank_balance);
	}
	else if (number_rolls == 1 && win_loss_neither == -1)//if the user has neither won nor lost, and must continue rolling
	{
		printf("You haven't lost yet! Roll again!\n");
		show_balance(initial_bank_balance, current_bank_balance);
	}
	else if (number_rolls > 1 && win_loss_neither == 1)//if the user has won after successive rolls
	{
		printf("You've made your point!\n");
		show_balance(initial_bank_balance, current_bank_balance);
	}
	else if (number_rolls > 1 && win_loss_neither == 0)//if the user has lost after successive rolls
	{
		printf("Ouch! You've rolled a 7 and lost the round.\n");
		show_balance(initial_bank_balance, current_bank_balance);
	}
	else if (number_rolls > 1 && win_loss_neither == -1)//if the user has neither won nor lost, and must continue rolling
	{
		printf("You havent lost yet, take another chance!\n");
		show_balance(initial_bank_balance, current_bank_balance);
	}
}

/*
Description: Prints users current and initial bank balance
Input: initial and current bank balance
Output: N/A
*/
void show_balance(double initial_bank_balance, double current_bank_balance)
{
	printf("Initial Balance: %lf\n", initial_bank_balance);
	printf("Current Balance: %lf\n", current_bank_balance);
}


/*
Description: Prompts the user on whether they would like to play another round
Input: N/A 
Output: returns value to main() if and only if the the user types 'y'
		else, no value is returned and the program ends. 
*/
int continue_prompt(void)
{
	char choice = '\0';
	printf("Would you like to play again? y/n\n");
	scanf(" %c", &choice);
	return choice == 'y';
}