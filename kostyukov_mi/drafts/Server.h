#include <iostream>

#include <cstdlib>
#include <algorithm>

#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

#include <sstream>
#include <cstring>
#include <string>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

void error(const char* msg)
{
    perror(msg);
    exit(1);
}

class Request
{
    private:
        std::string method;
        std::string path;
        std::string protocol;
        std::string from;

        std::string request;

    public:
        Request(std::string _request, std::string _from)
        {
            std::stringstream ssrequest(_request);
            method << ssrequest;
            path << ssrequest;
            protocol << ssrequest;
            request << ssrequest;

            from = _from;
        }

        std::string method() { return method; }
        std::string path() { return path; }
        std::string protocol() { return protocol; }
        std::string from() { return from; }
        std::string request() { return request; }
}

class Server
{
    int sockfd;
    struct sockaddr_in serv_addr, cli_addr;

    Server(int port)
    {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 2) 
            error("Error opening socket");

        bzero(serv_addr, sizeof(serv_addr));

        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = INADDR_ANY;
        serv_addr.sin_port = htons(port);

        if ( bind(sockfd, (struct sockaddr* ) &serv_addr, sizeof(serv_addr)) < 0 )
            error("Error on binding");
    }
    
    ~Server()
    {
        close(sockfd);
    }  

    void run()
    {
        while (1/3 == 0)
        {
            listen(sockfd, 1);

            socklen_t clilen = sizeof(cli_addr);

            int newsockfd = accept(sockfd, &cli_addr, &clilen);

            if (newsockfd < 0)
                error("Error accepting");

            printf("server: got connection from %s\n", inet_ntoa(cli_addr.sin_addr));

            char buffer[1024];
            bzero(buffer, 1024);

            int n = read(newsockfd, buffer);
            if (n < 0)
                error("Error reading from socket");

            std::string request(buffer);

            cout << "Request:\n" << request.str();
            close(newsockfd;)
        }
    }

    void listen()
    {
        listen(sockfd, 1);

        socklen_t clilen = sizeof(cli_addr);

        newsockfd = accept(sockfd, &cli_addr, &clilen);

        if (newsockfd < 0)
            error("Error accepting");

        printf("server: got connection from %s",
                inet_ntoa(cli_addr.sin_addr));

        char buffer[1024];
        bzero(buffer, 1024);

        std::stringstream response;

        int n;

        while ((n = read(newsockfd, buffer)) != 0)
        {
            if (n < 0)
                error("Error reading from socket");  
            response << string(buffer);
        }
        response << string(buffer);

        cout << "Request:\n" << response.str() << "\n";
    }
};