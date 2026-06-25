#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int sockfd;
    char msg[100];

    struct sockaddr_in server, client;
    socklen_t len;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = INADDR_ANY;

    bind(sockfd, (struct sockaddr *)&server, sizeof(server));

    len = sizeof(client);

    recvfrom(sockfd, msg, sizeof(msg), 0,
             (struct sockaddr *)&client, &len);

    printf("Received: %s\n", msg);

    close(sockfd);

    return 0;
}
