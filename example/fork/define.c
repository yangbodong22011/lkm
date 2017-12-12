/*************************************************************************
	> File Name: define.c
	> Author: bodong.ybd
	> Mail: 
	> Created Time: Sun 26 Nov 2017 08:45:14 PM CST
 ************************************************************************/

#include <stdio.h>
#define CLONE_UNTRACED		0x00800000	/* set if the tracing process can't force CLONE_PTRACE on this clone */

int main(int argc, char *argv[])
{
    printf("%d\n", 17 & CLONE_UNTRACED);

    return 0;
}
