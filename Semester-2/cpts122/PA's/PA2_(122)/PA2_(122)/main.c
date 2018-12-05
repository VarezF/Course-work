#include "Header.h"

int main()
{
	Node *pHead = NULL, *pTail = NULL;	
	Record newSong = { '\0' };

	int choice = 0;
	while (choice != 11)
	{
		choice = menu();
		if (choice == 1)	
		{
			pHead = NULL;	//(re)initialize pHead to NULL to reload data
			load(&pHead);
		}
		else if (choice == 2)
			store(pHead);
		else if (choice == 3)		
			display(pHead);
		else if (choice == 4)
			insert(&pHead);
		else if (choice == 5)	
			deletion(&pHead);
		else if (choice == 6)
			edit(&pHead);
		else if (choice == 7)	
			sort(&pHead);
		else if (choice == 8)
			rate(&pHead);
		else if (choice == 9)
			play(pHead);
		else if (choice == 10)
			shuffle(pHead);
	}
	exitPlayer(pHead);
	return 0;
}
