#include "tlpi_hdr.h"

#include <sys/stat.h>
#include <sys/uio.h>
#include <fcntl.h>

int 
main(int argc, char **argv)
{
    int fd;
    struct iovec iov[3];
    struct iovec *iovptr;
    struct stat sb;
    int x;
    #define STR_SIZE    100
    char str[STR_SIZE];
    ssize_t numRead, totRequired;

    if(argc != 2 || strcmp(argv[1], "--help") == 0)
        usageErr("%s filename\n", argv[0]);
    
    fd = open(argv[1], O_RDONLY);
    if(fd == -1)
        errExit("open");

    totRequired = 0;
    iovptr = &iov[0];
    iovptr->iov_base = &sb;
    iovptr->iov_len = sizeof(struct stat);
    totRequired += iovptr->iov_len;

    iovptr = &iov[1];
    iovptr->iov_base = &x;
    iovptr->iov_len = sizeof(int);
    totRequired += iovptr->iov_len;

    iovptr = &iov[2];
    iovptr->iov_base = &str[0];
    iovptr->iov_len = STR_SIZE;
    totRequired += iovptr->iov_len;

    numRead = readv(fd, &iov[0], 3);
    if(numRead == -1)
        errExit("readv");
    
    if(numRead < totRequired)
        printf("Read fewer bytes than requested\n");
    
    printf("total bytes requested: %ld; bytes read: %ld\n", (long)totRequired, (long)numRead);

    close(fd);
    exit(EXIT_SUCCESS);
}