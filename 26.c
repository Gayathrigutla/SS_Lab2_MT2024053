/*
============================================================================
Name : 26.c
Author : G Gayathri
Description : Write a program to send messages to the message queue. Check $ipcs -q 
Date: 20th Sep, 2024.
============================================================================
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <string.h>

int main(void) {
    int msgid, size;
    key_t key;
    struct msg {
        long int mtype;
        char message[80];
    } mq;

    // Generate a unique key
    key = ftok(".", 'a');
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        return 1;
    }

    printf("Enter the message type: ");
    scanf("%ld", &mq.mtype);

    printf("Enter the message text: ");
    scanf(" %[^\n]", mq.message);
    size = strlen(mq.message);

    if (msgsnd(msgid, &mq, size + 1, 0) == -1) {
        perror("msgsnd");
        return 1;
    }

    printf("Message sent successfully.\n");
    return 0;
}

/*
Output:

gayathri@alahomora:~/SS_Lab_2$ cc 26.c
gayathri@alahomora:~/SS_Lab_2$ ./a.out
Enter the message type: 1
Enter the message text: 10
Message sent successfully.
gayathri@alahomora:~/SS_Lab_2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x61051b9f 4          gayathri   666        3            1           

gayathri@alahomora:~/SS_Lab_2$ ./a.out
Enter the message type: 2
Enter the message text: 20
Message sent successfully.
gayathri@alahomora:~/SS_Lab_2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x61051b9f 4          gayathri   666        6            2           

gayathri@alahomora:~/SS_Lab_2$ 
*/
