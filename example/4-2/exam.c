/*************************************************************************
	> File Name: exam.c
	> Author: 
	> Mail: 
	> Created Time: Sun 12 Nov 2017 10:05:34 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int i;
    unsigned char *buff;

    buff = (char*)malloc(sizeof(char) * 1024);
    printf("My pid is:%d\n", getpid());

    for(i = 0; i < 60; ++i) {
        sleep(60);
    }
    return 0;
}
