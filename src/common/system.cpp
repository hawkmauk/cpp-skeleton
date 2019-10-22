#include "system.hpp"
#include <config.h>
#include <iostream>
#include <stdio.h>
#include <cstdlib>

namespace skeleton{

    void error(const char *msg)
    {
        perror(msg);
        exit(1);
    }
    
    // return the version information
    std::string getVersion( std::string application )
    {
        std::ostringstream oss;
        oss << "   ___                              __      " << std::endl
            << "  / _ \\__ _____  __________ _____  / /____  " << std::endl
            << " / , _/ // / _ \\/ __/ __/ // / _ \\/ __/ _ \\ " << std::endl
            << "/_/|_|\\_,_/_//_/\\__/_/  \\_, / .__/\\__/\\___/ " << std::endl
            << "                       /___/_/              " << std::endl
            << std::endl
            << application << " - " << PACKAGE_STRING << std::endl
            << std::endl
            << "source:\t" << PACKAGE_URL << std::endl
            << "bugs:\t" << PACKAGE_BUGREPORT << std::endl
            << std::endl;
        return oss.str();
    }

}