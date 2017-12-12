/*************************************************************************
	> File Name: module.c
	> Author: bodong.ybd
	> Mail: yangbodong22011 at gmail dot com 
 ************************************************************************/

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/list.h>
#include <linux/spinlock.h>
#include <linux/kdev_t.h>

#define FILE_SYSTEM_ADDRESS 0xffffffff81f55740
#define SB_LOCK_ADDRESS 0xffffffff81f54ce0

static int __init file_init(void)
{
    printk(KERN_ALERT "Enter Module\n");
    struct file_system_type **head = (struct file_system_type **)FILE_SYSTEM_ADDRESS;

    spin_lock((spinlock_t *)SB_LOCK_ADDRESS);
    while(*head) {
        printk(KERN_ALERT "files_system:%s\n",(*head)->name);
        *head = (*head)->next;
    }
    spin_unlock((spinlock_t *)SB_LOCK_ADDRESS);
    return 0;
}

static void __exit file_exit(void)
{
    printk(KERN_ALERT "Leave Module\n");
}

module_init(file_init);
module_exit(file_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Yang Bodong");

