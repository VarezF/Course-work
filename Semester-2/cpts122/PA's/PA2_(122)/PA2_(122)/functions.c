#include "Header.h"

/*
function:menu()
Details: Prints main menu to user and allows use to choose one of the following options:
(1) load, (2) store, (3) display, (4) insert, (5) delete, (6) edit, (7) sort, (8) rate, (9) play, (10) shuffle, and (11) exit.
Input: N/A
Output: Users choice denoted as an integer (see above)
*/
int menu()
{
	int choice = 0;
	while (choice < 1 || choice > 11)
	{
		printf("_________________Main Menu__________________________________\n"
			"|		1.)  Load\n"
			"|		2.)  Store\n"
			"|		3.)  Display\n"
			"|		4.)  Insert\n"
			"|		5.)  Delete\n"
			"|		6.)  Edit\n"
			"|		7.)  Sort\n"
			"|		8.)  Rate\n"
			"|		9.)  Play\n"
			"|		10.) Shuffle   ,-.        _.---._                   \n"
			"|		11.) Exit     /  `\.__.-''       `.                  \n");

		printf(			"|                            \  _        _  ,.   \                 \n"
			"|      ,+++=._________________)_||______|_|_||    |                \n"
			"|     (_.ooo.===================||======|=|=||    |                \n"
			"|         ~~'                 |  ~'      `~' o o  /                \n"
			"|                             \   /~`\     o o  /                  \n"
			"|                              `~'    `-.____.-'                   \n");
			

		scanf(" %d", &choice);
		system("cls");
		if (choice < 1 || choice > 11)
			printf("Error: Please enter an integer 1-11\n");
	}
	return choice;
}

/*
function: load()
Details: read records from a file called musicPlayList.csv into a dynamic doubly linked list. Each record consists of the following attributes
	(Each attribute, in a single record, is separated by a comma in the .csv file):
		Artist – a string
		Album title – a string
		Song title – a string
		Genre – a string
		Song length - a struct Duration type consisting of seconds and minutes, both integers
		Number times played – an integer
		Rating – an integer (1 – 5)
Input: pointer to head of doubly linked list
Output: success or failure
*/
bool load(Node **pHead)
{	
	FILE *infile = NULL;
	infile = fopen("musicPlaylist.csv", "r");	//opens infile for mode read

	bool success = false;
	char line[100] = { '\0' }, *token = NULL, nullLine[25] = { '\0' };
	Record songDetails = { {'\0'} };

	if (infile != NULL)
	{
		while (!feof(infile))
		{
			fgets(&line, 100, infile);	//extract and assign data to temporary record struct
			if (strcmp(line, nullLine) != 0)
			{
				token = strtok(line, ",");
				if (token[0] == '"')	//if the artists name is two strings of form "last, first"
				{
					strncpy(&songDetails.artist, token + 1, 25);	//copies in token exluding first character (")
					strcat(&songDetails, ",");	//concatenates the first and last name (seperated by a comma
					strcat(&songDetails.artist, token = strtok(NULL, ","));
					songDetails.artist[strlen(songDetails.artist) - 1] = '\0';
				}
				else  //artists name is a single string
				{
					strncpy(&songDetails.artist, token, 25);
				}

				strcpy(&songDetails.album, strtok(NULL, ","));

				strcpy(&songDetails.song, strtok(NULL, ","));

				strcpy(&songDetails.genre, strtok(NULL, ","));

				token = strtok(NULL, ":");
				songDetails.songLength.min = atoi(token);

				token = strtok(NULL, ",");
				songDetails.songLength.sec = atoi(token);

				token = strtok(NULL, ",");
				songDetails.timePlayed = atoi(token);

				token = strtok(NULL, "\n");
				songDetails.rating = atoi(token);

				if (*pHead == NULL)	//create first node
					*pHead = makeNewNode(songDetails);
				else  //add node to front of linked list
					insertAtFront(pHead, songDetails);
				line[0] = '\0';
			}
		}
		Node *pCur = *pHead;
		while (pCur != NULL)	//connects last node with pHead 
		{
			if (pCur->pNext == NULL)	//finds the last node
			{
				(*pHead)->pPrev = pCur;
				pCur->pNext = *pHead;
				break;	//connects the last node and exits
			}
			pCur = pCur->pNext;
		}
		success = 1;
	}
	if (success != 0)
	{
		printf("File was successfully read\n");
		system("pause");
		system("cls");
	}

	fclose(infile);
	return success;
}

