/**
 * File: signal_sigaction.c
 * Modified by: Abe Kesting
 * 
 * Brief summary of program: Recieves a signal and prints the pid of the sender
 */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


void handle_signal(int i, siginfo_t *info, void* ptr) {
    printf("Received a signal from pid: %d\n", info->si_pid);
    // exit(1);
}

int main() {
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


