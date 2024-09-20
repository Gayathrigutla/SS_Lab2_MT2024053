/*
============================================================================
Name : 25c.c
Author : G Gayathri
Description : Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
c. time of last message sent and received 
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>
#include <time.h>

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

    // Print time of last message sent and received
    printf("Time of Last Message Sent: %s", ctime(&buf.msg_stime));
    printf("Time of Last Message Received: %s", ctime(&buf.msg_rtime));
    return 0;
}

/*
Output:

key        msqid      owner      perms      used-bytes   messages    
0x61051b9f 13         gayathri   666        6            2 
gayathri@alahomora:~/SS_Lab_2$ cc 25c.c
gayathri@alahomora:~/SS_Lab_2$ ./a.out
Enter the message queue ID: 13
Time of Last Message Sent: Fri Sep 20 18:12:02 2024
Time of Last Message Received: Fri Sep 20 18:09:34 2024
*/
