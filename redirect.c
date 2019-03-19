#include "shell.h"

#define INVALID -1

/*
 * append_redirection
 *
 * Redirects the standard output of this process to append to the file with the specified name.
 *
 * filename - the name of the file to which to append our output
 */
void append_redirection(char* filename) {
    /*
     * TODO:  Write code to cause the standard output of this process to be sent to a file with
     * the specified name.  The output should be appended to the file if the file already exists.
     */
    
    int fd = open(filename, O_CREAT|O_WRONLY|O_APPEND, 0644);
    dup2(fd, STDOUT_FILENO);
    if(fd < 0) {
        printf("Failed append redirection : File Descriptor Invalid.");
    }
    close(fd);




}

/*
 * stdout_redirection
 *
 * Redirects the standard output of this process to overwrite the file with the specified name.
 *
 * filename - the name of the file which to overwrite
 */
void stdout_redirection(char* filename) {
    /*
     * TODO:  Write code to cause the standard output of this process to be sent to a file with
     * the specified name.  If the file already exists, its contents should be truncated before
     * this process writes to the file.
     */


    int fd = open(filename, O_CREAT|O_WRONLY|O_TRUNC, 0644);
    dup2(fd, STDOUT_FILENO);
    if(fd < 0) {
        printf("Failed append redirection : File Descriptor Invalid.");
    }
    close(fd);




}
/*
 * stderr_redirection
 *
 * Redirects the standard error of this process to overwrite the file with the specified name.
 *
 * filename - the name of the file which to overwrite
 */
void stderr_redirection(char* filename) {
    /*
     * TODO:  Write code to cause the standard error of this process to be sent to a file with the
     * specified name.  If the file already exists, its contents should be truncated before this
     * process writes to the file.
     */

    int fd = open(filename, O_CREAT|O_WRONLY|O_TRUNC, 0644);
    dup2(fd, STDERR_FILENO);
    if(fd < 0) {
        printf("Failed append redirection : File Descriptor Invalid.");
    }
    close(fd);





}

/*
 * stdout_stderr_redirection
 *
 * Redirects the standard output AND standard error of this process to overwrite the file with the
 * specified name.
 *
 * filename - the name of the file which to overwrite
 */
void stdout_stderr_redirection(char* filename) {
    /*
     * TODO:  Write code to cause the standard output and standard error of this process to be
     * sent to a file with the specified name.  If the file already exists, its contents should be
     * truncated before this process writes to the file.
     */

    int fd = open(filename, O_CREAT|O_WRONLY|O_TRUNC, 0644);
    dup2(fd, STDOUT_FILENO);
    dup2(fd, STDERR_FILENO);
    if(fd < 0) {
        printf("Failed append redirection : File Descriptor Invalid.");
    }
    close(fd);






}
/*
 * stdin_redirection
 *
 * Redirects the standard input to this process from the file with the specified name.
 *
 * filename - the name of the file from which to read as standard input.
 */
void stdin_redirection(char* filename) {
    /*
     * TODO:  Write code to cause the standard input of this process to be read from a file with
     * the specified name.
     */

    int fd = open(filename, O_RDONLY, 0644);
    dup2(fd, STDIN_FILENO);
    if(fd < 0) {
        printf("Failed append redirection : File Descriptor Invalid.");
    }
    close(fd);



}

