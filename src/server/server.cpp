#include "server.hpp"
#include <config.h>
#include <sstream>
#include <string>

Server::Server() : m_name( "Server" ) { }

string Server::greet()
{
    std::ostringstream oss;
	oss << "Hello " << getName() << "!";
    return oss.str();
}

string Server::getVersion()
{
    return PACKAGE_NAME;
}
