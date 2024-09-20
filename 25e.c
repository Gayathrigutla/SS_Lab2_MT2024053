/*
============================================================================
Name : 25e.c
Author : G Gayathri
Description : Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
e. size of the queue
Date: 20th Sep, 2024.
============================================================================
*/


#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>

int main(void) {
    int msgid;

    // Ask the user to enter the message queue ID
    printf("Enter the message queue ID: ");
    scanf("%d", &msgid);

    struct msqid_ds buf;

    // Get message queue information
    if (msgctl(msgid, IPC_STAT, &buf) == -1) {
        perror("msgctl");
        return 1;
    }

    // Print size of the queue
    printf("Size of the Queue: %ld bytes\n", buf.msg_qbytes);
    return 0;
}


/*
Output:

key        msqid      owner      perms      used-bytes   messages    
0x61051b9f 13         gayathri   666        6            2 
gayathri@alahomora:~/SS_Lab_2$ cc 25e.c
gayathri@alahomora:~/SS_Lab_2$ ./a.out
Enter the message queue ID: 13
Size of the Queue: 16384 bytes
*/
