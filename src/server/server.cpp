#include "server.hpp"
#include <config.h>
#include <sstream>
#include <string>
#include "../common/system.cpp"

// Default value for m_port
const int Server::DEFAULT_PORT = 6678;
// Default value for m_ipv4
const std::string Server::DEFAULT_IPV4 = "127.0.0.1";

// Constructor with member initialisation
Server::Server( int port, std::string ipv4 ) : m_port( port ), m_ipv4( ipv4 )
{
    //nothing to do
}

//Delegate initialisation with default values
Server::Server() : Server( Server::DEFAULT_PORT, Server::DEFAULT_IPV4 )
{
    //nothing to do
}


std::string Server::getVersion()
{
    return skeleton::getVersion();
}

