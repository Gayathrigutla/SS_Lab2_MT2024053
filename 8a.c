/*
============================================================================
Name : 8a.c
Author : G Gayathri
Description : Write a separate program using signal system call to catch the following signals.
a. SIGSEGV
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigsegv_handler(int signum) {
    printf("Caught SIGSEGV: Segmentation fault!\n");
    exit(1);
}

int main() {
    signal(SIGSEGV, sigsegv_handler);
    // Trigger SIGSEGV
    int *ptr = NULL;
    *ptr = 0; // This will cause a segmentation fault
    return 0;
}


/*
Output:

gayathri@alahomora:~/SS_Lab_2$ cc 8a.c
gayathri@alahomora:~/SS_Lab_2$ ./a.out
Caught SIGSEGV: Segmentation fault!
*/
