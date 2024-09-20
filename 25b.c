/*
============================================================================
Name : 25b.c
Author : G Gayathri
Description : Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
b. uid, gid 
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

    // Print UID and GID
    printf("UID: %d\n", buf.msg_perm.uid);
    printf("GID: %d\n", buf.msg_perm.gid);
    return 0;
}

/*
Output:

key        msqid      owner      perms      used-bytes   messages    
0x61051b9f 13         gayathri   666        6            2 
gayathri@alahomora:~/SS_Lab_2$ cc 25b.c
gayathri@alahomora:~/SS_Lab_2$ ./a.out
Enter the message queue ID: 13
UID: 1000
GID: 1000
*/
