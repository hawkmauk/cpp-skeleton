ACLOCAL_AMFLAGS = -I m4

bin_PROGRAMS = server

server_SOURCES = \
	server.cpp

server_CPPFLAGS = -I$(top_srcdir)/common
server_LDADD = \
    ../common/libcommon.a

SUBDIRS = test
