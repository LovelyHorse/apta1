/***********************************************************************
* COSC1076 - Advanced Programming Techniques
* Semester 2 2015 Assignment #1
* Full Name        : EDIT HERE
* Student Number   : EDIT HERE
* Course Code      : EDIT HERE
* Program Code     : EDIT HERE
* Start up code provided by Paul Miller
***********************************************************************/
#include "player.h"

/**
 * @param human the human player to initialise
 **/
enum input_result get_human_player(struct player* human)
{

	char userName[(NAMELEN + 2)];
	int uLength;


	printf("%s\n", "What's yo name dawg?");

	fgets(userName, (NAMELEN + 2) , stdin);

	uLength = strlen(userName) - 1;
	if (userName[uLength] == '\n'){
		userName[uLength] = '\0';
	}
	printf("\e[1;1H\e[2J");
	printf("Thanks, %s.\n", userName);

	/* construct player */
	strcpy(human->name, userName);
	human->thiscolor = C_WHITE;
	human->counters = 0;
	human->type = HUMAN;



    return SUCCESS;
}

/**
 * @param computer the computer player to initialise
 **/
enum input_result get_computer_player(struct player * computer)
{
	char compName[NAMELEN] = "computer\o";
    /* initialise all variables that are part of the struct to sensible
     * values */
	computer->thiscolor = C_RED;
	strcpy(computer->name, compName);
	computer->counters = 0;
	computer->type = COMPUTER;

    return FAILURE;
}

enum input_result take_turn(struct player * current,
        enum cell_contents board[BOARDHEIGHT][BOARDWIDTH])
{
	if (current->type == HUMAN){

		char input[3];
		char *end;
		int selection;
		int iLength;
		int count = -1;
		int row;

		/* Collect line input details from user */
		do {
			/* Ensure valid selection*/
			do {
				printf("%s\n", "Pick a column from 1 to 7:");

				/* Get user selection & clear line*/
				fgets(input, 3 , stdin);

				/* Format and fix newline chars */
				iLength = strlen(input) - 1;
				if (input[iLength] == '\n'){
					input[iLength] = '\0';
				}

				/* Convert read input string to int */
				selection = (int) strtol(input, &end, 10);

				/* Log to console user selection and change board */

				printf("You selected: %d\n", selection);

			} while ( (1 > selection) || (selection > 7) );


    		for (row = 0; row < 6; row++){
    			if (board[row][selection] == C_EMPTY) {
    				count = count + 1;
    			}
    		}

	   } while(count < -1);

	   /* Valid move selected */
	   printf("%s\n", "This is a valid move.");

	   board[count][selection] = current->thiscolor;

	} else if (current->type == COMPUTER){
		/* generate random number.*/
		int count = -1;
		int row;
		int col;

		printf("%s\n", "It's the computers turn.");
		/* returns a random number between 1 & 7 */

		/* select random column, test all rows to ensure it's valid */
		do {
			col = randomnum(7);
			for (row = 0; row < 6; row++){
    			if (board[row][col] == C_EMPTY) {
    				count = count + 1;
    			}
    		}

		} while (count > -1);
		/* Set the computer players action */
		board[count][col] = current->thiscolor;
	}

	/* End of turn */
}
