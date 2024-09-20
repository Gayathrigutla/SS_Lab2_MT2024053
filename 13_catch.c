/*
============================================================================
Name : 13.c
Author : G Gayathri
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not. 
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signum) {
    printf("Caught SIGSTOP! This should not happen.\n");
}

int main(void) {
    // Set up the signal handler for SIGSTOP
    signal(SIGSTOP, signal_handler);

    printf("Waiting for SIGSTOP... (PID: %d)\n", getpid());

    // Infinite loop to keep the program running
    while (1) {
        pause(); // Wait for signals
    }

    return 0;
}

/*
Output:

Catching Terminal:
gayathri@alahomora:~/SS_Lab_2$ ./catch
Waiting for SIGSTOP... (PID: 220651)

[1]+  Stopped                 ./catch
gayathri@alahomora:~/SS_Lab_2$ jobs
[1]+  Running                 ./catch &
gayathri@alahomora:~/SS_Lab_2$ jobs
[1]+  Killed                  ./catch
gayathri@alahomora:~/SS_Lab_2$ jobs
gayathri@alahomora:~/SS_Lab_2$

Sending Terminal:
gayathri@alahomora:~/SS_Lab_2$ ./send
Enter the PID of the first program to send SIGSTOP: 220651
Sent SIGSTOP to process 220651.
gayathri@alahomora:~/SS_Lab_2$ kill -SIGCONT 220651
gayathri@alahomora:~/SS_Lab_2$ kill -SIGKILL 220651
*/
