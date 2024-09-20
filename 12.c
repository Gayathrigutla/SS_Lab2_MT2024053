/*
============================================================================
Name : 12.c
Author : G Gayathri
Description : Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process. 
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(void) {
    pid_t pid = fork(); // Create a child process

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid > 0) {
        // Parent process
        printf("Parent process (PID: %d) is sleeping for 5 seconds...\n", getpid());
        sleep(5); // Sleep to allow the child to run first
        printf("Parent process is still alive.\n");
    } else {
        // Child process
        sleep(2); // Give the parent time to start
        printf("Child process (PID: %d) sending SIGKILL to parent (PID: %d)...\n", getpid(), getppid());
        
        // Send SIGKILL to the parent process
        if (kill(getppid(), SIGKILL) == -1) {
            perror("kill failed");
            exit(1);
        }
        
        // Child process continues to run
        printf("Child process is now orphaned. Parent process has been killed.\n");
        sleep(5); // Keep the child alive for a while to observe it as an orphan
    }

    return 0;
}

/*
Output:
gayathri@alahomora:~/SS_Lab_2$ nano 12.c
gayathri@alahomora:~/SS_Lab_2$ cc 12.c
gayathri@alahomora:~/SS_Lab_2$ ./a.out
Parent process (PID: 220442) is sleeping for 5 seconds...
Child process (PID: 220443) sending SIGKILL to parent (PID: 220442)...
Child process is now orphaned. Parent process has been killed.
Killed
*/
