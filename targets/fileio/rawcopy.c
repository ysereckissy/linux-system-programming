///--------------------------------------------------------------------------------------
/// !!! NOT SURE THIS IS THE RIGHT SOLUTION. TO BE CHECKED AGAIN!!!
///--------------------------------------------------------------------------------------
#include "tlpi_hdr.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int
main(int argc, char **argv)
{
    /// this program has two required arguments
    if(argc != 3 || strcmp(argv[1], "--help") == 0)
        usageErr("%s <filename> <copyname>\n", argv[0]);
    if(strcmp(argv[1], argv[2]) == 0)
    {
        char errorMsg[] = "<filename> and <copyname> must be different!\n";
        write(STDERR_FILENO, errorMsg, sizeof(errorMsg));
        usageErr("%s <filename> <copyname>\n", argv[0]);
    }
    /// open the file and get information
    int inputFile = open(argv[1], O_RDONLY);
    if(inputFile == -1)
        errExit("->failed to open the file %s\n", argv[1]);

    mode_t mode = S_IREAD | S_IWRITE;
    int outputFile = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, mode);
    if(outputFile == -1)
        errExit("->failed to open file %s in write mode\n", argv[2]);

    #define CP_BLOCK_SIZE      256
    char buffer[CP_BLOCK_SIZE];
    struct stat sb;
    if(stat(argv[1], &sb) == -1)
        errExit("->failed to get file information\n");
    printf("total size of the file: %ld\n", sb.st_size);
    off_t loopCount = sb.st_size / CP_BLOCK_SIZE;
    int numRead, numWritten;

    while(loopCount--)
    {
        if((numRead = read(inputFile, buffer, CP_BLOCK_SIZE)) > 0)
            if(write(outputFile, buffer, numRead) != numRead)
                errExit("->failed to write to the file");
    }

    if(sb.st_size % CP_BLOCK_SIZE)
        if((numRead = read(inputFile, buffer, CP_BLOCK_SIZE)) > 0)
            if(write(outputFile, buffer, numRead) != numRead)
                errExit("->failed to write to the file");

    close(inputFile);
    close(outputFile);

    exit(EXIT_SUCCESS);
}