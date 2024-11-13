/**
 * File: send_signal.c
 * Modified by: Abe Kesting
 * 
 * Brief summary of program: sends a signal with a random number
 */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int random = rand();

    union sigval value;
    value.sival_int = random;
    
    sigqueue(getppid(), SIGUSR1, value);//the way i run the other one this is child of the reviever process
}