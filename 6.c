/*
============================================================================
Name : 6.c
Author : G Gayathri
Description : Write a simple program to create three threads.  
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* thread_function(void* arg) {
    int thread_num = *((int*)arg);
    printf("Hello from thread %d!\n", thread_num);
    return NULL;
}

int main(void) {
    pthread_t threads[3];
    int thread_args[3];
    int i;

    // Create 3 threads
    for (i = 0; i < 3; i++) {
        thread_args[i] = i + 1;  // Set thread number (1, 2, 3)
        if (pthread_create(&threads[i], NULL, thread_function, &thread_args[i]) != 0) {
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

gayathri@alahomora:~/SS_Lab_2$ cc 6.c
gayathri@alahomora:~/SS_Lab_2$ ./a.out
Hello from thread 1!
Hello from thread 2!
Hello from thread 3!
All threads have finished executing.
*/