/*
function: searchNode()
Details: Searches for a given node based on an artists name, if multiple nodes are found, prompts user fro correct node
Input: Pointer to start of linked list and character array holding artist to be searched
Output: Pointer to node matching artist
*/
Node *searchNode(Node *pHead, char searchStr[25])
{
	Node *pCur = pHead, *matches[20] = { NULL };	//Initialize pCur to pHead and creates array to store pointers to matching songs
	int totalMatches = 0, matchIndex = 0;

	while (pCur != NULL)
	{
		if (strcmp(pCur->songDetails.artist, searchStr) == 0 || strcmp(pCur->songDetails.song, searchStr) == 0)	//check for match with artist or song title
		{
			matches[matchIndex] = pCur;	//stores address of matching node in array
			totalMatches++;
			printf("Match #%d\n", matchIndex + 1);
			printNode(pCur);	//print current node
			matchIndex++;
		}
		if (pCur == pHead->pPrev)	//if on the last node, break (stop printing)
			break;
		pCur = pCur->pNext;	//move to next node
	}

	Node *finalChoice = NULL;
	int userChoice = 0;

	if (totalMatches == 0)
	{
		printf("Sorry, there are no records matching your search: \"%s\"\n", searchStr);
		return NULL;
	}
	else if (totalMatches > 1)	//if multiple songs were nodes, prompt user for for correct node
	{
		printf("Your search returned multiple records, please choose one of the above (by match number):\n");
		scanf("%d", &userChoice);
		finalChoice = matches[userChoice - 1];
	}
	else finalChoice = matches[0];	//if only one song matched

	system("cls");
	return finalChoice;
}

/*
function: store()
Details: The “store” command writes the current records, in the dynamic doubly linked list, to the musicPlayList.csv file.
The store will completely overwrite the previous contents in the file.
Input: pointer beginning of linked list containing record information
Output: success or failure
*/
bool store(Node *pHead)
{
	FILE *outfile = NULL;	//(re)initializes outfile to NULL
	outfile = fopen("musicPlaylist.csv", "w");

	Node *pCur = pHead;
	if (outfile != NULL)
	{
		while (pCur != NULL)
		{
			if(strchr(pCur->songDetails.artist, ',') != NULL)	//if name is in the form 'Last, First' add quotes around name
				fprintf(outfile, "\"%s\",",pCur->songDetails.artist);
			else
				fprintf(outfile, "%s,", pCur->songDetails.artist);
			fprintf(outfile, "%s,", pCur->songDetails.album);
			fprintf(outfile, "%s,", pCur->songDetails.song);
			fprintf(outfile, "%s,", pCur->songDetails.genre);
			fprintf(outfile, "%d:%d,", pCur->songDetails.songLength.min, pCur->songDetails.songLength.sec);
			fprintf(outfile, "%d,", pCur->songDetails.timePlayed);
			fprintf(outfile, "%d\n", pCur->songDetails.rating);

			if (pCur == pHead->pPrev)	//if on the last node, break (stop printing)
				break;
			pCur = pCur->pNext;	//move to next node
		}
	}
	else printf("Error: Could not print to file");
}

