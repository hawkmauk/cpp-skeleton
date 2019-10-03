#include <string>

namespace skeleton{

// Application startup time (used for uptime calculation)
// const int64_t nStartupTime = GetTime();

// set the default configuration file name
const char * const CONF_FILENAME = "default.conf";

// return the version information
std::string getVersion()
{
    std::ostringstream oss;
    oss << "   ___                              __      " << std::endl
        << "  / _ \\__ _____  __________ _____  / /____  " << std::endl
        << " / , _/ // / _ \\/ __/ __/ // / _ \\/ __/ _ \\ " << std::endl
        << "/_/|_|\\_,_/_//_/\\__/_/  \\_, / .__/\\__/\\___/ " << std::endl
        << "                       /___/_/              " << std::endl
        << std::endl
        << APPLICATION_NAME << " - " << PACKAGE_STRING << std::endl
        << std::endl
        << "source:\t" << PACKAGE_URL << std::endl
        << "bugs:\t" << PACKAGE_BUGREPORT << std::endl
        << std::endl;
    return oss.str();
}

}
