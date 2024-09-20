/*
============================================================================
Name : 1c.c
Author : G Gayathri
Description : Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
	      a. ITIMER_PROF 
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/time.h>
#include <signal.h>

void timer_handler(int signum) {
    printf("ITIMER_PROF triggered\n");
}

int main(void) {
    struct itimerval timer;

    signal(SIGPROF, timer_handler);

    // Setting the interval timer to 10 seconds
    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_PROF, &timer, NULL);

    while(1); // Infinite loop to keep the program running
    return 0;
}

/*
Output:

gayathri@alahomora:~/SS_Lab_2$ cc 1c.c
gayathri@alahomora:~/SS_Lab_2$ ./a.out
ITIMER_PROF triggered
ITIMER_PROF triggered
*/
