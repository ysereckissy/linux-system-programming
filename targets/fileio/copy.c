#include <sys/stat.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

#ifndef BUF_SIZE        /** Allow "cc -D" to override the definition **/
#define BUF_SIZE    1024
#endif

int
main(int argc, char *argv[])
{
    int inputFd, outputFd, openFlags;
    mode_t filePerms;
    ssize_t numRead;
    char buffer[BUF_SIZE];
    /// perform minimum argument checks and print usage help accordingly
    if(argc != 3 || strcmp(argv[1], "--help") == 0)
        usageErr("%s old-file new-file\n", argv[0]);
    
    /// Open input and output files
    inputFd = open(argv[1], O_RDONLY);
    if(inputFd == -1)
        errExit("opening file %s", argv[1]);
    openFlags = O_CREAT | O_WRONLY | O_TRUNC;
    filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH; /** rw-rw-rw **/
    outputFd = open(argv[2], openFlags, filePerms);
    if(outputFd == -1)
        errExit("opening file %s", argv[2]);
    /// Trasfer data until we encouter end of input file or error
    while((numRead = read(inputFd, buffer, BUF_SIZE)))
        if(write(outputFd, buffer, numRead) != numRead)
            fatal("couldn't write whole buffer");

    if(numRead == -1)
        errExit("read");
    if(close(inputFd) == -1)
        errExit("close input");
    if(close(outputFd) == -1)
        errExit("close output");

    exit(EXIT_SUCCESS);
}