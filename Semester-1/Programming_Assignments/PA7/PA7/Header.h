#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


/////////////////////////////////////GAME PREPERATION//////////////////////////////
typedef struct card {
	char suit[50];
	char face[50];
}Card;

typedef struct hand {
	Card card[5];
}Hand;

int next_card;

void shuffle(int wDeck[4][13]);

void deal(const int wDeck[4][13], const char *wFace[], const char *wSuit[], Hand *player1_hand, Hand *player2_hand);

/////////////////////////////////////////GAMEPLAY///////////////////////////////////
void play_poker(Hand player1_hand, Hand player2_hand, int deck[4][13], char *suit[], char *face[]);

void redraw(Hand *player_hand, int draw);

void print_hand(Hand player_hand);	//prints player hand

/////////////////////////////////////HAND COMPOSITION FUNCTIONS////////////////////////////////////////
int is_pair(Hand player_hand);//determines if the hand contains a pair.

int is_2_pairs(Hand player_hand);//determines if the hand contains two pairs.

int is_3_of_a_kind(Hand player_hand);//determines if the hand contains three of a kind(e.g.three jacks).

int is_4_of_a_kind(Hand player_hand);//determines if the hand contains four of a kind(e.g.four aces).

int is_flush(Hand player_hand);//determines if the hand contains a flush(i.e.all five cards of the same suit).

int is_straight(Hand player_hand);//determines if the hand contains a straight(i.e.five cards of consecutive face values).

void print_possible_combinations(Hand player_hand);	//prints all valid combinations to the user

int determine_better_hand(Hand player1_hand, Hand player2_hand);	//determines the better hand between the two players




