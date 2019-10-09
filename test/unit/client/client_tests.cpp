#define BOOST_TEST_MODULE client
#define BOOST_ALL_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <sstream>
#include <string>
#include <src/client/client.cpp>  


BOOST_AUTO_TEST_CASE( constructor_tests )
{
	Client c;

    BOOST_TEST_MESSAGE( "Testing default constructor: " );

	BOOST_TEST( true == false ); 

}
