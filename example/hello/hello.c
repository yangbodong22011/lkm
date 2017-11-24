/*************************************************************************
	> File Name: hello.c
	> Author: 
	> Mail: 
	> Created Time: Wed 04 Oct 2017 09:44:35 PM CST
 ************************************************************************/

#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

static int hello_init(void)
{
    printk(KERN_ALERT "This is the first\n");
    return 0;
}

static void hello_exit(void)
{
    printk(KERN_ALERT "Out,Out,I am out\n");
}

module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("YangBodong");
MODULE_DESCRIPTION("This is YangBodong first module");


