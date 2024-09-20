/*
============================================================================
Name : 32d.c
Author : G Gayathri
Description : Write a program to implement semaphore to protect any critical section.
d. remove the created semaphore 
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main(void) {
    int semid;
    key_t key = ftok(".", 'c'); // Binary semaphore key

    // Get the existing semaphore
    semid = semget(key, 1, 0666);
    if (semid == -1) {
        perror("semget");
        return 1;
    }

    // Remove the semaphore
    if (semctl(semid, 0, IPC_RMID) == -1) {
        perror("semctl");
        return 1;
    }

    printf("Semaphore removed successfully.\n");
    return 0;
}

/*
Output:

gayathri@alahomora:~/SS_Lab_2$ cc 32d.c
gayathri@alahomora:~/SS_Lab_2$ ./a.out
Semaphore removed successfully.
gayathri@alahomora:~/SS_Lab_2$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsem
0x64051b9f 0          gayathri   666        1
*/
