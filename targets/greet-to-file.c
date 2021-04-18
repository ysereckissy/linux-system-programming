#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <gnu/libc-version.h>

int main(int argc, char *argv[])
{
    int fd;
    char greeting[] = "Hello to all the world \n";
    fd = open("greeting-file", O_WRONLY | O_CREAT, 0644);
    if(fd < 0)
    {
        printf("error number %d\n", errno);
        perror("greeting-file");
        exit(1);
    }
    write(fd, greeting, sizeof(greeting));
    close(fd);
    /// prints information about the libc on the system
    printf("GNU libc version: %s\n", gnu_get_libc_version());
    printf("GNU libc release: %s\n", gnu_get_libc_release());
}