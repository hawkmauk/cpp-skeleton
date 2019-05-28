#define BOOST_TEST_MODULE greeter
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../greeter.cpp"  


BOOST_AUTO_TEST_CASE( constructor_tests )
{
	Greeter g1;
	BOOST_TEST( g1.greet() == "Hello user!" ); 
}
