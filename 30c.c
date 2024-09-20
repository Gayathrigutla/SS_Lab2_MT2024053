/*
============================================================================
Name : 30c.c
Author : G Gayathri
Description : Write a program to create a shared memory.
c. detach the shared memory 
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

int main(void) {
    int shmid;
    char *shmaddr;
    key_t key;

    // Generate a unique key
    key = ftok(".", 'b');

    // Get the shared memory segment ID
    shmid = shmget(key, 1024, 0666);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    // Attach to the shared memory
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (char *)-1) {
        perror("shmat");
        return 1;
    }

    // Detach from the shared memory
    if (shmdt(shmaddr) == -1) {
        perror("shmdt");
        return 1;
    }

    printf("Detached from shared memory successfully.\n");

    return 0;
}

/*
Output:

gayathri@alahomora:~/SS_Lab_2$ cc 30c.c
gayathri@alahomora:~/SS_Lab_2$ ./a.out
Detached from shared memory successfully.
*/
