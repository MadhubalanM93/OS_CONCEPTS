//Send the message "Hello Queue" using a message queue and receive it in another process.

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct message
{
    long type;
    char text[50];
};

int main()
{
    struct message msg;

    int id = msgget(1234,0666|IPC_CREAT);

    msgrcv(id,&msg,sizeof(msg.text),1,0);

    printf("Received: %s\n",msg.text);

    return 0;
}