/*
function: display()
Details:  prints records to the screen. Supports two methods, one of which is selected by the user:
	1.    Print all records.
	2.    Print all records that match an artist.
Input: pointer to head of array
Output: success or failure
*/
bool display(Node *pHead)
{
	bool success = true;
	Node *pCur = pHead;
	int userChoice = 0;	//prompt user
	while (1)
	{
		printf("Choose one of the following options:\n1.) Print all records\n2.) Print records matching an artist\n");
		scanf(" %d", &userChoice);
		system("cls");
		if (userChoice == 1 || userChoice == 2)
			break;
		else
			printf("Error, please enter '1' or '2'\n\n");
	}

	if (userChoice == 1)	//Print all records
	{
		while (pCur != NULL)
		{
			printNode(pCur);	//Print current node
			if (pCur == pHead->pPrev)	//if on the last node, break (stop printing)
				break;
			pCur = pCur->pNext;	//move to next node
		}
	}
	else //Print records matching specified artist
	{
		pCur = pHead;	//(re)initialize pCur to pHead
		int totalMatches = 0;
		char artistSearch[25] = { "\0" };
		printf("Enter an artist below:\n");	//prompts user for artist they would like to search
		scanf(" %[^\n]s", &artistSearch);
		system("cls");

		while (pCur != NULL)
		{
			if (strcmp(pCur->songDetails.artist, artistSearch) == 0)
			{
				totalMatches++;
				printf("Artist:     %s\n", pCur->songDetails.artist);	//Print current node8
				printf("Album:      %s\n", pCur->songDetails.album);
				printf("Song:       %s\n", pCur->songDetails.song);
				printf("Genre:      %s\n", pCur->songDetails.genre);
				printf("Length:     %d:%d\n", pCur->songDetails.songLength.min, pCur->songDetails.songLength.sec);
				printf("Played:     %d times\n", pCur->songDetails.timePlayed);
				printf("Rating:     %d\n\n", pCur->songDetails.rating);
			}
			if (pCur == pHead->pPrev)	//if on the last node, break (stop printing)
				break;
			pCur = pCur->pNext;	//move to next node
		}
		if(totalMatches == 0)
			printf("Sorry, there are no artists matching your search: \"%s\"\n", artistSearch);
	}

	system("pause");
	system("cls");
	return success;
}

/*
function: edit()
Details: allows the user to find a record in the list by artist.
	If there are multiple records with the same artist, then your program prompts the user which one to edit.
	The user may modify all of the attributes in the record.
Input: pointer to head of linked list
Output: success or failure
*/
bool edit(Node **pHead)	
{
	char artistSearch[25] = { "\0" };
	int userChoice = 0;

	printf("Enter an artist below:\n");	//prompts user for node they would like to edit 
	scanf(" %[^\n]s", artistSearch);	//Gets users input including spaces
	system("cls");

	Node *finalChoice = searchNode(*pHead, artistSearch);

	if (finalChoice == NULL)
		return;

	printf("Please choose one of the following attributes to modify\n");
	printf("1.)Artist:     %s\n", finalChoice->songDetails.artist);	//Print current node
	printf("2.)Album:      %s\n", finalChoice->songDetails.album);
	printf("3.)Song:       %s\n", finalChoice->songDetails.song);
	printf("4.)Genre:      %s\n", finalChoice->songDetails.genre);
	printf("5.)Length:     %d:%d\n", finalChoice->songDetails.songLength.min, finalChoice->songDetails.songLength.sec);
	printf("6.)Played:     %d times\n", finalChoice->songDetails.timePlayed);
	printf("7.)Rating:     %d\n", finalChoice->songDetails.rating);

	scanf(" %d", &userChoice);
	system("cls");
		
	if (userChoice == 1)	//change artist
	{
		printf("Artist:     %s\n\n", finalChoice->songDetails.artist);
		printf("Enter the new artist name:\n");
		scanf(" %[^\n]s", finalChoice->songDetails.artist);	//Gets user input including spaces
		system("cls");
	}
	else if (userChoice == 2)	//change album
	{
		printf("Album:      %s\n\n", finalChoice->songDetails.album);
		printf("Enter new album title:\n");
		scanf(" %[^\n]s", finalChoice->songDetails.album);	//Gets user input including spaces
		system("cls");
	}
	else if (userChoice == 3)	//change song
	{
		printf("Song:       %s\n\n", finalChoice->songDetails.song);
		printf("Enter new song title:\n");
		scanf(" %[^\n]s", finalChoice->songDetails.song);	//Gets user input including spaces
		system("cls");
	}
	else if (userChoice == 4)	//change genre
	{
		printf("Genre:      %s\n\n", finalChoice->songDetails.genre);
		printf("Enter new genre:\n");
		scanf(" %[^\n]s", finalChoice->songDetails.genre);
		system("cls");
	}
	else if (userChoice == 5)	//change Length
	{
		printf("Length:     %d:%d\n\n", finalChoice->songDetails.songLength.min, finalChoice->songDetails.songLength.sec);
		printf("Enter song length:\nmin:");
		scanf(" %d", finalChoice->songDetails.songLength.min);
		printf("seconds:");
		scanf(" %d", finalChoice->songDetails.songLength.sec);
		system("cls");
	}
	else if (userChoice == 6)	//change times played
	{
		printf("Played:     %d times\n\n", finalChoice->songDetails.timePlayed);
		printf("Enter times played:\n");
		scanf(" %d", finalChoice->songDetails.timePlayed);
		system("cls");
	}
	else if (userChoice == 7)	//chnage rating
	{
		printf("Rating:     %d\n\n", finalChoice->songDetails.rating);
		printf("Enter new rating:\n");
		scanf(" %d", finalChoice->songDetails.rating);
		system("cls");
	}
	printf("Successfully edited\n");
	system("pause");
	system("cls");
	return true;
}

