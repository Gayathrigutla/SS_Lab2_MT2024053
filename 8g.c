/*
============================================================================
Name : 8g.c
Author : G Gayathri
Description : Write a separate program using signal system call to catch the following signals.
g. SIGPROF (use setitimer system call)
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void sigprof_handler(int signum) {
    printf("Caught SIGPROF: Profiling timer alarm triggered!\n");
    exit(0);
}

int main() {
    struct itimerval timer;
    signal(SIGPROF, sigprof_handler);

    timer.it_value.tv_sec = 2;  // Initial delay of 2 seconds
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0; // No repeat
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_PROF, &timer, NULL);
    printf("Waiting for profiling alarm...\n");
    while (1); // Wait indefinitely
    return 0;
}


/*
Output:

gayathri@alahomora:~/SS_Lab_2$ cc 8g.c
gayathri@alahomora:~/SS_Lab_2$ ./a.out
Waiting for profiling alarm...
Caught SIGPROF: Profiling timer alarm triggered!
*/

