#define BOOST_TEST_MODULE server
#define BOOST_ALL_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <string>
#include <server.hpp>


BOOST_AUTO_TEST_CASE( constructor_tests )
{

    BOOST_TEST_MESSAGE( "Testing default initialisation: " );

    int port = 1234;
    std::string ipv4 = "127.0.0.1";
    Server s1( port, ipv4 );
    BOOST_TEST_MESSAGE( "Testing initialisation: " );
    BOOST_TEST(true);
}
