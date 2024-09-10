/*
============================================================================
Name : 19d.c
Author : G Gayathri
Description : Create a FIFO file by
              e. mknod system call 
Date: 10th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(void) {
    int fd;
    fd = mknod("myfifo", S_IFIFO | 0744, 0);  // Create FIFO using mknod system call
    if (fd == -1) {
        perror("mknod");
        return 1;
    }
    printf("FIFO created using mknod system call.\n");
    return 0;
}

