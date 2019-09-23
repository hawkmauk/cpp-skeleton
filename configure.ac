dnl AUTOCONF
dnl Process this file with autoconf to produce a configure script.

define(_PROJECT_NAME, [skeleton])
define(_PROJECT_ISSUES, [https://github.com/runcrypto/skeleton/issues])
define(_PROJECT_SITE, [https://github.com/runcrypto/skeleton])
define(_CLIENT_VERSION_MAJOR, 0)
define(_CLIENT_VERSION_MINOR, 1)
define(_CLIENT_VERSION_REVISION, 0)
define(_CLIENT_VERSION_BUILD, 0)
define(_CLIENT_VERSION_RC, 0)
define(_CLIENT_VERSION_IS_RELEASE, false)
define(_COPYRIGHT_YEAR, 2019)
define(_COPYRIGHT_HOLDERS,[The %s developers])
define(_COPYRIGHT_HOLDERS_SUBSTITUTION,[[Runcrypto Ltd]])

dnl Initialise autoconf
AC_INIT([_PROJECT_NAME],m4_join([.], _CLIENT_VERSION_MAJOR, _CLIENT_VERSION_MINOR, _CLIENT_VERSION_REVISION, m4_if(_CLIENT_VERSION_BUILD, [0], [], _CLIENT_VERSION_BUILD))m4_if(_CLIENT_VERSION_RC, [0], [], [rc]_CLIENT_VERSION_RC),[_PROJECT_ISSUES],[_PROJECT_NAME],[_PROJECT_SITE])
dnl create config headers in the following directory
AC_CONFIG_HEADERS([src/config/config.h])
dnl define where to find m4 macros
AC_CONFIG_MACRO_DIR([build-aux/m4])
dnl this checks for config.sub and needs to be called after AC_INIT
AC_CONFIG_AUX_DIR([build-aux]) 
dnl Checks for programs.
AC_PROG_CXX
AC_PROG_CC
dnl Populates EXEEXT variable
AX_PROG_CC_FOR_BUILD

dnl -------------------------------
dnl Arguments
dnl -------------------------------

dnl set the option to build for debugging
AC_ARG_ENABLE(debug,
AS_HELP_STRING([--enable-debug],
               [enable debugging, default: no]),
[case "${enableval}" in
             yes) debug=true ;;
             no)  debug=false ;;
             *)   AC_MSG_ERROR([bad value ${enableval} for --enable-debug]) ;;
esac],
[debug=false])

AM_CONDITIONAL(DEBUG, test x"$debug" = x"true")


dnl -------------------------------
dnl m4 Macros
dnl -------------------------------

dnl test framework
dnl AX_GNU_AUTOTEST
AX_BOOST_BASE([1.65.1])
AX_BOOST_UNIT_TEST_FRAMEWORK

AC_CANONICAL_HOST

dnl Initialise AUTOMAKE
AM_INIT_AUTOMAKE([silent-rules foreign no-define subdir-objects])

dnl Checks for header files.
AC_CHECK_HEADER_STDBOOL
AC_LANG_PUSH([C++])
AC_CHECK_HEADERS([syslog.h],[],[AC_MSG_ERROR(You need the Syslog libraries.)])
AC_CHECK_HEADERS([boost/test/unit_test.hpp],[],[AC_MSG_ERROR(You need the Boost libraries.)])
AC_LANG_POP([C++])

dnl Checks for libraries.

dnl Checks for typedefs, structures, and compiler characteristics.

dnl Checks for library functions.

dnl AUTOCONF
AC_CONFIG_FILES([Makefile])

AC_OUTPUT
