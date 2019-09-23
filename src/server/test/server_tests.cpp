#define BOOST_TEST_MODULE server
#define BOOST_ALL_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <sstream>
#include <string>
#include "../server.cpp"  


BOOST_AUTO_TEST_CASE( constructor_tests )
{
	Server s;

    std::ostringstream message;
    message << "greeting: " << s.greet() << std::endl;
    BOOST_TEST_MESSAGE( "Testing default greet: " );
    BOOST_TEST_MESSAGE( message.str() );

	BOOST_TEST( s.greet() == "Hello Server!" ); 

}
