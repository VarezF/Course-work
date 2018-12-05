#include "Header.h"

int main(void)
{
	double initial_bank_balance = 0, current_bank_balance = 0, wager_amount = 0;
	int number_rolls = 0, win_loss_neither = 0;

	print_game_rules();//prints the rules of Craps for the user

	initial_bank_balance = get_bank_balance();//prompts user for initial bank balance (saved for further messeges 

	current_bank_balance = initial_bank_balance;//saves account balance to a second variable for future winnings/losses

	do
	{
		int die1_value = 0, die2_value = 0, sum_dice = 0, point_value = 0, add_or_subtract = 0;

		wager_amount = get_wager_amount();//prompts user for their wager

		while (check_wager_amount(wager_amount, current_bank_balance) == 0)// Checks wager against bank account balance
		{
			printf("Your wager exceeds your current bank balance, please enter another wager\n"); //prompts user for a different wager if account balance is too low
			wager_amount = get_wager_amount();//gets a new wager amount, looping if the wager is, again, too large
		}
		////////////////////////////////////////////////FIRST ROLL///////////////////////////////////////////////
		die1_value = roll_die();//Rolls one die, returning a value between 1-6

		die2_value = roll_die();//Rolls one die, returning a value between 1-6

		number_rolls++;//adds 1 to rolls to enter second loop for further rolls (see below)

		sum_dice = calculate_sum_dice(die1_value, die2_value);//- Sums together the values of the two dice and returns the result.
														//Note: this result may become the player's point in future rolls.


		if (is_win_loss_or_point(sum_dice) == 1) //Determines the result of the first dice roll.If the sum is 7 or 11 on the roll, the player wins and 1 is returned.
		{
			add_or_subtract = 1;
			win_loss_neither = 1;
			current_bank_balance = adjust_bank_balance(current_bank_balance, wager_amount, add_or_subtract);
			chatter_messages(number_rolls, win_loss_neither, initial_bank_balance, current_bank_balance);
		}
		else if (is_win_loss_or_point(sum_dice) == 0)//If the sum is 2, 3, or 12 on the first throw (called "craps"), the player loses(i.e.the "house" wins) and 0 is returned.
											
		{

			add_or_subtract = -1;
			win_loss_neither = 0;
			current_bank_balance = adjust_bank_balance(current_bank_balance, wager_amount, add_or_subtract);
			chatter_messages(number_rolls, win_loss_neither, initial_bank_balance, current_bank_balance);
		}
		else//If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's "point" and -1 is returned.
		{
			point_value = sum_dice;
			win_loss_neither = -1;
			chatter_messages(number_rolls, win_loss_neither, initial_bank_balance, current_bank_balance);
			/////////////////////////////////SUCCESSIVE ROLLS/////////////////////////////////////////////////////////

			while (1)//loop for successive rolls, continues until
			{
				die1_value = roll_die();//rolls second set of dice
				die2_value = roll_die();

				number_rolls++;//increments dice roll counter

				sum_dice = calculate_sum_dice(die1_value, die2_value);//calculates sum of the two die (see above rolls)

				if (is_point_loss_or_neither(sum_dice, point_value) == 1)//If the sum of the roll is the point_value, then 1 is returned, the player wins the round																		 
				{
					add_or_subtract = 1;
					current_bank_balance = adjust_bank_balance(current_bank_balance, wager_amount, add_or_subtract);
					chatter_messages(number_rolls, win_loss_neither, initial_bank_balance, current_bank_balance);
					break;
				}

				else if (is_point_loss_or_neither(sum_dice, point_value) == 0)//If the sum of the roll is a 7, then 0 is returned, the player loses
				{
					add_or_subtract = -1;
					current_bank_balance = adjust_bank_balance(current_bank_balance, wager_amount, add_or_subtract);
					chatter_messages(number_rolls, win_loss_neither, initial_bank_balance, current_bank_balance);
					break;
				}//Otherwise, -1 is returned, and the player re-enters the loop, re-rolling until a win or loss

			}

		}
	} while (continue_prompt());

	return 0;
}
