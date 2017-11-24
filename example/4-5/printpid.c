/*************************************************************************
	> File Name: hello.c
	> Author: 
	> Mail: 
	> Created Time: Wed 04 Oct 2017 09:44:35 PM CST
 ************************************************************************/

#include<linux/init.h>
#include<linux/module.h>
#include<linux/interrupt.h>
#include<linux/kernel.h>
#include<linux/sched.h>
#include<linux/list.h>
#include<linux/init_task.h>
#include<linux/pid.h>
#include<linux/mm.h>
#include<linux/slab.h>
#include<linux/vmalloc.h>

unsigned long pagemem;
unsigned char* kmallocmem;
unsigned char* vmallocmem;

static int printpid_init(void)
{
    pagemem = __get_free_page(GFP_KERNEL);
    printk(KERN_INFO "pagemem=0x%lx\n", pagemem);
    kmallocmem = kmalloc(100, GFP_KERNEL);
    printk(KERN_INFO "kmallocmem=0x%p\n", kmallocmem);
    vmallocmem = vmalloc(1000000);
    printk(KERN_INFO "vmallocmem=0x%p\n", vmallocmem);
    return 0;
}

static void printpid_exit(void)
{
    vfree(vmallocmem);
    kfree(kmallocmem);
    free_page(pagemem);
    return;
}

module_init(printpid_init);
module_exit(printpid_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("YangBodong");
MODULE_DESCRIPTION("MALLOC");


