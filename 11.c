/*
============================================================================
Name : 11.c
Author : G Gayathri
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call. 
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signum) {
    printf("Caught SIGINT! Default action restored.\n");
}

int main(void) {
    struct sigaction sa;

    // Step 1: Ignore SIGINT
    sa.sa_handler = SIG_IGN; // Set handler to ignore
    sigemptyset(&sa.sa_mask); // No additional signals to block
    sa.sa_flags = 0; // No special flags

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    printf("SIGINT is currently being ignored. Press Ctrl+C to test.\n");

    // Sleep for a while to allow user to press Ctrl+C
    sleep(5);

    // Step 2: Reset the default action for SIGINT
    sa.sa_handler = signal_handler; // Set to custom handler

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    printf("Default action for SIGINT restored. Press Ctrl+C to test again.\n");

    // Sleep again to allow user to press Ctrl+C
    sleep(5);

    // Step 3: Reset to the default action (terminate the program)
    sa.sa_handler = SIG_DFL; // Set to default action

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    printf("SIGINT set to default action. You can exit now by pressing Ctrl+C.\n");

    // Sleep to keep the program running
    sleep(10);

    return 0;
}

/*
Output:
gayathri@alahomora:~/SS_Lab_2$ cc 11.c
gayathri@alahomora:~/SS_Lab_2$ ./a.out
SIGINT is currently being ignored. Press Ctrl+C to test.
^C
Default action for SIGINT restored. Press Ctrl+C to test again.
SIGINT set to default action. You can exit now by pressing Ctrl+C.
^C
gayathri@alahomora:~/SS_Lab_2$
*/
