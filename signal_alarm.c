/**
 * File: signal_alarm.c
 * Modified by: Abe Kesting
 * 
 * Brief summary of program: schedules an alarm to be sent after 5 seconds and then exits once the alarm signal is recieved
 */


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void handle_signal() {
    printf("Received alarm\n");
    exit(1);
}

int main() {

    // Register for the signal
    signal(SIGALRM, handle_signal);
    alarm(5);
    // Wait until a alarm is received
    while(1) {
        printf("Sleeping\n");
        sleep(1);
    }

    return 0;
}
