/*
============================================================================
Name : 17c.c
Author : Yash Talele
Description : Write a program to execute ls -l | wc using
              c. fcntl
Date: 10th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void){
	int fd[2];
	pipe(fd);

	if(!fork()){
		close(1);
		close(fd[0]);
		fcntl(fd[1], F_DUPFD, 0);
		execlp("ls", "ls", "-l", (char *)NULL);
	}
	else{
		close(0);
		close(fd[1]);
		fcntl(fd[0], F_DUPFD, 0);
		execlp("wc", "wc", (char *)NULL);
	}
	return 0;
}
