/*************************************************************************
	> File Name: module.c
	> Author: bodong.ybd
	> Mail: yangbodong22011 at gmail dot com 
 ************************************************************************/

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int __init _init(void)
{
    printk(KERN_ALERT "Enter Module\n");
    return 0;
}

static void __exit _exit(void)
{
    printk(KERN_ALERT "Leave Module\n");
}

module_init(_init);
module_exit(_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Yang Bodong");

