//Send the message "Hello Queue" using a message queue and receive it in another process.

#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct message
{
    long type;
    char text[50];
};

int main()
{
    struct message msg;

    int id = msgget(1234,0666|IPC_CREAT);

    msg.type = 1;

    strcpy(msg.text,"Hello Queue");

    msgsnd(id,&msg,sizeof(msg.text),0);

    return 0;
}
