#define BOOST_TEST_MODULE server
#define BOOST_ALL_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <string>
#include <src/server/server.cpp>  


BOOST_AUTO_TEST_CASE( constructor_tests )
{

    BOOST_TEST_MESSAGE( "Testing default initialisation: " );

    Server s1;
    BOOST_TEST_MESSAGE( "Testing initialisation: " );
    BOOST_TEST(true);
    s1.stop();
}
