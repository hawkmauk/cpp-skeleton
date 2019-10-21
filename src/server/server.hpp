#ifndef SKELETON_SERVER_H
#define SKELETON_SERVER_H
#define APPLICATION_NAME PACKAGE_NAME "d"

#include <stdio.h>
#include <string>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>


class Server {
	public:

        pid_t pid;

		//constructors
		Server();

        /*
        *  Creates a new server instance
        *
        *  @param port Port number to listen on
        *  @param ipv4 IPv4 address to bind to
        */
		Server( int port, std::string ipv4 );
		
		//methods
        std::string getVersion();

        int stop();

	private:

        int sockfd, newsockfd, portno;
        socklen_t clilen;
        char buffer[256];
        struct sockaddr_in serv_addr, cli_addr;
        char str[INET_ADDRSTRLEN];
        int m_port;
        std::string m_ipv4;

        // Daemonize the process to run in the background
        void daemonize();

};


#endif /* SKELETON_SERVER_H */
