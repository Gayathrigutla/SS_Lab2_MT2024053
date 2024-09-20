/*
============================================================================
Name : 7.c
Author : G Gayathri
Description : Write a simple program to print the created thread ids. 
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <pthread.h>

void* thread_function(void* arg) {
    pthread_t tid = pthread_self(); // Get the thread ID of the current thread
    printf("Thread ID: %lu\n", (unsigned long)tid); // Print the thread ID
    return NULL;
}

int main(void) {
    pthread_t threads[3]; // Array to hold thread identifiers
    int i;

    // Create 3 threads
    for (i = 0; i < 3; i++) {
        if (pthread_create(&threads[i], NULL, thread_function, NULL) != 0) {
            perror("Failed to create thread");
            return 1;
        }
    }

    // Join 3 threads to ensure they complete before exiting
    for (i = 0; i < 3; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("Failed to join thread");
            return 1;
        }
    }

    printf("All threads have finished executing.\n");
    return 0;
}


/*
Output:

gayathri@alahomora:~/SS_Lab_2$ cc -pthread 7.c
gayathri@alahomora:~/SS_Lab_2$ ./a.out
Thread ID: 140640448935616
Thread ID: 140640440542912
Thread ID: 140640432150208
All threads have finished executing.
*/
