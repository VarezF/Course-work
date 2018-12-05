#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

/**********************************************************************************************
* Programmer: Freya Varez                                                                     *
* Class: CptS 122, Summer 2018; Lab Section 1											      *
* Programming Assignment: PA2																  *
* Date: June 18, 2018                                                                         *
* Description: This program prints acts as a basic music player							      *
***********************************************************************************************/

typedef int bool;
enum {false, true};

typedef struct length
{
	int min;
	int sec;
}Length;

typedef struct record
{
	char artist[25];
	char album[25];
	char song[25];
	char genre[25];
	Length songLength;
	int timePlayed;
	int rating;
}Record;

typedef struct node
{
	Record songDetails;
	struct Node *pNext;
	struct Node *pPrev;
}Node;

/*
function:menu()
Details: Prints main menu to user and allows use to choose one of the following options:
	(1) load, (2) store, (3) display, (4) insert, (5) delete, (6) edit, (7) sort, (8) rate, (9) play, (10) shuffle, and (11) exit. 
Input: N/A
Output: Users choice denoted as an integer (see above)
*/
int menu();

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
bool load(Node **pHead);

/*
function: searchNode()
Details: Searches for a given node based on an artists name, if multiple nodes are found, prompts user fro correct node
Input: Pointer to start of linked list and character array holding artist to be searched
Output: Pointer to node matching artist
*/
Node *searchNode(Node *pHead, char strSearch[25]);

/*
function: store()
Details: The “store” command writes the current records, in the dynamic doubly linked list, to the musicPlayList.csv file. 
	The store will completely overwrite the previous contents in the file.
Input: pointer beginning of linked list containing record information
Output: success or failure
*/
bool store(Node *pHead);

/*
function: display()
Details:  prints records to the screen. Supports two methods, one of which is selected by the user:
		1.    Print all records. 
		2.    Print all records that match an artist. 
Input: pointer to head of array
Output: success or failure
*/
bool display(Node *pHead);

/*
function: edit()
Details: allows the user to find a record in the list by artist. 
	If there are multiple records with the same artist, then your program prompts the user which one to edit. 
	The user may modify all of the attributes in the record. 
Input: pointer to head of linked list
Output: success or failure
*/
bool edit(Node **pHead);

/*
function: rate()
Details: allows the user to assign a value of 1 – 5 to a song; 1 is the lowest rating and 5 is the highest rating. 
	The rating will replace the previous rating.
Input: pointer to head of linked list
Output: success or failure
*/
bool rate(Node **pHead);

/*
function: play()
Details: allows the user to select a song to start “playing” each song in order from the current song. 
		(“Playing” displays the contents of the record that represents the song for a short period of time, 
		clearing the screen and showing the next record in the list, etc. This continues until all songs have been played.)
Input: pointer to linked list of songs
Output: success or failure
*/
bool play(Node *pHead);

/*
function: exit()
Details:The “exit” command saves the most recent list to the musicPlayList.csv file. 
	This command will completely overwrite the previous contents in the file.
Input: pointer to linked lists
Output: success or failure
*/
void exitPlayer(Node *pHead);

/*
function: makeNewNode()
Details: Creates new node in cases where Linked list is currently empty
Input: Data to be added to node
Output: pointer to new node
*/
Node *makeNewNode(Record songDetails);

void insertAtFront(Node **pHead, Record newRecord);
////////////////////Part 2 of assingment///////////////////////

/*
function: insert()
Details: prompts the user for details of a new record. The prompt requests the artist name, album title, song title,
genre, song length, number of times played, and rating. The new record is then inserted at the front of the list.
Input: pointer to head of linked list
Output: N/A
*/
void insert(Node **pHead);

/*
function: deletion()
Details: Prompts the user for a song title, removing the matching record from the list.
If the song title does not exist, then the list remains unchanged.
Input: indirect pointer to start of list
Output: N/A
*/
void deletion(Node **pHead);

/*
function: sort()
Details: Prompts the user for 4 different methods to sort the records in the list. These include:
1.    Sort based on artist (A-Z)
2.    Sort based on album title (A-Z)
3.    Sort based on rating (1-5)
4.    Sort based on times played (largest-smallest)
Once a sort method is selected by the user, the sort is performed on the records in the list.
Input: indirect pointer to start of list
Output: N/A
*/
void sort(Node **pHead);

/*
function: shuffle()
Details:  provides a random order in which the songs are played (does not modify the links in the list, simply the order played).
Input: indirect pointer to list
Output: N/A
*/
void shuffle(Node *pHead);

///////////////////////////////////Misc helper functions/////////////
/*
function: move()
Details: Assists shuffle() in moving to next node in randomized list
Input: pointer to current node, number of steps to be taken
Output: N/A (position of pCur is changed indirectly through address of pCur)
*/
void move(Node **pCur, int steps);

/*
function: printNode()
Details: prints current node
Input: pointer to current node
Output: N/A
*/
void printNode(Node *pCur);

/*
function: switchNodes()
Details: switches two nodes passed in
Input: indirect pointer to two nodes (to be switched
Output: N/A
*/
void switchNodes(Node **p1, Node **p2);

/*
function: isSorted()
Details: Assists sort(). Returns a bollean true/false if the two given nodes are in the correct order based on user choice of sorting method
Input: pointers to two nodes, userChoice (denoting the sorting method chosen by the user in the sort() function)
Output: boolean true (if the nodes are sorted), false otherwise
*/
bool isSorted(Node *p1, Node *p2, int userChoice);