/*
============================================================================
Name : 5e.c
Author : G Gayathri
Description : Write a program to print the system limitation of
e. size of a page
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    long page_size = sysconf(_SC_PAGESIZE);
    printf("Size of a page: %ld bytes\n", page_size);
    return 0;
}

/*
Output:

gayathri@alahomora:~/SS_Lab_2$ cc 5e.c
gayathri@alahomora:~/SS_Lab_2$ ./a.out
Size of a page: 4096 bytes
*/
