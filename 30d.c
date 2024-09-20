/*
============================================================================
Name : 30d.c
Author : G Gayathri
Description : Write a program to create a shared memory.
d. remove the shared memory 
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

int main(void) {
    int shmid;
    key_t key;

    // Generate a unique key
    key = ftok(".", 'b');

    // Get the shared memory segment ID
    shmid = shmget(key, 1024, 0666);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    // Remove the shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        return 1;
    }

    printf("Shared memory removed successfully.\n");

    return 0;
}

/*
Output:

gayathri@alahomora:~/SS_Lab_2$ cc 30d.c
gayathri@alahomora:~/SS_Lab_2$ ./a.out
Shared memory removed successfully.
*/
