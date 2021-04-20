#include <pwd.h>
#include <grp.h>
#include <ctype.h>

#include "tlpi_hdr.h"

char *
userNameFromId(uid_t uid)
{
    struct passwd *pwd;

    pwd = getpwuid(uid);
    return (pwd == NULL) ? NULL : pwd->pw_name;
}

uid_t
userIdFromName(const char *name)
{
    struct passwd *pwd;
    uid_t uid;
    char *endptr;

    if(name == NULL || *name == '\0')
        return -1;

    uid = strtol(name, &endptr, 10);
    if(*endptr == '\0')
        return uid;

    pwd = getpwnam(name);
    if(pwd == NULL)
        return -1;
    
    return pwd->pw_uid;
}

char *
groupNameFromId(gid_t gid)
{
    struct group *grp;

    grp = getgrgid(gid);
    return (grp == NULL) ? NULL : grp->gr_name;
}

gid_t
groupIdFromName(const char *name)
{
    struct group *grp;

    gid_t gid;
    char *endptr;

    if(name == NULL || *name == '\0')
        return -1;
    
    gid = strtol(name, &endptr, 10);
    if(*endptr == '\0')
        return gid;
    
    grp = getgrnam(name);
    if(grp == NULL)
        return -1;

    return grp->gr_gid;
}