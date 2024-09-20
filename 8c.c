/*
============================================================================
Name : 8c.c
Author : G Gayathri
Description : Write a separate program using signal system call to catch the following signals.
c. SIGFPE
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigfpe_handler(int signum) {
    printf("Caught SIGFPE: Arithmetic error!\n");
    exit(1);
}

int main() {
    signal(SIGFPE, sigfpe_handler);
    // Trigger SIGFPE (division by zero)
    int x = 1;
    int y = 0;
    int z = x / y; // This will cause SIGFPE
    return 0;
}


/*
Output:

gayathri@alahomora:~/SS_Lab_2$ cc 8c.c
gayathri@alahomora:~/SS_Lab_2$ ./a.out
Caught SIGFPE: Arithmetic error!
*/

