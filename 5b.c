/*
============================================================================
Name : 5b.c
Author : G Gayathri
Description : Write a program to print the system limitation of
b. maximum number of simultaneous process per user id.
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/resource.h>

int main() {
    struct rlimit rl;
    getrlimit(RLIMIT_NPROC, &rl);
    printf("Maximum number of simultaneous processes per user ID: %lu\n", rl.rlim_cur);
    return 0;
}

/*
Output

gayathri@alahomora:~/SS_Lab_2$ cc 5b.c
gayathri@alahomora:~/SS_Lab_2$ ./a.out
Maximum number of simultaneous processes per user ID: 62781
*/
