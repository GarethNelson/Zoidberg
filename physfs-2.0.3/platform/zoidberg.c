/*
 *
 * Zoidberg platform support - more like UEFI + efilibc platform support right now
 *
 */

#define __PHYSICSFS_INTERNAL__
#include "physfs_internal.h"
#include "physfs_platforms.h"

#ifdef PHYSFS_PLATFORM_ZOIDBERG

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// Your kernel threading support is bad and you should feel bad
#if (defined PHYSFS_NO_THREAD_SUPPORT)
void *__PHYSFS_platformGetThreadID(void) { return((void *) 0x0001); }
void *__PHYSFS_platformCreateMutex(void) { return((void *) 0x0001); }
void __PHYSFS_platformDestroyMutex(void *mutex) {}
int __PHYSFS_platformGrabMutex(void *mutex) { return(1); }
void __PHYSFS_platformReleaseMutex(void *mutex) {}
#endif

int __PHYSFS_platformExists(const char *fname)
{
    FILE* fd = fopen(fname,"r");
    int retval=0;
    if(fd==NULL) {
       if(errno==ENOENT) return retval;
       retval=1; // this is a silly assumption
    } else {
       retval=1;
       fclose(fd);
    }
    return retval;
} /* __PHYSFS_platformExists */

static char *baseDir = NULL;

// TODO - fix this to actually get it from EFI in platformInit function
char *__PHYSFS_platformCalcBaseDir(const char *argv0)
{
    char *retval = (char *) allocator.Malloc(strlen(baseDir) + 1);
    BAIL_IF_MACRO(retval == NULL, ERR_OUT_OF_MEMORY, NULL);
    strcpy(retval, baseDir); /* calculated at init time. */
    return(retval);
} /* __PHYSFS_platformCalcBaseDir */


char *__PHYSFS_platformGetUserName(void)
{
    return(NULL);  /* (*shrug*) */
} /* __PHYSFS_platformGetUserName */


char *__PHYSFS_platformGetUserDir(void)
{
    return(__PHYSFS_platformCalcBaseDir(NULL));
} /* __PHYSFS_platformGetUserDir */

int __PHYSFS_platformInit(void)
{
    return(1);  /* always succeed. */
} /* __PHYSFS_platformInit */


int __PHYSFS_platformDeinit(void)
{
    return(1);  /* always succeed. */
} /* __PHYSFS_platformDeinit */

#endif
