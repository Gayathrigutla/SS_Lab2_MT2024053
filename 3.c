/*
============================================================================
Name : 3.c
Author : G Gayathri
Description : Write a program to set (any one) system resource limit. Use setrlimit system call.
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>

int main(void) {
    struct rlimit limit;

    // Get the current limits for the number of open files
    if (getrlimit(RLIMIT_NOFILE, &limit) != 0) {
        perror("getrlimit");
        return 1;
    }

    printf("Current limits: Soft = %ld, Hard = %ld\n", (long)limit.rlim_cur, (long)limit.rlim_max);

    // Set new soft limit to 2048 and hard limit to 4096
    limit.rlim_cur = 2048;  // New soft limit
    limit.rlim_max = 4096;  // New hard limit

    if (setrlimit(RLIMIT_NOFILE, &limit) != 0) {
        perror("setrlimit");
        return 1;
    }

    // Get the new limits to verify the changes
    if (getrlimit(RLIMIT_NOFILE, &limit) != 0) {
        perror("getrlimit");
        return 1;
    }

    printf("New limits: Soft = %ld, Hard = %ld\n", (long)limit.rlim_cur, (long)limit.rlim_max);

    return 0;
}

/*
Output:

gayathri@alahomora:~/SS_Lab_2$ ulimit -n
1024
gayathri@alahomora:~/SS_Lab_2$ ulimit -Hn
1048576
gayathri@alahomora:~/SS_Lab_2$ nano 3.c
gayathri@alahomora:~/SS_Lab_2$ cc 3.c
gayathri@alahomora:~/SS_Lab_2$ sudo ./a.out
Current limits: Soft = 1024, Hard = 1048576
New limits: Soft = 2048, Hard = 4096
*/
