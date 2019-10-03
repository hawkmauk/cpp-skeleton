#ifndef SKELETON_ARGSMANAGER_H
#define SKELETON_ARGSMANAGER_H

#include <string>

class ArgsManager()
{
public:

    /*
    *  Return true if the argument has been manually set
    *
    *  @param strArg Argument to get (e.g. "--foo")
    *  @return true if the argument has been set
    */
    bool std::IsArgSet(const std::string& strArg) const;

    /*
    *  Return argument as a string
    *
    *  @param strArg Argument to get (e.g. "--foo")
    *  @param strDefault (e.g. "bar")
`   *  @return command line argument or default value
    */
    std::string getArg(const std::string& strArg, const std::string& strDefault) const;

}

// Make gArgs avaialabe to the application
extern ArgsManager gArgs;

#endif
