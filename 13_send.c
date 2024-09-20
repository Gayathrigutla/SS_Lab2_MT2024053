#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(void) {
    pid_t pid;

    // Get the PID of the first program
    printf("Enter the PID of the first program to send SIGSTOP: ");
    scanf("%d", &pid);

    // Send SIGSTOP to the first program
    if (kill(pid, SIGSTOP) == -1) {
        perror("Failed to send SIGSTOP");
        exit(EXIT_FAILURE);
    }

    printf("Sent SIGSTOP to process %d.\n", pid);
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
