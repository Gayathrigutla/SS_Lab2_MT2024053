/*
============================================================================
Name : 30a.c
Author : G Gayathri
Description : Write a program to create a shared memory.
a. write some data to the shared memory 
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <sys/types.h>

int main(void) {
    int shmid;
    char *shmaddr;
    key_t key;

    // Generate a unique key
    key = ftok(".", 'b');

    // Create a shared memory segment
    shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    printf("Shared memory created with ID: %d\n", shmid);

    // Attach to the shared memory
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (char *)-1) {
        perror("shmat");
        return 1;
    }

    // Write data to shared memory
    printf("Enter data to write into shared memory: ");
    fgets(shmaddr, 1024, stdin);
    printf("Data written: %s\n", shmaddr);

    // Detach from the shared memory
    shmdt(shmaddr);

    return 0;
}

/*
Output:

gayathri@alahomora:~/SS_Lab_2$ cc 30a.c
gayathri@alahomora:~/SS_Lab_2$ ./a.out
Shared memory created with ID: 29
Enter data to write into shared memory: Hi
Data written: Hi
*/
