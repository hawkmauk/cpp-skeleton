#ifdef STAND_ALONE
#   define BOOST_TEST_MODULE Main
#endif
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(server_binding_suite)

BOOST_AUTO_TEST_CASE(test_port)
{
    BOOST_CHECK( 2<1 );
}

BOOST_AUTO_TEST_SUITE_END()

