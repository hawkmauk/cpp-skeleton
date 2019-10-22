ACLOCAL_AMFLAGS = -I build-aux -I build-aux/m4
EXTRA_DIST = $(TESTS)
CC = g++
PYTHON=python3.7

bin_PROGRAMS = \
    server \
    client

check_PROGRAMS = \
    server_test \
    client_test

TESTS = $(check_PROGRAMS)


# If configure was run with --debug=true
if DEBUG
AM_CFLAGS = -g3 -O0
AM_CXXFLAGS = -g3 -O0
else
AM_CFLAGS = -O2
AM_CXXFLAGS = -O2
endif


# -------------------------
# Common
# -------------------------
# Common flags used for all targets
common_LDADD = $(BOOST_FILESYSTEM_LIB) $(BOOST_SYSTEM_LIB) $(BOOST_UNIT_TEST_FRAMEWORK_LIB)
common_CPPFLAGS = \
    -I$(top_srcdir)/config

common_SOURCES = \
    src/common/system.cpp

# -------------------------
# SERVER
# -------------------------

# $(top_builddir) is automatically populated by autoconf in config.status
serverdir = $(top_builddir)/src/server
server_BIN = $(top_builddir)/src/$(_PROJECT_NAME)d$(EXEEXT)

# List of the sources for the server
server_core_SOURCES = \
    $(common_SOURCES) \
    src/server/server.cpp

# This is the same as core sources but with main.cpp.  This is to avoid
# conflicts with main() when running the test suite

server_SOURCES = \
	src/server/main.cpp \
	$(server_core_SOURCES)

server_CPPFLAGS = \
    $(common_CPPFLAGS)

# Server unit tests
server_test_SOURCES = \
    $(server_core_SOURCES) \
	test/unit/server/server_tests.cpp

# Comiler flags
server_test_CPPFLAGS = \
    -I$(top_srcdir)/src/server/

# Linker flags
server_test_LDADD = \
    $(common_LDADD)


# -------------------------
# CLIENT
# -------------------------

# $(top_builddir) is automatically populated by autoconf in config.status
clientdir = $(top_builddir)/src/client
client_BIN = $(top_builddir)/src/$(_PROJECT_NAME)-cli$(EXEEXT)

client_core_SOURCES = \
    $(common_SOURCES) \
	src/client/client.cpp

client_SOURCES = \
    src/client/main.cpp \
    $(client_core_SOURCES)

client_CPPFLAGS = \
    $(common_CPPFLAGS)

client_test_SOURCES = \
    $(client_core_SOURCES) \
	test/unit/client/client_tests.cpp

client_test_LDADD = $(common_LDADD)

#---------------------------
# INTEGRATION TESTS
# --------------------------

if FUNCTIONAL_TESTS
PYTEST_OPTS := -v --timeout=550 --timeout_method=thread-p no:logging
PYTHONPATH=`pwd`/contrib/pyskeleton::$$PYTHONPATH

functionaldir = ../test/functional
check-local:
	$(PYTHON) $(functionaldir)/testrunner.py
endif