/*
function: rate()
Details: allows the user to assign a value of 1 – 5 to a song; 1 is the lowest rating and 5 is the highest rating.
	The rating will replace the previous rating.
Input: pointer to head of linked list
Output: success or failure
*/
bool rate(Node **pHead)
{
	char userChoice = '\0';
	Node *pCur = *pHead;
	while(pCur != NULL)
	{
		printf("Would you like to rate this song Y/N\n");
		printf("%s\n", pCur->songDetails.song);
		scanf(" %c", &userChoice);
		if (userChoice == 'Y')
		{
			printf("Enter new rating:\n");
			scanf(" %d", &(pCur->songDetails.rating));
		}
		if (pCur == (*pHead)->pPrev)	//if on the last node, break 
			break;
		pCur = pCur->pNext;	//move to next node
		system("cls");
	}
	printf("Successfulle edited\n");
	system("pause");
	system("cls");
}

/*
function: play()
Details: allows the user to select a song to start “playing” each song in order from the current song.
	(“Playing” displays the contents of the record that represents the song for a short period of time,
	clearing the screen and showing the next record in the list, etc. This continues until all songs have been played.)
Input: pointer to linked list of songs
Output: success or failure
*/
bool play(Node *pHead)
{
	Node *pCur = pHead;
	int choice = 0;
	if (pCur == NULL)
	{
		printf("Error: Your music file is empty, try 'Load'\n");
		return;
	}
	printf("Choose one of the following options:\n1.) Play all songs\n2.) Play from a searched song\n");
	scanf("%d", &choice);
	system("cls");

	if (choice == 1)
	{
		while (pCur != NULL)
		{
			printNode(pCur);
			Sleep(1500);	//"plays" each song for 1.5 seconds 
			system("cls");	//clears screen for next song
			if (pCur == pHead->pPrev)	//if on the last node, break (stop printing)
				break;
			pCur = pCur->pNext;	//move to next node
		}
	}
	else if (choice == 2)
	{
		char artistSearch[25] = { "\0" };

		printf("Enter an artist below:\n");	//prompts user for node they would like to play/start playlist
		scanf(" %[^\n]s", artistSearch);	//Gets users input including spaces
		system("cls");

		Node *finalChoice = searchNode(pHead, artistSearch);
		
		if (finalChoice == NULL)	//if no songs were found return to main menu
			return;

		printNode(finalChoice);	//Print users final node choice

		Sleep(1500);	//"plays" each song for 1.5 seconds 
		system("cls");	//clears screen for next song

		pCur = pHead;
		while (pCur != NULL)
		{
			if (pCur == finalChoice)	//continues playlist, this time ignoring users choice 
				pCur = pCur->pNext;
			else
			{
				printNode(pCur);
				Sleep(2000);	//"plays" each song for 3 seconds 
				system("cls");	//clears screen for next song
				if (pCur == pHead->pPrev)	//if on the last node, break (stop printing)
					break;
				pCur = pCur->pNext;	//move to next node
			}
		}
	}
	system("pause");
	system("cls");
}

/*
function: exit()
Details:The “exit” command saves the most recent list to the musicPlayList.csv file.
	This command will completely overwrite the previous contents in the file.
Input: pointer to linked lists
Output: N/A
*/
void exitPlayer(Node *pHead)
{
	store(pHead);
}

