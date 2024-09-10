/*
Name : 14.c
Author : G Gayathri
Description : 14. Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.
Date: 10th Sep, 2024
*/

#include <stdio.h>
#include <unistd.h>

int main(void){
	int fd[2];
	char buf[20];
	pipe(fd);

	scanf(" %[^\n]", buf);
	write(fd[1], buf, 20);
	read(fd[0], buf, sizeof(buf));
	printf("Read from Pipe: %s\n", buf);
	return 0; 
}
