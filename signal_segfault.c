/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by: Abe Kesting
 * 
 * Brief summary of modifications: added a signal handler to catch the segfault. Surprise, surprise -- it doesnt fix the program
 */


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void handle_signal() {
    printf("Received segfault\n");
    sleep(1);//waits a second or it just goes crazy
    // exit(1);
}


int main (int argc, char* argv[]) {
    // Declare a null pointer
    int* i = NULL;
    signal(SIGSEGV, handle_signal);
    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}