bin_PROGRAMS = identityd
check_PROGRAMS = identityd_test

identityd_SOURCES = \
	src/identityd/main.cpp

identityd_test_SOURCES = \
	src/identityd/test/resolver-example-tests.cpp

identityd_test_LDADD = $(BOOST_FILESYSTEM_LIB) $(BOOST_SYSTEM_LIB) $(BOOST_UNIT_TEST_FRAMEWORK_LIB)

CC = g++

TESTS = $(check_PROGRAMS)

EXTRA_DIST = $(TESTS)
