#include <stdio.h>
#include <cstdlib>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}