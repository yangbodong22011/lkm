/*************************************************************************
	> File Name: fork_user.c
	> Author: bodong.ybd
	> Mail: 
	> Created Time: Sun 26 Nov 2017 08:34:30 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    pid_t pid;
    pid = fork();
    return 0;
}
