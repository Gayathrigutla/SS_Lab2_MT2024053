/*
============================================================================
Name : 26_send.c
Author : G Gayathri
Description : Write a program to send messages to the message queue. Check $ipcs -q
Date: 11th Sep, 2024.
============================================================================
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <string.h>

int main (void) {
	int msgid, size;
	key_t key;
	struct msg {
		long int mtype;
		char message[80];
	}mq;

	key = ftok(".",'a');
	msgid = msgget(key, 0);
	printf("Enter the message type: ");
	scanf("%ld", &mq.mtype);

	printf("Enter the message text: ");
	scanf(" %[^\n]", mq.message);
	size = strlen(mq.message);

	msgsnd(msgid, &mq, size+1, 0);
	return 0;
}

/*
Output:

gayathri@alahomora:~/SS_Lab_2$ ./a.out
Enter the message type: 1
Enter the message text: First message
gayathri@alahomora:~/SS_Lab_2$ ./a.out
Enter the message type: 2
Enter the message text: Second message
gayathri@alahomora:~/SS_Lab_2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x61051b9f 0          gayathri   744        29           2           

gayathri@alahomora:~/SS_Lab_2$ cc 26_rec.c 
gayathri@alahomora:~/SS_Lab_2$ ./a.out
Enter the message type to receive: 0
 : Success
Message type: 1 Message text: First message
gayathri@alahomora:~/SS_Lab_2$ ./a.out
Enter the message type to receive: 2
 : Success
Message type: 2 Message text: Second message
gayathri@alahomora:~/SS_Lab_2$ ./a.out
Enter the message type to receive: 0
^C
gayathri@alahomora:~/SS_Lab_2$
*/
