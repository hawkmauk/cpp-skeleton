#if defined(HAVE_CONFIG_H)
#include <config.h>
#endif

#include "boost/program_options.hpp"
#include <iostream>
#include <string>

namespace
{
    const size_t ERROR_IN_COMMAND_LINE = 1;
    const size_t SUCCESS = 0;
    const size_t ERROR_UNHANDLED_EXCEPTION = 2;
}

void SetupServerArgs(int argc, char ** argv)
{
    namespace po = boost::program_options;

    /*
    *  Set up the options
    */
    po::options_description desc( "Allowed Options" );
    desc.add_options()
        ("help", "Display help message")
        ("version", "Show verion information")
    ;

    po::variables_map vm;

    try
    {
        po::store(po::parse_command_line( argc, argv, desc ), vm );

        // help option
        if( vm.count( "help" ) )
        {
            std::cout << desc << "\n";
        }

        // version option
        if( vm.count( "version" ) )
        {

#if defined(HAVE_CONFIG_H)
            std::cout << "Version: " <<  "TODO" << "\n";
#else
            std::cout << "Version info not available" << "\n";
#endif 

        }

        // this throws on error, so do after help in case there
        // are any problems
        po::notify( vm );
    }
    catch( po::error& e )
    {
        std::cerr << "ERROR: " << e.what() << std::endl << std::endl;
        std::cerr << desc << std::endl;
    }
}
