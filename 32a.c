/*
============================================================================
Name : 32a.c
Author : G Gayathri
Description : 32. Write a program to implement semaphore to protect any critical section.
a. rewrite the ticket number creation program using semaphore
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
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
    int semid;
    key_t key = ftok(".", 'c'); // Use the binary semaphore key

    // Get the existing semaphore
    semid = semget(key, 1, 0666);
    if (semid == -1) {
        perror("semget");
        return 1;
    }

    // Simulate ticket number creation
    for (int i = 0; i < 5; i++) {
        P(semid); // Wait (enter critical section)
        printf("Creating ticket number: %d\n", i + 1);
        sleep(1); // Simulate time taken to create a ticket
        V(semid); // Signal (exit critical section)
    }

    return 0;
}

/*
Output:

gayathri@alahomora:~/SS_Lab_2$ cc 32a.c
gayathri@alahomora:~/SS_Lab_2$ ./a.out
Creating ticket number: 1
Creating ticket number: 2
Creating ticket number: 3
Creating ticket number: 4
Creating ticket number: 5
*/
