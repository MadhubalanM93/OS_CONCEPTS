//Create a TCP server that receives and displays a message sent by a client.

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int serverfd, clientfd;
    char msg[100];

    struct sockaddr_in server;

    serverfd = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = INADDR_ANY;

    bind(serverfd, (struct sockaddr *)&server, sizeof(server));

    listen(serverfd, 5);

    printf("Waiting for client...\n");

    clientfd = accept(serverfd, NULL, NULL);

    recv(clientfd, msg, sizeof(msg), 0);

    printf("Message Received: %s\n", msg);

    close(clientfd);
    close(serverfd);

    return 0;
}
