#include <stdio.h>
#define HIST_SIZE 40
// TODO: Stuff in here to save and list history


char commands[HIST_SIZE];
static int count = 0;

char add_history(char** executedCommand){
    
    if(count == (HIST_SIZE - 1)) {
        count = 0;
    }

    commands[count] = executedCommand;
    count++;
}

void print_commmands(void) {

    int i;

    //loops through commands array and prints all values
    
    for(i = 0; i < commands.length; i++) {

        printf("%d: %s", i, commands[i]);

    }

}

void print_single_command(int history_num) {

    //Prints a single command that corresponds to command argument
    printf("%d: %s", history_num, commands[history_num]);

}

    


    








