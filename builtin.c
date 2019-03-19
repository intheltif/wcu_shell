#include "shell.h"
#include <errno.h>

/**
 * do_file_list
 *
 * Implements a built-in version of the 'ls' command.
 *
 * args - An array of strings corresponding to the command and its arguments.
 *        If args[1] is NULL, the current directory (./) is assumed; otherwise
 *        it specifies the directory to list.
 */
void do_file_list(char** args) {
    /*                                                                          
     * TODO: Write code here that will list the content of the specified directory (or if no
     * directory was specified, the current directory).
     */                                                                         

    /** A pointer to a directory stream */
    DIR* directory;

    /** A pointer to a dirent structure which allows us to access filenames */
    struct dirent *dir_p;
    

    //If no directory specified, opens and reads current directory
    if(args[1] == NULL) {
        //Assures directory stream can be opened
        if( (directory = opendir(".")) == NULL) {
            perror("Cannot open current directory");
            //_exit(1);
        }
        
        // Reads from the directory stream, gets filenames, and prints items to the console
        while( (dir_p = readdir(directory)) != NULL ) {
            printf("%s\n", dir_p->d_name);
        }
    } else if( (strcmp(args[1], "-l") == 0) ||
               (strcmp(args[1], "-a") == 0) ||
               (strcmp(args[1], "-t") == 0)   ) {
            
            printf("Unsupported operation.\n");
            //_exit(1);
    } else {

        //Does same as above, except for a specified directory
        if( (directory = opendir(args[1])) == NULL) {
            perror("Cannot open specified directory");
            //_exit(1);
        }

        while( (dir_p = readdir(directory)) != NULL ) {
            printf("%s\n", dir_p->d_name);
        }

    } //end if-else

} // end do_file_list

/**
 * do_file_remove
 *
 * Implements a built-in version of the 'rm' command.
 *
 * args - An array of strings corresponding to the command and its arguments.
 *        args[0] is "rm", additional arguments are in args[1] ... n.
 *        args[x] = NULL indicates the end of the argument list.
 */
void do_file_remove(char** args) {
    /*                                                                          
     * TODO: Write code here that will remove the specified list of files.  If no file list is
     * specified, print a usage message.
     */                                                                         

    int i = 1;
    int removed;
    

    //Check that a filename was provided
    if(args[1] == NULL) {
        perror("Please specify a filename to remove");
        //_exit(1);
    }

    while(args[i] != NULL) {

        removed = unlink(args[i]);
        if(removed == 0) {
            printf("\nremoved %s\n", args[i]);
        } else {
            perror("Could not remove file");
        }
        i++;

    }

}
/**
 * do_touch
 *
 * Implements a built-in version of the 'touch' command.
 *
 * args - An array of strings corresponding to the command and its arguments.
 *        args[0] is "touch", additional arguments are in args[1] ... n.
 *        args[x] = NULL indicates the end of the argument list.
 */
void do_touch(char** args) {
    /*                                                                          
     * TODO: Write code here that will modify the access time of a file(s) if it exists, or create
     * the file(s) if it/they does not exist.  If no file list is specified, print a usage message.
     */                                                                         

    int i = 1;
    int accessed = 0;
    
    if(args[1] == NULL) {
        perror("Please specify a filename");
        printf("Usage: touch <filename(s)>");
    } else {
        while(args[i] != NULL) {
            accessed = utime(args[i], NULL); //When second arg is null, time is current time.
            if(accessed < 0) {
                if(errno == ENOENT) {
                    open(args[i], O_CREAT, 0644);
                }
                perror("Error accessing specified file");
            }
            i++;
        }
    }

}
/**
 * do_history
 *
 * Implements a built-in version of the 'history' command. This will just list the command in the
 * form:
 *  0: command
 *  1: command
 *  2: command
 *
 * args - An array of strings corresponding to the command and its arguments.
 *        args[0] is "history", additional arguments are in args[1] ... n.
 *        args[x] = NULL indicates the end of the argument list.
 */
void do_history(char** args) {
    /*                                                                          
     * TODO: Write code here that will print the last n commands executed via this shell.
     */                                                                         








}
