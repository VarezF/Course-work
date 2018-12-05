#include <stdio.h>
#include <math.h>


void print_game_rules(void); // Prints out the rules of the game of "craps".

double get_bank_balance(void); //Prompts the player for an initial bank balance from which wagering will be added or subtracted. 
							   //The player entered bank balance(in dollars, i.e.$100.00) is returned.

double get_wager_amount(void); //Prompts the player for a wager on a particular roll.The wager is returned.

int check_wager_amount(double wager, double balance); //- Checks to see if the wager is within the limits of the player's available balance. 
													  //If the wager exceeds the player's allowable balance, then 0 is returned; otherwise 1 is returned.

int roll_die(void);//Rolls one die.This function should randomly generate a value between 1 and 6, inclusively.
				   //Returns the value of the die.

int calculate_sum_dice(int die1_value, int die2_value); //- Sums together the values of the two dice and returns the result.
														//Note: this result may become the player's point in future rolls.

int is_win_loss_or_point(int sum_dice);// - Determines the result of the first dice roll.If the sum is 7 or 11 on the roll, the player wins and 1 is returned.
									   //If the sum is 2, 3, or 12 on the first throw (called "craps"), the player loses(i.e.the "house" wins) and 0 is returned.If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's "point" and -1 is returned.

int is_point_loss_or_neither(int sum_dice, int point_value);//- Determines the result of any successive roll after the first roll.
															//If the sum of the roll is the point_value, then 1 is returned.If the sum of the roll is a 7, then 0 is returned.Otherwise, -1 is returned.

double adjust_bank_balance(double current_bank_balance, double wager_amount, int add_or_subtract); //If add_or_subtract is 1, then the wager amount is added to the bank_balance.
																						   //If add_or_subtract is 0, then the wager amount is subtracted from the bank_balance.
																						   //Otherwise, the bank_balance remains the same.The bank_balance result is returned.

void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance); //Prints an appropriate message dependent on the number of rolls taken so far by the player,
																														//the current balance, and whether or not the player just won his roll.
																														//The parameter win_loss_neither indicates the result of the previous roll.
void show_balance(double initial_bank_balance, double current_bank_balance);

int continue_prompt(void);
//(10 pts) Others ?

/*(20 pts) A main() function that makes use of the above functions in order to play the game of craps as explained above.
Note that you will most likely have a loop in your main() function(or you could have another function that loops through the game play).*/