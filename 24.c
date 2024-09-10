/*
============================================================================
Name : 24.c
Author : G Gayathri
Description : Write a program to create a message queue and print the key and message queue id. 
Date: 11th Sep, 2024.
============================================================================
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>

int main(void) {
	int msgid;
	key_t key;

	key = ftok(".", 'a');
	msgid = msgget(key, IPC_CREAT | IPC_EXCL | 0744);
	printf("key value = %d\n", key);
	printf("key value in hex ' 0x%0x\n", key);
	printf("Message queue id = %d\n", msgid);
	return 0;
}

/*
Output:

gayathri@alahomora:~/SS_Lab_2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages

gayathri@alahomora:~/SS_Lab_2$ cc 24.c
gayathri@alahomora:~/SS_Lab_2$ ./a.out
key value = 1627724703
key value in hex ' 0x61051b9f
Message queue id = 0
gayathri@alahomora:~/SS_Lab_2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x61051b9f 0          gayathri   744        0            0

*/
