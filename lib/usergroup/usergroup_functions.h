#ifndef _USER_GROUP_FUNCTIONS_H
#define _USER_GROUP_FUNCTIONS_H

#include <unistd.h>

extern char * userNameFromId(uid_t uid);
extern uid_t userIdFromName(const char *name);
extern char * groupNameFromId(gid_t gid);
extern gid_t groupIdFromName(const char *name);

#endif