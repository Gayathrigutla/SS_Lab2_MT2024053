/*
============================================================================
Name : 22.c
Author : G Gayathri
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
Date: 11th Sep, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>

int main(void){
	int fd, retval;
	char buff[80];
	fd_set rfds;
	struct timeval tv;

	fd = open("myfifo", O_RDONLY);
	FD_ZERO(&rfds);
	FD_SET(fd, &rfds);
	tv.tv_sec=5;
	tv.tv_usec=0;
	retval=select(fd+1, &rfds, NULL, NULL, &tv);
	if(retval){
		printf(" Data is available now...\n");
	}
	else{
		printf(" No data is available within 5 seconds...\n");
		exit(0);
	}
	read(fd, buff, sizeof(buff));
	printf(" The text from FIFO: %s\n", buff);
	return 0;
}

/*
Output:
Terminal 1:
gayathri@alahomora:~/SS_Lab_2$ ./write
Enter the text: 

Terminal 2:
gayathri@alahomora:~/SS_Lab_2$ ./read
 No data is available within 5 seconds...

Terminal 1:
gayathri@alahomora:~/SS_Lab_2$ ./write
Enter the text: Hi

Terminal 2:
gayathri@alahomora:~/SS_Lab_2$ ./read
 Data is available now...
 The text from FIFO: Hi
*/
