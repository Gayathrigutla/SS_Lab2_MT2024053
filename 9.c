/*
============================================================================
Name : 9.c
Author : G Gayathri
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call. 
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signum) {
    // This function will be called when the default action is restored
    printf("Caught SIGINT! Default action restored.\n");
}

int main(void) {
    // Ignore the SIGINT signal
    signal(SIGINT, SIG_IGN);
    printf("SIGINT is currently being ignored. Press Ctrl+C to test.\n");

    // Sleep for a while to allow user to press Ctrl+C
    sleep(5);

    // Reset the default action for SIGINT
    signal(SIGINT, signal_handler);
    printf("Default action for SIGINT restored. Press Ctrl+C to test again.\n");

    // Sleep again to allow user to press Ctrl+C
    sleep(5);

    // Reset to the default action (terminate the program)
    signal(SIGINT, SIG_DFL);
    printf("SIGINT set to default action. You can exit now by pressing Ctrl+C.\n");

    // Sleep to keep the program running
    sleep(10);

    return 0;
}

/*
Output:

gayathri@alahomora:~/SS_Lab_2$ cc 9.c
gayathri@alahomora:~/SS_Lab_2$ ./a.out
SIGINT is currently being ignored. Press Ctrl+C to test.
^C
Default action for SIGINT restored. Press Ctrl+C to test again.
SIGINT set to default action. You can exit now by pressing Ctrl+C.
^C
gayathri@alahomora:~/SS_Lab_2$
*/
