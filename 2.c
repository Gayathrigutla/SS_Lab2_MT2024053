/*
============================================================================
Name : 2.c
Author : G Gayathri
Description : Write a program to print the system resource limits. Use getrlimit system call.
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/resource.h>

// Array of RLIMIT identifiers and their corresponding names
struct rlimit_info {
    int resource;
    const char* name;
} limits[] = {
    {RLIMIT_CPU, "CPU time (seconds)"},
    {RLIMIT_FSIZE, "File size (bytes)"},
    {RLIMIT_DATA, "Data segment size (bytes)"},
    {RLIMIT_STACK, "Stack size (bytes)"},
    {RLIMIT_CORE, "Core file size (bytes)"},
    {RLIMIT_RSS, "Resident set size (bytes)"},
    {RLIMIT_NOFILE, "Number of open files"},
    {RLIMIT_MEMLOCK, "Locked memory (bytes)"},
    {RLIMIT_NPROC, "Number of processes"},
    {RLIMIT_AS, "Address space (bytes)"},
    {RLIMIT_LOCKS, "File locks"},
    {RLIMIT_SIGPENDING, "Pending signals"},
    {RLIMIT_MSGQUEUE, "Message queue size (bytes)"},
    {RLIMIT_NICE, "Nice priority"},
    {RLIMIT_RTPRIO, "Real-time priority"},
    {RLIMIT_RTTIME, "Real-time timeout (microseconds)"}
};

int main(void) {
    struct rlimit limit;
    int num_limits = sizeof(limits) / sizeof(limits[0]);

    for (int i = 0; i < num_limits; i++) {
        if (getrlimit(limits[i].resource, &limit) == 0) {
            printf("%s: Soft Limit = %ld, Hard Limit = %ld\n",
                   limits[i].name,
                   (long)limit.rlim_cur,
                   (long)limit.rlim_max);
        } else {
            perror("getrlimit");
        }
    }

    return 0;
}

/*
Output:

gayathri@alahomora:~/SS_Lab_2$ cc 2.c
gayathri@alahomora:~/SS_Lab_2$ ./a.out
CPU time (seconds): Soft Limit = -1, Hard Limit = -1
File size (bytes): Soft Limit = -1, Hard Limit = -1
Data segment size (bytes): Soft Limit = -1, Hard Limit = -1
Stack size (bytes): Soft Limit = 8388608, Hard Limit = -1
Core file size (bytes): Soft Limit = 0, Hard Limit = -1
Resident set size (bytes): Soft Limit = -1, Hard Limit = -1
Number of open files: Soft Limit = 1024, Hard Limit = 1048576
Locked memory (bytes): Soft Limit = 2066821120, Hard Limit = 2066821120
Number of processes: Soft Limit = 62781, Hard Limit = 62781
Address space (bytes): Soft Limit = -1, Hard Limit = -1
File locks: Soft Limit = -1, Hard Limit = -1
Pending signals: Soft Limit = 62781, Hard Limit = 62781
Message queue size (bytes): Soft Limit = 819200, Hard Limit = 819200
Nice priority: Soft Limit = 0, Hard Limit = 0
Real-time priority: Soft Limit = 0, Hard Limit = 0
Real-time timeout (microseconds): Soft Limit = -1, Hard Limit = -1
*/
