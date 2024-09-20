/*
============================================================================
Name : 10a.c
Author : G Gayathri
Description : Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigsegv_handler(int signum, siginfo_t *info, void *context) {
    printf("Caught SIGSEGV: Segmentation fault!\n");
    exit(1);
}

int main() {
    struct sigaction sa;
    sa.sa_sigaction = sigsegv_handler;
    sa.sa_flags = SA_SIGINFO; // Use the sa_sigaction field
    sigaction(SIGSEGV, &sa, NULL);

    printf("Triggering SIGSEGV...\n");
    
    // Trigger SIGSEGV by dereferencing a null pointer
    int *ptr = NULL;
    printf("Attempting to dereference null pointer...\n");
    *ptr = 0; // This will cause a segmentation fault

    return 0; // This line won't be executed
}


/*
Output:

gayathri@alahomora:~/SS_Lab_2$ cc 10a.c
gayathri@alahomora:~/SS_Lab_2$ ./a.out
Triggering SIGSEGV...
Attempting to dereference null pointer...
Caught SIGSEGV: Segmentation fault!
*/
