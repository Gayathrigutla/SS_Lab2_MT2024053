/*
============================================================================
Name : 5a.c
Author : G Gayathri
Description : Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    long arg_max = sysconf(_SC_ARG_MAX);
    if (arg_max == -1) {
        perror("sysconf");
        return 1;
    }
    printf("Maximum length of arguments to exec family: %ld\n", arg_max);
    return 0;
}

/*
Output

gayathri@alahomora:~/SS_Lab_2$ cc 5a.c
gayathri@alahomora:~/SS_Lab_2$ ./a.out
Maximum length of arguments to exec family: 2097152
*/
