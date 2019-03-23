/**
 * Does all of the work for history command in the shell.
 *
 * @author Evert Ball
 * @author Garrett Starkey
 *
 * @version 03/22/2019
 */
#include <stdio.h>
#include <strings.h>
#include <string.h>
#define HIST_SIZE 40

//Defines a static array to hold the commands entered
static char commands[HIST_SIZE][100];
char buffer[100];
int count = 0;

/**
 * Adds the command entered by the user on the shell into array that holds
 * the history of commands
 *
 * @param executedCommand the command executed by the user
 */
void add_history(char** executedCommand){
    
    //makes the buffer to hold the commands zero
    bzero(buffer, 100);
    //a C boolean
    int aBool = 1;
    int i;
    
    //While the next part of the command is not null
    while(*executedCommand != NULL) {
        //if this is the first piece of the command, add the command
        if(aBool) {
            strcpy(buffer, *executedCommand);
            aBool = 0;
        } else {
            //otherwise add a space between the commands
            strcat(buffer, " ");
            strcat(buffer, *executedCommand);
        }
        //pointer arithmatic to go to next entered command
        executedCommand++;

    }
    
    //If the history gets too big, start again and copy everything up one
    if(count == (HIST_SIZE - 1)) {
        for(i = 0; i < count; i++) {
            strcpy(commands[i], commands[i+1]);
        }
        count = 0;
    }
    //copy the command in the buffer into the history array
    strcpy(commands[count], buffer);
    //increments the history count
    count++;
}

/**
 * Prints the list of commands entered by the user.
 */
void print_commands(void) {

    int i;


    //loops through commands array and prints all values
    
    for(i = 0; i <= count - 1; i++) {
        printf("%d: %s\n", i, commands[i]);
    }
}

/**
 * Method that prints a specific index of the history array. If no method is
 * given, then print_commands would have been called by builtin.c
 *
 * @param history_num The index into the array that needs to be printed.
 */
void print_single_command(int history_num) {

    //Prints a single command that corresponds to command argument
    printf("%d: %s\n", history_num, commands[history_num]);

}

