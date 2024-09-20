/*
============================================================================
Name : 8f.c
Author : G Gayathri
Description : Write a separate program using signal system call to catch the following signals.
f. SIGVTALRM (use setitimer system call)
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void sigvtalrm_handler(int signum) {
    printf("Caught SIGVTALRM: Virtual timer alarm triggered!\n");
    exit(0);
}

int main() {
    struct itimerval timer;
    signal(SIGVTALRM, sigvtalrm_handler);

    timer.it_value.tv_sec = 2;  // Initial delay of 2 seconds
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0; // No repeat
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_VIRTUAL, &timer, NULL);
    printf("Waiting for virtual alarm...\n");
    while (1); // Wait indefinitely
    return 0;
}


/*
Output:

gayathri@alahomora:~/SS_Lab_2$ cc 8f.c
gayathri@alahomora:~/SS_Lab_2$ ./a.out
Waiting for virtual alarm...
Caught SIGVTALRM: Virtual timer alarm triggered!
*/

