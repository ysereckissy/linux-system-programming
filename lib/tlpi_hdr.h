#ifndef TLPI_HDR_H
#define TLPI_HDR_H
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h> /** Prototypes for commonly used library functions, plus EXIT_SUCCESS and EXIT_FAILURES**/

#include <unistd.h> /** prototypes for many system calls **/
#include <errno.h>  /** Declares errno and defines error constants **/
#include <string.h> /** Commonly used string-handling functions **/

#include "get_num.h"
#include "error_functions.h"

typedef enum 
{
    FALSE,
    TRUE
} Boolean;

#define min(m,n) ((m) < (n) ? (m) : (n))
#define max(m,n) ((m) > (n) ? (m) : (n))
#endif