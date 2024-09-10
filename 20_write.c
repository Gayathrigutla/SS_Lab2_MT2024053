/*
============================================================================
Name : 20_write.c
Author : G Gayathri
Description : Write two programs so that both can communicate by FIFO - Use one way communication
Date: 10th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main (void) {
	int fd;
	char buff[80];
	fd = open("myfifo", O_WRONLY);
	printf("Enter the text: ");
	scanf(" %[^\n]", buff);
	write(fd, buff, sizeof(buff));
	return 0;
}
