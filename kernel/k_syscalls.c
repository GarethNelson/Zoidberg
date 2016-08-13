#include "k_syscalls.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "k_thread.h"
#include "kmsg.h"
#include "dmthread.h"
#include "k_utsname.h"
#include "k_vfs.h"

#include <Library/BaseLib.h>

extern EFI_BOOT_SERVICES *BS;

void sys_exit() {
//     kill_task(ctx->task_id);
}

void conv_backslashes(CHAR16 *s)
{
        while (*s != 0)
        {
                if(*s == '/')
                        *s = '\\';
                s++;
        }
}


extern void uefi_run(void* _t);
// pid_t spawn(char* path)
pid_t sys_spawn(char* path) {
     CHAR16 *wfname = (CHAR16 *)malloc((strlen(path) + 1) * sizeof(CHAR16));
     mbstowcs((wchar_t *)wfname, path, strlen(path) + 1);
     conv_backslashes(wfname);
     req_task(&uefi_run,(void*)wfname);
     // TODO - fix the memory leak without early free()
  //   free(wfname);
}

void sys_null() { }

pid_t sys_vfork() {
      UINT64 parent_id = get_cur_task();
      UINT64 child_id  = clone_task(parent_id);
      if(sys_getpid() == parent_id) return child_id;
      return 0;
}

pid_t sys_getpid() {
      return get_cur_task();
}

// ssize_t read(unsigned int fd, char* buf, size_t count)
ssize_t sys_read(unsigned int fd, void* buf, size_t count) {
      return read(fd,buf,count);
}

// ssize_t write(int fd, void* buf, uint32 count)
ssize_t sys_write(unsigned int fd, void* buf, size_t count) {
      // TODO implement multiple terminals etc, different stdin/stdout for different processes
      // TODO map the fd for the calling process
      return write(fd,buf,count);
}

void* sys_malloc(size_t size) {
      return malloc(size);
}

void sys_free(void* ptr) {
     free(ptr);
}

void* sys_realloc(void* ptr, size_t size) {
      return realloc(ptr,size);
}

int sys_uname (struct utsname *buf) {
     *buf = zoidberg_uname;
    return 0;
}

pid_t sys_wait(int* status) {
}

int sys_execve(char *filename, char **argv, char** envp) {
    return 0;
}

