#ifndef PROGRAM_UTIL_SYSTEM_H
#define PROGRAM_UTIL_SYSTEM_H

#if defined(HAVE_CONFIG_H)
#include <config.h>
#endif
#include <stdio.h>
#include <stdlib.h>

/*
*  Application stratup tima (used for uptime calculation)
*/
extern const char * const PROGRAM_CONF_FILENAME;

/*
*  Standard error processing
*/
void error(const char *msg)
{
    perror(msg);
    exit(1);
}

#endif
