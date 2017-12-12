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

#define SUPER_BLOCKS_ADDRESS 0xffffffff81a40d50
#define SB_LOCK_ADDRESS 0xffffffff81f54ce0

static int __init super_init(void)
{
    printk(KERN_ALERT "Enter Module\n");
    
    struct super_block *sb;
    struct list_head *pos;
    struct list_head *linode;
    struct inode *pinode;
    unsigned long long count = 0;
    
    printk("\n print some fields of super_block:\n");
    spin_lock((spinlock_t *)SB_LOCK_ADDRESS);
    list_for_each(pos, (struct list_head *)SUPER_BLOCKS_ADDRESS) {
        sb = list_entry(pos, struct super_block, s_list);
        printk("dev_t: %d : %d , ", MAJOR(sb->s_dev), MINOR(sb->s_dev));
        printk("file_type name : %s\n", sb->s_type->name);

        list_for_each(linode, &sb->s_inodes) {
            pinode = list_entry(linode, struct inode, i_sb_list);
            count++;
            printk("%lu\t", pinode->i_ino);
        }
    }

    spin_unlock((spinlock_t *)SB_LOCK_ADDRESS);
    printk("The number of inodes: %llu\n", sizeof(struct inode) * count);
    return 0;
}

static void __exit super_exit(void)
{
    printk(KERN_ALERT "Leave Module\n");
}

module_init(super_init);
module_exit(super_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Yang Bodong");

