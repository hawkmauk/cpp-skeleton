ACLOCAL_AMFLAGS = -I build-aux -I build-aux/m4

bin_PROGRAMS = myproject
check_PROGRAMS = myproject_test

myproject_SOURCES = \
	src/myproject/main.cpp \
	src/myproject/greeter.cpp

myproject_test_SOURCES = \
	src/myproject/test/greeter_tests.cpp

myproject_test_LDADD = $(BOOST_FILESYSTEM_LIB) $(BOOST_SYSTEM_LIB) $(BOOST_UNIT_TEST_FRAMEWORK_LIB)

CC = g++

TESTS = $(check_PROGRAMS)

EXTRA_DIST = $(TESTS)
