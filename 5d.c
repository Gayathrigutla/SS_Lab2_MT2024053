/*
============================================================================
Name : 5d.c
Author : G Gayathri
Description : Write a program to print the system limitation of
d. maximum number of open files
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/resource.h>

int main() {
    struct rlimit rl;
    getrlimit(RLIMIT_NOFILE, &rl);
    printf("Maximum number of open files: %lu\n", rl.rlim_cur);
    return 0;
}

/*
Output:

gayathri@alahomora:~/SS_Lab_2$ cc 5d.c
gayathri@alahomora:~/SS_Lab_2$ ./a.out
Maximum number of open files: 1024
*/
