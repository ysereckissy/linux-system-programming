#define _GNU_SOURCE
#include <unistd.h>
#include <sys/fsuid.h>
#include <limits.h>

#include "usergroup_functions.h"
#include "tlpi_hdr.h"

#define SG_SIZE     (NGROUPS_MAX + 1)

int
main(int argc, char **argv)
{
    uid_t ruid, euid, suid, fsuid;
    gid_t rgid, egid, sgid, fsgid;
    gid_t suppGroups[SG_SIZE];
    int numGroups, jj;
    char *p;

    if(getresuid(&ruid, &euid, &suid) == -1)
        errExit("getresuid");
    
    if(getresgid(&rgid, &egid, &sgid) == -1)
        errExit("getresgid");

    /** Attempts to change the file-system IDs are always ignored for unprivileged processes, 
     * but even so, the following calls return the current file-system IDs **/
    fsuid = setfsuid(0);
    fsgid = setfsgid(0);

    printf("UID: ");
    p = userNameFromId(ruid);
    printf("real=%s (%ld); ", (p == NULL)? "???" : p, (long)ruid);
    p = userNameFromId(euid);
    printf("effective=%s (%ld); ", (p == NULL)? "???" : p, (long)euid);
    p = userNameFromId(suid);
    printf("saved=%s (%ld); ", (p == NULL)? "???" : p, (long)suid);
    p = userNameFromId(fsuid);
    printf("file-system=%s (%ld)", (p == NULL)? "???" : p, (long)fsuid);
    printf("\n");

    printf("GID: ");
    p = groupNameFromId(rgid);
    printf("real=%s (%ld); ", (p == NULL)? "???" : p, (long)rgid);
    p = groupNameFromId(egid);
    printf("effective=%s (%ld); ", (p == NULL)? "???" : p, (long)egid);
    p = groupNameFromId(sgid);
    printf("saved=%s (%ld); ", (p == NULL)? "???" : p, (long)sgid);
    p = groupNameFromId(fsgid);
    printf("file-system=%s (%ld)", (p == NULL)? "???" : p, (long)fsgid);
    printf("\n");

    numGroups = getgroups(SG_SIZE, suppGroups);
    if(numGroups == -1)
        errExit("getgroups");

    printf("Supplementary groups (%d): ", numGroups);
    for(jj = 0; jj < numGroups; jj++)
    {
        p = groupNameFromId(suppGroups[jj]);
        printf("%s (%ld) ", (p == NULL) ? "???" : p, (long)suppGroups[jj]);
    }
    printf("\n");

    exit(EXIT_SUCCESS);
}