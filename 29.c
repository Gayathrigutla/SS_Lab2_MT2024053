/*
============================================================================
Name : 29.c
Author : G Gayathri
Description : Write a program to remove the message queue.
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main(void) {
    key_t key;
    int msgid;

    printf("Enter the key (in hex format, e.g., 0x61051b9f): ");
    scanf("%x", &key);

    msgid = msgget(key, 0);
    if (msgid == -1) {
        perror("msgget");
        return 1;
    }

    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        return 1;
    }

    printf("Message queue removed successfully.\n");
    return 0;
}

/*
Output:

gayathri@alahomora:~/SS_Lab_2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x61051b9f 13         gayathri   666        6            2

gayathri@alahomora:~/SS_Lab_2$ ./a.out
Enter the key (in hex format, e.g., 0x61051b9f): 0x61051b9f
Message queue removed successfully.
gayathri@alahomora:~/SS_Lab_2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages

gayathri@alahomora:~/SS_Lab_2$
*/

