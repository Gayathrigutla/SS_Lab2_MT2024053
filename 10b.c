/*
============================================================================
Name : 10b.c
Author : G Gayathri
Description : Write a separate program using sigaction system call to catch the following signals.
b. SIGINT
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int signum, siginfo_t *info, void *context) {
    printf("Caught SIGINT: Interrupt signal!\n");
    exit(0);
}

int main() {
    struct sigaction sa;
    sa.sa_sigaction = sigint_handler;
    sa.sa_flags = SA_SIGINFO; // Use the sa_sigaction field
    sigaction(SIGINT, &sa, NULL);

    printf("Press Ctrl+C to trigger SIGINT...\n");
    while (1) {
        pause(); // Wait for signals
    }
    return 0;
}


/*
Output:

gayathri@alahomora:~/SS_Lab_2$ cc 10b.c
gayathri@alahomora:~/SS_Lab_2$ ./a.out
Press Ctrl+C to trigger SIGINT...
^CCaught SIGINT: Interrupt signal!
*/
