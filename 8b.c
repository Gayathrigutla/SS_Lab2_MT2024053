/*
============================================================================
Name : 8b.c
Author : G Gayathri
Description : Write a separate program using signal system call to catch the following signals.
b. SIGINT
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int signum) {
    printf("Caught SIGINT: Interrupt signal!\n");
    exit(0);
}

int main() {
    signal(SIGINT, sigint_handler);
    printf("Press Ctrl+C to trigger SIGINT...\n");
    while (1) {
        pause(); // Wait for signals
    }
    return 0;
}


/*
Output:

gayathri@alahomora:~/SS_Lab_2$ cc 8b.c
gayathri@alahomora:~/SS_Lab_2$ ./a.out
Press Ctrl+C to trigger SIGINT...
Caught SIGINT: Interrupt signal!
*/

