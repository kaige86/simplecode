#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include "test.h"

#define MDF_LOOP 10000000

void print_info(void)
{
    int i;
    int c = 0;

    for (i = 0; ; i++) {
        if (i > MDF_LOOP && c == 0) {
            //modify_code();
            asm("lea 0(%%rip), %%rax\n\
                 mov $0x0, %%bl\n\
                 mov %%bl, 6(%%rax)\n\
                 movl $1, %0"
                 : "=g"(c) 
                 : 
                 : "memory", "eax", "ebx");
        }

        if (c)
            printf("code modify failed!\n");
    }
}

void modify_code(void)
{
    memset((char *)print_info + 42, 0, 7);
}

void unprotect_code(void)
{
    int ret;

    ret = mprotect((void *)((long)print_info & (~0xFFF)), 0x1000, PROT_READ | PROT_WRITE | PROT_EXEC);
    if (ret != 0)
        printf("mprotect ret %d\n", ret);
}
