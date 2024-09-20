/*
============================================================================
Name : 8d.c
Author : G Gayathri
Description : Write a separate program using signal system call to catch the following signals.
d. SIGALRM (use alarm system call)
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigalrm_handler(int signum) {
    printf("Caught SIGALRM: Alarm triggered!\n");
    exit(0);
}

int main() {
    signal(SIGALRM, sigalrm_handler);
    alarm(2); // Set alarm for 2 seconds
    printf("Waiting for alarm...\n");
    pause(); // Wait for signals
    return 0;
}


/*
Output:

gayathri@alahomora:~/SS_Lab_2$ cc 8d.c
gayathri@alahomora:~/SS_Lab_2$ ./a.out
Waiting for alarm...
Caught SIGALRM: Alarm triggered!
*/

