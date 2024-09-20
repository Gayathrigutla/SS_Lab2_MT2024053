/*
============================================================================
Name : 4.c
Author : G Gayathri
Description : Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter. 
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

unsigned long long rdtsc() {
    unsigned int lo, hi;
    // Inline assembly to read the time-stamp counter into edx:eax
    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((unsigned long long)hi << 32) | lo;
}

int main(void) {
    unsigned long long start, end;
    int i;

    // Start time-stamp counter
    start = rdtsc();

    // Call getppid() 100 times
    for (i = 0; i < 100; i++) {
        getppid();
    }

    // End time-stamp counter
    end = rdtsc();

    // Calculate and print the total number of cycles taken
    printf("Total CPU cycles for 100 getppid() calls: %llu\n", end - start);

    return 0;
}

/*
Output:

gayathri@alahomora:~/SS_Lab_2$ cc 4.c
gayathri@alahomora:~/SS_Lab_2$ ./a.out
Total CPU cycles for 100 getppid() calls: 72245
*/
