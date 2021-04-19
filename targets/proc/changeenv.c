#define     _GNU_SOURCE         /** To get various declarations from <stdlib.h> **/
#include <stdlib.h>

#include "tlpi_hdr.h"

extern char **environ;

int
main(int argc, char **argv)
{
    int jj;
    char **ep;

    clearenv();     /// erase entire environment

    for(jj = 1; jj < argc; jj++)
        if(putenv(argv[jj]) != 0)
            errExit("putenv: %s", argv[jj]);
    
    if(setenv("GREET", "Hello world", 0) == -1)
        errExit("setenv");

    unsetenv("BYE");

    for(ep = environ; *ep != NULL; ep++)
        puts(*ep);

    exit(EXIT_SUCCESS);
}