/*
============================================================================
Name : 5c.c
Author : G Gayathri
Description : Write a program to print the system limitation of
c. number of clock ticks (jiffy) per second.
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    long ticks = sysconf(_SC_CLK_TCK);
    printf("Number of clock ticks (jiffies) per second: %ld\n", ticks);
    return 0;
}

/*
Output:

gayathri@alahomora:~/SS_Lab_2$ cc 5c.c
gayathri@alahomora:~/SS_Lab_2$ ./a.out
Number of clock ticks (jiffies) per second: 100
*/
