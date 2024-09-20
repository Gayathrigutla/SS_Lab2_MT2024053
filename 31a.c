/*
============================================================================
Name : 31a.c
Author : G Gayathri
Description : Write a program to create a semaphore and initialize value to the semaphore.
a. create a binary semaphore
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>

int main(void) {
    int semid;
    key_t key;
    struct sembuf sem_op;
    union semun {
        int val;               // Value for SETVAL
        struct semid_ds *buf;  // Buffer for IPC_STAT, IPC_SET
        unsigned short *array; // Array for GETALL, SETALL
    } sem_union;

    // Generate a unique key
    key = ftok(".", 'c');

    // Create a semaphore set with 1 semaphore (binary semaphore)
    semid = semget(key, 1, 0666 | IPC_CREAT);
    if (semid == -1) {
        perror("semget");
        return 1;
    }

    // Initialize the semaphore value to 1 (binary semaphore)
    sem_union.val = 1;
    if (semctl(semid, 0, SETVAL, sem_union) == -1) {
        perror("semctl");
        return 1;
    }

    printf("Binary semaphore created and initialized with value 1.\n");
    printf("Semaphore ID: %d\n", semid);

    return 0;
}

/*
Output:

gayathri@alahomora:~/SS_Lab_2$ cc 31a.c
gayathri@alahomora:~/SS_Lab_2$ ./a.out
Binary semaphore created and initialized with value 1.
Semaphore ID: 1
*/
