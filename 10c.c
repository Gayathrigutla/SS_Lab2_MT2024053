/*
============================================================================
Name : 10c.c
Author : G Gayathri
Description : Write a separate program using sigaction system call to catch the following signals.
c. SIGFPE
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigfpe_handler(int signum, siginfo_t *info, void *context) {
    printf("Caught SIGFPE: Arithmetic error!\n");
    exit(1);
}

int main() {
    struct sigaction sa;
    sa.sa_sigaction = sigfpe_handler;
    sa.sa_flags = SA_SIGINFO; // Use the sa_sigaction field
    sigaction(SIGFPE, &sa, NULL);

    printf("Triggering SIGFPE (division by zero)...\n");
    // Trigger SIGFPE (division by zero)
    int x = 1;
    int y = 0;
    int z = x / y; // This will cause SIGFPE

    return 0; // This line won't be executed
}


/*
Output:

gayathri@alahomora:~/SS_Lab_2$ cc 10c.c
gayathri@alahomora:~/SS_Lab_2$ ./a.out
Triggering SIGFPE (division by zero)...
Caught SIGFPE: Arithmetic error!
*/
