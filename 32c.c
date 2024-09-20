/*
============================================================================
Name : 32c.c
Author : G Gayathri
Description : 32. Write a program to implement semaphore to protect any critical section.
c. protect multiple pseudo resources ( may be two) using counting semaphore
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
    key_t key = ftok(".", 'd'); // Counting semaphore key

    // Get the existing counting semaphore
    semid = semget(key, 1, 0666);
    if (semid == -1) {
        perror("semget");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        P(semid); // Wait (enter critical section)
        printf("Using pseudo resource: %d\n", i + 1);
        sleep(1); // Simulate time taken to use resource
        V(semid); // Signal (exit critical section)
    }

    return 0;
}

/*
Output:

gayathri@alahomora:~/SS_Lab_2$ cc 32c.c
gayathri@alahomora:~/SS_Lab_2$ ./a.out
Using pseudo resource: 1
Using pseudo resource: 2
Using pseudo resource: 3
Using pseudo resource: 4
Using pseudo resource: 5
*/