/////////////////////////////////////////////////////Assignment Part 2/////////////////////////////////////////////////////////////////////////////////
/*
function: insert()
Details: prompts the user for details of a new record. The prompt requests the artist name, album title, song title, 
	genre, song length, number of times played, and rating. The new record is then inserted at the front of the list.
Input: pointer to head of linked list
Output: N/A
*/
void insert(Node **pHead)
{
	Record newData = { {'\0'} };

	printf("Enter artist below:\n");	//prompts user for new artist
	scanf(" %[^\n]s", &newData.artist);	//Gets users input including spaces
	system("cls");

	printf("Enter album title below:\n");	//prompts user for new album title
	scanf(" %[^\n]s", &newData.album);	//Gets users input including spaces
	system("cls");

	printf("Enter song title below:\n");	//prompts user for new song title
	scanf(" %[^\n]s", &newData.song);	//Gets users input including spaces
	system("cls");

	printf("Enter genre below:\n");	//prompts user for new genre
	scanf(" %[^\n]s", &newData.genre);	//Gets users input including spaces
	system("cls");

	printf("Enter song length below:\nmin: ");	//prompts user for new input
	scanf(" %d", &newData.songLength.min);	//Gets users input (min)
	printf("\nsec: ");
	scanf(" %d", &newData.songLength.sec);	//Gets users input (sec)
	system("cls");

	printf("Enter number of times played below:\n");	//prompts user for new input
	scanf(" %d", &newData.timePlayed);	//Gets users input (number of times played)
	system("cls");

	printf("Enter rating below:\n");	//prompts user for new input
	scanf(" %d", &newData.rating);	//Gets users input (number of times played)
	system("cls");

	Node *pMem = makeNewNode(newData);	//returns pointer to allocated memory

	if (*pHead == NULL)	//if list is null, assign pHead only, 
		*pHead = pMem;
	else if ((*pHead)->pPrev == NULL)	//if only one node exists
	{
		(*pHead)->pPrev = pMem;
		pMem->pNext = *pHead;
		pMem->pPrev = *pHead;
		(*pHead)->pNext = pMem;
		*pHead = pMem;
	}
	else    //if 2 or more nodes exist (new node must be inserted bewtween existing nodes
	{
		Node *pTail = (*pHead)->pPrev;	//temporary pointer made in order to seperate linked "circle" (seperated between pHead and pTail)
		pTail->pNext = pMem;
		pMem->pPrev = pTail;
		(*pHead)->pPrev = pMem;
		pMem->pNext = *pHead;
		*pHead = pMem;	//moves pHead pointer to newly made node
	}
}

/*
function: deletion()
Details: Prompts the user for a song title, removing the matching record from the list. 
	If the song title does not exist, then the list remains unchanged.
Input: indirect pointer to start of list
Output: N/A
*/
void deletion(Node **pHead)
{
	if (*pHead != NULL)
	{
		char songSearch[25] = { '\0' };
		printf("Enter the song you would like to delete below:\n");	//prompts user for node they would like to edit 
		scanf(" %[^\n]s", songSearch);	//Gets users input including spaces
		system("cls");

		Node *deletion = searchNode(*pHead, songSearch);
		
		if (deletion != NULL)
		{
			if (deletion->pNext == NULL && deletion->pPrev == NULL)	//if deletion node is the only node
			{
				*pHead = NULL;	//list is now empty, pHead is set to NULL
				free(deletion);
			}
			else if (deletion->pNext == deletion->pPrev)	//if only 2 nodes exist
			{
				if (deletion == *pHead)	//if pHead is deletion node, move to new node
					*pHead = (*pHead)->pNext;
				free(deletion);
				(*pHead)->pNext = NULL;	//since only one node exists after deletion, pNext and pPrev are set to NULL
				(*pHead)->pPrev = NULL;
			}
			else  //if there are 3 or more nodes (thus deletion node is between existing nodes
			{
				Node *pTemp1 = deletion->pPrev, *pTemp2 = deletion->pNext;	//temporary pointers to nodes beside deletion node
				if (deletion == *pHead)
					*pHead = deletion->pNext;	//if deletion node was pHead, move pHead to new node
				free(deletion);
				pTemp1->pNext = pTemp2;
				pTemp2->pPrev = pTemp1;
			}
			printf("successfully deleted\n");
		}
		else printf("Error: deletion unsuccessful\n");
	}
	system("pause");
	system("cls");
}

