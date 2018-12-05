#include "Header.h"


int main(void)
{
	/* initialize suit array */
	const char *suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	/* initialize face array */
	const char *face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };

	/* initalize deck array */
	int deck[4][13] = { 0 };

	/*Initialize player hands */
	Hand player1_hand = { {"\0"} };
	Hand player2_hand = { {"\0"} };

	srand((unsigned)time(NULL)); /* seed random-number generator */

	shuffle(deck);
	deal(deck, face, suit, &player1_hand, &player2_hand);

	play_poker(player1_hand, player2_hand, deck, suit, face);

	return 0;
}
