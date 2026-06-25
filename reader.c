//Write a message into a named pipe and read it from another program.

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    char msg[20];

    int fd = open("myfifo",O_RDONLY);

    read(fd,msg,sizeof(msg));

    printf("Received: %s\n",msg);

    close(fd);

    return 0;
}
