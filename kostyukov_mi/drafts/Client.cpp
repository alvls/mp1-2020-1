#include <iostream>

#include <cstdlib>
#include <algorithm>

#include <stdio.h>
#include <stdlib.h>

#include <memory.h>

#include <unistd.h>

#include <sstream>
#include <string>
#include <strings.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#include "sha2.cpp"

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    
    char buffer[256];

    sockfd = socket (AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("Error opening socket");
    server = gethostbyname(argv[1]);

    if (server == NULL)
        error("Error no such host");

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;

    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);

    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
        error("ERROR connecting");

    // printf("Please enter the message: ");
    // bzero(buffer,256);
    // fgets(buffer,255,stdin);
    // n = write(sockfd, buffer, strlen(buffer));
    n = write(sockfd, "Hi", 2);
    if (n < 0) 
         error("ERROR writing to socket");
    bzero(buffer,256);
    n = read(sockfd, buffer, 255);
    if (n < 0) 
         error("ERROR reading from socket");
    std::string response(buffer);

    if (response == sha256("pass"))
        std::cout << "Connected" << "\n";
    else
        std::cout << "Wrong pass" << "\n";

    close(sockfd);
    return 0;
}