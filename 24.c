/*
============================================================================
Name : 24.c
Author : G Gayathri
Description : Write a program to create a message queue and print the key and message queue id.
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main(void) {
    key_t key;
    int msgid;

    // Generate a unique key
    key = ftok(".", 'a');
    if (key == -1) {
        perror("ftok");
        return 1;
    }

    // Create a message queue
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        return 1;
    }

    printf("Message Queue Created:\n");
    printf("Key: %d\n", key);
    printf("Message Queue ID: %d\n", msgid);

    return 0;
}

/*
Output:

gayathri@alahomora:~/SS_Lab_2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    

gayathri@alahomora:~/SS_Lab_2$ ./a.out
Message Queue Created:
Key: 1627724703
Message Queue ID: 4
gayathri@alahomora:~/SS_Lab_2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x61051b9f 4          gayathri   666        0            0           

gayathri@alahomora:~/SS_Lab_2$ 
*/
