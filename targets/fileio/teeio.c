#include "tlpi_hdr.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <getopt.h>

extern char *optarg;
extern int optind;


int 
main(int argc, char *argv[])
{
    int fileDescriptor;
    int flags = O_WRONLY | O_CREAT | O_TRUNC;
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;
    #define BUFFER_SIZE     256
    char buffer[BUFFER_SIZE];
    int numRead;

    if(argc < 2 || strcmp(argv[1], "--help") == 0)
        usageErr("%s filename\n", argv[0]);
    
    int opt;
    /// modified version: take the long option --append into account;
    struct option longOptions[] = {"append", no_argument, NULL, 'a'};
    int optionsIndex;
    
    /** while((opt = getopt(argc, argv, "a")) != -1) **/
    while((opt = getopt_long(argc, argv, "a", &longOptions[0], &optionsIndex)) != -1)
    {
        switch (opt)
        {
        case 'a':
            flags &= ~O_TRUNC;
            flags |= O_APPEND;
            break;
        default:
            usageErr("%s [-a] filename\n", argv[0]);
            break;
        }
    }
    char **filename = &argv[optind];
    fileDescriptor = open(*filename, flags, mode);
    if(fileDescriptor == -1)
        errExit("open");
    
    /// Use paratheses to manage precedence since > has higher precedence over =
    while((numRead = read(STDIN_FILENO, &buffer[0], BUFFER_SIZE)) > 0)
    {
        /// write to both the standard output and the file
        if(write(STDOUT_FILENO, buffer, strlen(buffer)) == -1)
            errExit("stdout write");
        if(write(fileDescriptor, buffer, strlen(buffer)) == -1)
            errExit("%s file write", *filename);
    }
    /// we are done, close the file
    close(fileDescriptor);
    exit(EXIT_SUCCESS);
}