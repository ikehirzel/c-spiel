#ifndef WARBLER_UTIL_PATH_H  
#define WARBLER_UTIL_PATH_H  

#include <warbler/util/primitives.h>

bool pathHasExtension(const char *path, const char *extension);
char *pathJoin(const char *left, const char *right);
char *pathGetRelative(const char *base, const char *path);
void santizePath(char *path);
char *pathDuplicate(const char *path);
char *pathGetFilename(const char *path);

#endif
