/*
============================================================================
Name : 28.c
Author : G Gayathri
Description : Write a program to change the exiting message queue permission. (use msqid_ds structure) 
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>
#include <string.h>

int main(void) {
    key_t key;
    int msgid;
    struct msqid_ds buf;

    printf("Enter the key: ");
    scanf("%d", &key);

    msgid = msgget(key, 0);
    if (msgid == -1) {
        perror("msgget");
        return 1;
    }

    // Get current permissions
    if (msgctl(msgid, IPC_STAT, &buf) == -1) {
        perror("msgctl IPC_STAT");
        return 1;
    }

    printf("Current permissions: %o\n", buf.msg_perm.mode);

    // Change permissions (e.g., to read and write for owner and group)
    buf.msg_perm.mode = 0660; // Set new permissions
    if (msgctl(msgid, IPC_SET, &buf) == -1) {
        perror("msgctl IPC_SET");
        return 1;
    }

    // Verify the change
    if (msgctl(msgid, IPC_STAT, &buf) == -1) {
        perror("msgctl IPC_STAT");
        return 1;
    }

    printf("New permissions: %o\n", buf.msg_perm.mode);

    return 0;
}

/*
Output:

gayathri@alahomora:~/SS_Lab_2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x61051b9f 13         gayathri   666        6            2

gayathri@alahomora:~/SS_Lab_2$ sudo ./a.out
Enter the key: 0x61051b9f
Current permissions: 0
New permissions: 660
gayathri@alahomora:~/SS_Lab_2$ 
*/
