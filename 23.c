/*
============================================================================
Name : 23.c
Author : G Gayathri
Description : Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer). 
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <unistd.h>

int main(void) {
    struct rlimit rl;

    // Get maximum number of open files
    if (getrlimit(RLIMIT_NOFILE, &rl) == -1) {
        perror("getrlimit for RLIMIT_NOFILE failed");
        exit(EXIT_FAILURE);
    }
    printf("Maximum number of open files: Soft Limit = %lu, Hard Limit = %lu\n", 
           rl.rlim_cur, rl.rlim_max);

    // Estimate size of a pipe (commonly 64 KB on many systems)
    size_t pipe_size = 64 * 1024; // Assuming a typical pipe size
    printf("Estimated size of a pipe (circular buffer): %lu bytes\n", pipe_size);

    return 0;
}

/*
Output:

gayathri@alahomora:~/SS_Lab_2$ cc 23.c
gayathri@alahomora:~/SS_Lab_2$ ./a.out
Maximum number of open files: Soft Limit = 1024, Hard Limit = 1048576
Estimated size of a pipe (circular buffer): 65536 bytes
*/