/*
function: sort()
Details: Prompts the user for 4 different methods to sort the records in the list. These include:
		1.    Sort based on artist (A-Z)
		2.    Sort based on album title (A-Z)
		3.    Sort based on rating (1-5)
		4.    Sort based on times played (largest-smallest)
	Once a sort method is selected by the user, the sort (using bubble sort) is performed on the records in the list. 
Input: indirect pointer to start of list
Output: N/A
*/
void sort(Node **pHead)
{
	int userChoice = 0;
	printf("Please choose one of the following sorting options:\n"	//prompt user for sorting method
		"1.    Sort based on artist (A-Z)\n"
		"2.    Sort based on album title (A-Z)\n"
		"3.    Sort based on rating (1-5)\n"
		"4.    Sort based on times played (largest-smallest)\n");
	scanf(" %d", &userChoice);
	system("cls");

	if (*pHead != NULL)
	{
		if ((*pHead)->pNext == NULL && (*pHead)->pPrev == NULL)	//if only one node exists
		{
			printf("List successfully sorted\n");
			system("pause");
			system("cls");
			return;
		}
		//////////////////////////////////////////////////////////////////sorting functions///////(bubble sort)/////////////

		int length = 1;
		Node *pCur = *pHead;
		for (; pCur != (*pHead)->pPrev; length++, pCur = pCur->pNext);	//calculates the length of the linked list to assist bubble sort algorithms below
													////Note: function dealing with one node is above (at this point, 2 nodes must exist)

		for (int i = 0; i < length; i++)
		{
			Node *p1 = *pHead, *p2 = (*pHead)->pNext;
			while (p2 != *pHead)
			{
				if (!isSorted(p1, p2, userChoice))
				{
					switchNodes(&p1, &p2);
					if ((*pHead) == p2)	//if p1 was switched, pHead is switched as well
						*pHead = p1;
				}
				p1 = p1->pNext;
				p2 = p2->pNext;
			}
		}
		printf("List successfully sorted\n");
		system("pause");
		system("cls");
		return;
	}
	printf("Your playlist is empty, try loading\n");
	system("pause");
	system("cls");
}

/*
function: shuffle()
Details:  provides a random order in which the songs are played (does not modify the links in the list, simply the order played).
Input: indirect pointer to list
Output: N/A
*/
void shuffle(Node *pHead)
{
	if (pHead != NULL)
	{
		Node *pCur = pHead;
		int playlist[100];	//array of integers corrosponding to nodes in the linked list (max 100)(integers to be randomized later)
		int listSize = 0;

		for (int i = 0; pCur != NULL; i++)
		{
			listSize++;
			playlist[i] = i;	//adds integer value to each index (corrosponding to a node in the linked list)

			if (pCur->pNext == pHead)	//if at last node
				break;
			else pCur = pCur->pNext;
		}

		int temp = 0, swap1 = 0, swap2 = 0;
		for (int i = 0; i < listSize; i++)	//swaps indexes in array corrosponding to the size of the array
		{
			swap1 = rand() % listSize;
			swap2 = rand() % listSize;

			temp = playlist[swap1];
			playlist[swap1] = playlist[swap2];
			playlist[swap2] = temp;
		}
		
		int steps = 0;

		move(&pCur, 0 - playlist[0]);	//move to first position (in shuffled playlist)

		for (int i = 0; i < listSize - 1; i++)
		{
			printNode(pCur);	//print current node
			Sleep(1500);	//pauses program for 1.5 sec to "play" the song
			steps = playlist[i] - playlist[i + 1];
			move(&pCur, steps);	//move to next song in shuffled playlist
		}
		printNode(pCur);
	}
	else printf("Error: no music currently loaded\n");
	system("pause");
	system("cls");
}

