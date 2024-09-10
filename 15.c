/*
Name : 15.c
Author : G Gayathri
Description : Write a simple program to send some data from parent to the child process.
Date: 10th Sep, 2024.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void){
	char buff[20];
	int fd[2];

	pipe(fd);
	if(fork()) {
		close(fd[0]); //closing the read end of the pipe
		printf("Enter message to child: ");
		scanf(" %[^\n]", buff);
		write(fd[1], buff, sizeof(buff));
	}
	else{
		close(fd[1]); //closing the write end of the pipe
		read(fd[0], buff, sizeof(buff));
		printf("Message from parent: %s\n", buff);
	}
	wait(0); //not required really as read and write are blocking calls
	return 0;
}
