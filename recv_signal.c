/**
 * File: recv_signal.c
 * Modified by: Abe Kesting
 * 
 * Brief summary of program: recieves a signal 
 */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


void handle_signal(int i, siginfo_t *info, void* ptr) {
    int num = info->si_value.sival_int;
    printf("Received a signal with data: %d\n", num);
    // exit(1);
}

int main() {
    if (!fork()) {
        execlp("./send_signal.out", "./send_signal.out", NULL);
        //run the sender as a child process to avoid transferring pid via command line
    }

    struct sigaction sa;
    sa.sa_sigaction = handle_signal;
    sa.sa_flags = SA_SIGINFO;
    // Register for the signal
    sigaction(SIGUSR1, &sa, NULL);

    // Wait until a signal is received
    while(1) {
        sleep(1);
    }

    return 0;
}



