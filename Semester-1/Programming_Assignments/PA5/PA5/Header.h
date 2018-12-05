#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int game_menu();	//prints game menu and prompts user for options to read rules for Yahtzee, enter a game, or exit 

int print_game_rules(); //Print game rules

void goodbye();	//if player chooses to exit game, prints a small goodbye message

void play_yahtzee();

int final_scoring(int[], int combination);

void roll_dice(int[]);	//rolls 5 dice, inputing each into an array 

int play_round(int []);	//plays each round of Yahtzee, rolling and entering scores into an array for each player

void print_dice_roll(int[]);

int sum_dice(int[]);

void sort_rolls(int[]);

int contains(int[], int);

sum_score(int[]);