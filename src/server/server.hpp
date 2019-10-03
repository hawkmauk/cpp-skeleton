#ifndef SKELETON_SERVER_H
#define SKELETON_SERVER_H
#define APPLICATION_NAME PACKAGE_NAME "d"

#include <string>


class Server {
	public:

        //default port number
        static const int DEFAULT_PORT;
        //default to any ip address
        static const std::string DEFAULT_IPV4;

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

        //accessor methods
        int getPort(){ return m_port; };
        std::string getIpv4(){ return m_ipv4; };

	private:

        //port number to bind to
		int m_port;
        //ipv4 address to bind to
        std::string m_ipv4;

};


#endif /* SKELETON_SERVER_H */
