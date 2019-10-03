#include "client.hpp"
#include <config.h>
#include <sstream>
#include <string>
#include "../common/system.cpp"

Client::Client( ): m_name( "Client" )
{ }

string Client::getVersion()
{
    return skeleton::getVersion();
}