//////////////////////////////////////////////MISC helper functions/////////////////////////////////////////////////
/*
function: printNode()
Details: prints current node
Input: pointer to current node
Output: N/A
*/
void printNode(Node *pCur)
{
	printf("Artist:     %s\n", pCur->songDetails.artist);	//Print current node
	printf("Album:      %s\n", pCur->songDetails.album);
	printf("Song:       %s\n", pCur->songDetails.song);
	printf("Genre:      %s\n", pCur->songDetails.genre);
	printf("Length:     %d:%d\n", pCur->songDetails.songLength.min, pCur->songDetails.songLength.sec);
	printf("Played:     %d times\n", pCur->songDetails.timePlayed);
	printf("Rating:     %d\n\n", pCur->songDetails.rating);
}

/*
function: makeNewNode()
Details: Creates new node in cases where Linked list is currently empty
Input: Data to be added to node
Output: pointer to new node
*/
Node *makeNewNode(Record newRecord)
{
	Node *pMem = NULL;

	pMem = (Node *)malloc(sizeof(Node));

	strcpy(pMem->songDetails.album, newRecord.album);
	strcpy(pMem->songDetails.artist, newRecord.artist);
	strcpy(pMem->songDetails.song, newRecord.song);
	strcpy(pMem->songDetails.genre, newRecord.genre);
	pMem->songDetails.songLength.min = newRecord.songLength.min;
	pMem->songDetails.songLength.sec = newRecord.songLength.sec;
	pMem->songDetails.timePlayed = newRecord.timePlayed;
	pMem->songDetails.rating = newRecord.rating;

	pMem->pNext = NULL;
	pMem->pPrev = NULL;

	return pMem;
}

/*
function: inserAtFront()
Details: Inserts new node at front of linked list
Input: pointer to first node in the linked list and Data to be added to node
Output: N/A
*/
void insertAtFront(Node **pHead, Record newRecord)
{
	Node *pMem = makeNewNode(newRecord);
	pMem->pPrev = NULL;
	(*pHead)->pPrev = pMem;
	pMem->pNext = *pHead;
	*pHead = pMem;
}

/*
function: move()
Details: Assists shuffle() in moving to next node in randomized list
Input: pointer to current node, number of steps to be taken 
Output: N/A (position of pCur is changed indirectly through address of pCur)
*/
void move(Node **pCur, int steps)
{
	if (steps < 0)	//move "right" (to higher numbered nodes)
	{
		for (; steps < 0; steps++)	//move n steps "right" to next node in playlist
		{
			*pCur = (*pCur)->pNext;
		}
	}
	else //move "left" (to lower numbered nodes)
	{
		for (; steps > 0; steps--)	//move n steps "left" to previous node in playlist
		{
			*pCur = (*pCur)->pPrev;
		}
	}
}

/*
function: switchNodes()
Details: switches two nodes passed in
Input: indirect pointer to two nodes (to be switched
Output: N/A
*/
void switchNodes(Node **p1, Node **p2)
{
	Node *p0 = (*p1)->pPrev, *p3 = (*p2)->pNext;

	p0->pNext = *p2;
	(*p2)->pPrev = p0;
	(*p2)->pNext = *p1;
	(*p1)->pPrev = *p2;
	(*p1)->pNext = p3;
	p3->pPrev = *p1;

	*p1 = *p2;
	*p2 = (*p1)->pNext;
}

/*
function: isSorted()
Details: Assists sort(). Returns a bollean true/false if the two given nodes are in the correct order based on user choice of sorting method
Input: pointers to two nodes, userChoice (denoting the sorting method chosen by the user in the sort() function)
Output: boolean true (if the nodes are sorted), false otherwise
*/
bool isSorted(Node *p1, Node *p2, int userChoice)
{
	if (userChoice == 1)	//sort based on artist
		return strcmp(p1->songDetails.artist, p2->songDetails.artist) < 0;
	else if (userChoice == 2)	//sort based on album title
		return strcmp(p1->songDetails.album, p2->songDetails.album) < 0;
	else if (userChoice == 3)	//sort based on rating
		return p1->songDetails.rating < p2->songDetails.rating;
	else if (userChoice == 4)	//sort based on times played
		return p1->songDetails.timePlayed > p2->songDetails.timePlayed;
}