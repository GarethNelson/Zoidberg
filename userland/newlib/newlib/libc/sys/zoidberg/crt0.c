#include <efi.h>
#include <efilib.h>
#include <setjmp.h>

#include "syscalls.h"

extern int main();

EFI_SYSTEM_TABLE *ST;
EFI_BOOT_SERVICES *BS;
EFI_RUNTIME_SERVICES *RT;
EFI_HANDLE gImageHandle;

jmp_buf proc_start_env;


EFI_STATUS
efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) {
     sys_test(1,2,3);
     ST = SystemTable;
     BS = ST->BootServices;
     RT = ST->RuntimeServices;
     gImageHandle = ImageHandle;

       int i;
       i = setjmp(proc_start_env);
       if(i==0) {
          int ex = main();
          return ex;
       } 

       return i-1;
}
