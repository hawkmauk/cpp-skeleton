#include "client.hpp"
#include "../common/system.hpp"

#include <stdlib.h>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>


Client::Client( ): m_name( "Client" )
{
    int sockfd, portno, result;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];

    // Create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        skeleton::error("ERROR openeing socket");

    //create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        skeleton::error("ERROR openeing socket");

    // clear address structure
     memset((char *) &serv_addr, 0, sizeof(serv_addr));

    /* setup the host_addr structure for use in bind call */
     // server byte order
     serv_addr.sin_family = AF_INET;
     
     // automatically be filled with current host's IP address
     serv_addr.sin_addr.s_addr = INADDR_ANY;

    // convert short integer value for port must be converted into network byte order
     serv_addr.sin_port = htons( DEFAULT_DAEMON_PORT );


    // Connect to socket
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
        skeleton::error("ERROR connecting");

    // Prompt user for input
    printf("Please enter the message: ");
    // Blank the buffer memory
    memset((char *) &buffer, 0, 256);
    // Get the user input
    fgets(buffer,255,stdin);
    // Write the input to the socket
    result = write(sockfd, buffer, strlen(buffer));
    if (result < 0) 
         skeleton::error("ERROR writing to socket");

    // Blank the buffer memory
    memset((char *) &buffer, 0, 256);
    // Read response into buffer
    result = read(sockfd, buffer, 255);
    if (result < 0) 
         skeleton::error("ERROR reading from socket");
    
    // Print the buffer output
    printf("%s\n", buffer);
    // Close the socket
    close(sockfd);
}

string Client::getVersion()
{
    return skeleton::getVersion( APPLICATION_NAME );
}
