/*
============================================================================
Name : 8e.c
Author : G Gayathri
Description : Write a separate program using signal system call to catch the following signals.
e. SIGALRM (use setitimer system call)
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void sigalrm_handler(int signum) {
    printf("Caught SIGALRM: Alarm triggered using setitimer!\n");
    exit(0);
}

int main() {
    struct itimerval timer;
    signal(SIGALRM, sigalrm_handler);

    timer.it_value.tv_sec = 2;  // Initial delay of 2 seconds
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0; // No repeat
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);
    printf("Waiting for alarm...\n");
    pause(); // Wait for signals
    return 0;
}


/*
Output:

gayathri@alahomora:~/SS_Lab_2$ cc 8e.c
gayathri@alahomora:~/SS_Lab_2$ ./a.out
Waiting for alarm...
Caught SIGALRM: Alarm triggered using setitimer!
*/

