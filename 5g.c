/*
============================================================================
Name : 5g.c
Author : G Gayathri
Description : Write a program to print the system limitation of
g. number of currently available pages in the physical memory. 
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    long avail_pages = sysconf(_SC_AVPHYS_PAGES);
    printf("Number of currently available pages in the physical memory: %ld\n", avail_pages);
    return 0;
}


/*
Output:

gayathri@alahomora:~/SS_Lab_2$ cc 5g.c
gayathri@alahomora:~/SS_Lab_2$ ./a.out
Number of currently available pages in the physical memory: 1148505
*/
