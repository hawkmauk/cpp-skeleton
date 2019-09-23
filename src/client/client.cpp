#include "client.hpp"
#include <config.h>
#include <sstream>
#include <string>

Client::Client( ): m_name( "Client" )
{ }

string Client::greet()
{
    std::ostringstream oss;
	oss << "Hello " << getName() << "!"; 
    return oss.str();
}

string Client::getVersion()
{
    return PACKAGE_NAME;
}
