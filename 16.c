/*
============================================================================
Name : 16.c
Author : G Gayathri
Description : Write a program to send and receive data from parent to child and vice versa. Use two way communication.
Date: 10th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void){
	char buf[20];
	int fd1[2];
	int fd2[2];
	pipe(fd1);
	pipe(fd2);

	if(fork()){ //parent
		close(fd1[0]);
		printf("Sending message from parent: ");
		scanf(" %[^\n]", buf);
		write(fd1[1], buf, sizeof(buf));
		read(fd2[0], buf, sizeof(buf));
		printf("Message received from child: %s\n", buf);
	}
	else{ //child
		close(fd1[1]);
		read(fd1[0], buf, sizeof(buf));
		printf("Message received from parent: %s\n", buf);
		printf("Sending message to parent: ");
		scanf(" %[^\n]", buf);
		write(fd2[1], buf, sizeof(buf));
	}
	return 0;
}
