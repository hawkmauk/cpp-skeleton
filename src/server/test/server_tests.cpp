#define BOOST_TEST_MODULE server
#define BOOST_ALL_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <string>
#include "../server.cpp"  


BOOST_AUTO_TEST_CASE( constructor_tests )
{

    BOOST_TEST_MESSAGE( "Testing default initialisation: " );

    Server s1;

	BOOST_TEST( s1.getPort() == Server::DEFAULT_PORT ); 
	BOOST_TEST( s1.getIpv4() == Server::DEFAULT_IPV4 ); 

    BOOST_TEST_MESSAGE( "Testing initialisation: " );

    int port = 80;
    std::string ipv4 = "127.0.0.1";
    Server s2( port, ipv4 );

	BOOST_TEST( s2.getPort() == port ); 
	BOOST_TEST( s2.getIpv4() == ipv4 );

}
