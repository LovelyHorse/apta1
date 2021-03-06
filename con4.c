/***********************************************************************
* COSC1076 - Advanced Programming Techniques
* Semester 2 2015 Assignment #1
* Full Name        : Keaton Okkonen
* Student Number   : s3432651
* Course Code      : COSC1076
* Program Code     : BP094
* Start up code provided by Paul Miller
***********************************************************************/
#include "con4.h"

int main(void)
{
    /* clear console */
    printf("\e[1;1H\e[2J");

    /* the scoreboard for keeping track of winners */
    scoreboard scores;
    init_scoreboard(scores);

    /* the two players and a pointer to who won the last game */
    struct player human_player, computer_player, *winner;
	char input[3];
	char *end;
	int iLength;
	int selection;
    int mode = 1;
    /* mode setting specifies the current status of the program, outisde of game play:
     * 1 - active
     * 0 - exit
     */

    do {
        /*display menu and get menu choice until the user chooses to quit */

    	printf("\n%s\n%s\n%s\n%s\n%s\n%s\n",
    			"Welcome to Connect 4",
    			"--------------------",
    			"1. Play Game",
    			"2. Display High Scores",
    			"3. Quit",
    			"Please enter your choice:");

    	/* Get user selection & clear line*/
    	fgets(input, 3 , stdin);

    	/* Format and fix newline chars */
    	iLength = strlen(input) - 1;
    	if (input[iLength] == '\n'){
    		input[iLength] = '\0';
    	}

    	/* Convert read input string to int */
    	selection = (int) strtol(input, &end, 10);

    	/* Log to console user selection */
    	printf("You selected: %d\n", selection);

    	/* Process selection and call appropriate methods */
    	switch(selection){
    		/* play a game option */
    		case 1 :

    			printf("\e[1;1H\e[2J");
    			printf(" - %d | play game \n", selection);

                winner = play_game(&human_player, &computer_player);
                /* game will return the game result, with player and board */

                if (winner) {
                    add_to_scoreboard(scores, winner);
                }
    			break;

    		/* display the scoreboard option */
    		case 2  :
    		   display_scores(scores);
    		   break;

    		/* quit the program option */
    		case 3  :
                printf("%s\n", "Hope you enjoyed yo game, 'G.");
                mode = 0;
                break;

    		default : /* Optional */
    			/* default code here */
    			printf("%s\n", "you a basic bitch");
    			break;
    	}
    } while (mode == 1);

    return EXIT_SUCCESS;
}
