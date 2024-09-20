/*
============================================================================
Name : 5f.c
Author : G Gayathri
Description : Write a program to print the system limitation of
f. total number of pages in the physical memory
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    long num_pages = sysconf(_SC_PHYS_PAGES);
    printf("Total number of pages in the physical memory: %ld\n", num_pages);
    return 0;
}

/*
Output:

gayathri@alahomora:~/SS_Lab_2$ cc 5f.c
gayathri@alahomora:~/SS_Lab_2$ ./a.out
Total number of pages in the physical memory: 4036767
*/
