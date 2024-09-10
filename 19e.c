/*
============================================================================
Name : 19e.c
Author : G Gayathri
Description : Create a FIFO file by
	      e. mkfifo library function 
Date: 10th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/stat.h>

int main(void) {
    int fd;
    fd = mkfifo("myfifo6", 0744);  // Create FIFO using mkfifo library function
    if (fd == -1) {
        perror("mkfifo");
        return 1;
    }
    printf("FIFO created using mkfifo library function.\n");
    return 0;
}
