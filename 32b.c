/*
============================================================================
Name : 32b.c
Author : G Gayathri
Description : 32. Write a program to implement semaphore to protect any critical section.
b. protect shared memory from concurrent write access
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <string.h>
#include <unistd.h>

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

void P(int semid) {
    struct sembuf sb = {0, -1, 0}; // Wait (decrement)
    semop(semid, &sb, 1);
}

void V(int semid) {
    struct sembuf sb = {0, 1, 0}; // Signal (increment)
    semop(semid, &sb, 1);
}

int main(void) {
    int shmid;
    key_t key = ftok(".", 'b'); // Shared memory key
    int semid = semget(ftok(".", 'c'), 1, 0666); // Binary semaphore key

    // Create shared memory
    shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    char *shmaddr = shmat(shmid, NULL, 0);

    for (int i = 0; i < 5; i++) {
        P(semid); // Wait (enter critical section)
        snprintf(shmaddr, 1024, "Data written: %d", i + 1);
        printf("Writing to shared memory: %s\n", shmaddr);
        sleep(1); // Simulate time taken to write
        V(semid); // Signal (exit critical section)
    }

    shmdt(shmaddr); // Detach shared memory
    return 0;
}

/*
Output:

gayathri@alahomora:~/SS_Lab_2$ cc 32b.c
gayathri@alahomora:~/SS_Lab_2$ ./a.out
Writing to shared memory: Data written: 1
Writing to shared memory: Data written: 2
Writing to shared memory: Data written: 3
Writing to shared memory: Data written: 4
Writing to shared memory: Data written: 5
*/
