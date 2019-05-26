dnl AUTOCONF
dnl Process this file with autoconf to produce a configure script.

define(_PROJECT_NAME, [skeleton])
define(_PROJECT_ISSUES, [https://github.com/runcrypto/skeleton/issues])
define(_PROJECT_SITE, [https://github.com/runcrypto/skeleton])

define(_CLIENT_VERSION_MINOR, 1)
define(_CLIENT_VERSION_REVISION, 0)
define(_CLIENT_VERSION_BUILD, 0)
define(_CLIENT_VERSION_RC, 0)
define(_CLIENT_VERSION_IS_RELEASE, false)

define(_COPYRIGHT_YEAR, 2019)
define(_COPYRIGHT_HOLDERS,[The %s developers])
define(_COPYRIGHT_HOLDERS_SUBSTITUTION,[[Runcrypto Ltd]])

dnl AUTOCONF
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([build-aux/m4])
AC_CONFIG_HEADERS([src/config/config.h])

AC_INIT([_PROJECT_NAME],m4_join([.], _CLIENT_VERSION_MAJOR, _CLIENT_VERSION_MINOR, _CLIENT_VERSION_REVISION, m4_if(_CLIENT_VERSION_BUILD, [0], [], _CLIENT_VERSION_BUILD))m4_if(_CLIENT_VERSION_RC, [0], [], [rc]_CLIENT_VERSION_RC),[_PROJECT_ISSUES],[bitcoin],[_PROJECT_SITE])

AC_CONFIG_FILES([Makefile])
AC_PREREQ([2.69])

dnl Checks for programs.
AC_PROG_CXX
AC_PROG_CC

dnl Checks for header files.
AC_CHECK_HEADER_STDBOOL
AC_LANG_PUSH([C++])
AC_CHECK_HEADERS([syslog.h],[],[AC_MSG_ERROR(You need the Syslog libraries.)])
AC_CHECK_HEADERS([boost/test/unit_test.hpp],[],[AC_MSG_ERROR(You need the Boost libraries.)])
AC_LANG_POP([C++])



dnl AUTOMAKE
AM_INIT_AUTOMAKE([silent-rules foreign no-define subdir-objects])

dnl test framework
AX_BOOST_BASE([1.65.1])
AX_BOOST_UNIT_TEST_FRAMEWORK


dnl Checks for libraries.



dnl Checks for typedefs, structures, and compiler characteristics.

dnl Checks for library functions.

AC_OUTPUT
