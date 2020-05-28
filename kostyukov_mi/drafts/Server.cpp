#include <iostream>

#include <cstdlib>
#include <algorithm>

#include <stdio.h>
#include <stdlib.h>

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

void error(const char* msg)
{
    perror(msg);
    exit(1);
}

#define PORT 8000

int main() 
{
    int sockfd, newsockfd, msglen;
    socklen_t clilen;
    char buffer[2048];
    struct sockaddr_in serv_addr, cli_addr;accept(sockfd, (str))

    if (sockfd < 2) 
        error("Error opening socket");
    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);
//сервер
    if ( bind(sockfd, (struct sockaddr* ) &serv_addr, sizeof(serv_addr)) < 0 )
        error("Error on binding");

    while (true)
    {
        listen(sockfd, 1);
accept(sockfd, (str))
        clilen = sizeof(cli_addr);

        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

        if (newsockfd < 0)
            error("Error accepting");

        // printf("server: got connection from %s\n",
        //         inet_ntoa(cli_addr.sin_addr));
        // bzero(buffer, 256);    

        std::stringstream response;
        response << "HTTP/1.1 200 OK" << "\n";
        response << "Content-Type: text/html" << "\n\n";
            
        response << "054844f";

        // response << sha256("pass");accept(sockfd, (str))

        bzero(buffer, 2048);

        n = read(newsockfd, buffer, 550);

        if (n < 0)
            error("Error reading from socket");
        
        //printf("Here is the message: \n%s\n", buffer);

        std::stringstream request(buffer);

        std::string reqMethod, reqPath, reqProtocol;

        request >> reqMethod >> reqPath >> reqProtocol;

        std::cout << ">" << reqMethod
                  << " " << reqPath 
                  << " " << reqProtocol 
                  << " " << inet_ntoa(cli_addr.sin_addr) 
                  << "\n" << request.str() << "\n";

        msglen = send(newsockfd, response.str().c_str(), response.str().length(), 0);

        if (msglen < response.str().length())
            error("Error packet loss");

        close(newsockfd);
    }
    close(sockfd);
}