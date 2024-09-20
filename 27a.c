/*
============================================================================
Name : 27a.c
Author : G Gayathri
Description : 27. Write a program to receive messages from the message queue.
a. with 0 as a flag
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>

struct msg {
    long int mtype;
    char message[80];
};

int main(void) {
    int msgid;
    key_t key;
    struct msg mq;

    // Ask the user to enter the key and msgid
    printf("Enter the key (in hex format, e.g., 0x61051b9f): ");
    scanf("%x", &key);
    printf("Enter the message queue ID: ");
    scanf("%d", &msgid);

    // Try to get the message queue with the provided key and id
    if (msgget(key, 0) != msgid) {
        printf("The provided key and message queue ID do not match.\n");
        return 1;
    }

    // Receive message from the queue (with mtype = 0 to receive any message type)
    if (msgrcv(msgid, &mq, sizeof(mq.message), 0, 0) == -1) {
        perror("msgrcv");
        return 1;
    }

    // Print the received message
    printf("Received message: %s\n", mq.message);
    return 0;
}

/*
Output:

gayathri@alahomora:~/SS_Lab_2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x61051b9f 13         gayathri   666        6            2           

gayathri@alahomora:~/SS_Lab_2$ nano 27a.c
gayathri@alahomora:~/SS_Lab_2$ cc -o 27a 27a.c
gayathri@alahomora:~/SS_Lab_2$ ./27a
Enter the key (in hex format, e.g., 0x61051b9f): 0x61051b9f
Enter the message queue ID: 13
Received message: 10
gayathri@alahomora:~/SS_Lab_2$ ./27a
Enter the key (in hex format, e.g., 0x61051b9f): 0x61051b9f
Enter the message queue ID: 13
Received message: 20
gayathri@alahomora:~/SS_Lab_2$ ./27a
Enter the key (in hex format, e.g., 0x61051b9f): 0x61051b9f
Enter the message queue ID: 13
^C
gayathri@alahomora:~/SS_Lab_2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x61051b9f 13         gayathri   666        0            0           

gayathri@alahomora:~/SS_Lab_2$ 
*/
