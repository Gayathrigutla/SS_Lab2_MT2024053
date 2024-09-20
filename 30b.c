/*
============================================================================
Name : 30b.c
Author : G Gayathri
Description : Write a program to create a shared memory.
b. attach with O_RDONLY and check whether you are able to overwrite. 
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

    // Get the shared memory segment ID
    shmid = shmget(key, 1024, 0666);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    // Attach to the shared memory in read-only mode
    shmaddr = shmat(shmid, NULL, SHM_RDONLY);
    if (shmaddr == (char *)-1) {
        perror("shmat");
        return 1;
    }

    // Try to write data to shared memory (should fail in read-only mode)
    printf("Attempting to overwrite shared memory in read-only mode...\n");
    strcpy(shmaddr, "New data");

    // Print the contents to check if it has changed
    printf("Data in shared memory: %s\n", shmaddr);

    // Detach from the shared memory
    shmdt(shmaddr);

    return 0;
}


/*
Output:

gayathri@alahomora:~/SS_Lab_2$ cc 30b.c
gayathri@alahomora:~/SS_Lab_2$ ./a.out
Attempting to overwrite shared memory in read-only mode...
Segmentation fault (core dumped)
*/
