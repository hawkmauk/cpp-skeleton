#ifndef SKELETON_SYSTEM_H
#define SKELETON_SYSTEM_H
#include <sstream>

namespace skeleton
{
    // Handle Errors
    void error(const char *msg);
    // Return version info
    std::string getVersion( std::string application );
}
#endif