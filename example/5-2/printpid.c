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
#include<asm/page.h>
#include<asm/pgtable.h>

static int irq;
static char *interface;
static int count = 0;

module_param(interface, charp, 0644);
module_param(irq, int, 0644);

static irqreturn_t intr_handler(int irq, void *dev_id)
{
    static long interval = 0;

    if (count == 0) {
        interval = jiffies;
    }

    interval = jiffies - interval;
    printk("The interval between two interrupts is %ld\n", interval);
    interval = jiffies;
    count ++;

    return IRQ_NONE;
}

static int printpid_init(void)
{
    if (request_irq(irq, &intr_handler, IRQF_SHARED, interface, &irq)) {
        printk(KERN_ERR "Fails to register IRQ %d\n", irq);
        return -EIO;
    }
    printk("%s Request on IRQ %d succeeded\n", interface, irq);
    return 0;
}

static void printpid_exit(void)
{
    printk("The %d interrupts happened on irq %d\n", count, irq);
    free_irq(irq, &irq);
    printk("Freeing IRQ %d\n", irq);
    return;
}

module_init(printpid_init);
module_exit(printpid_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("YangBodong");
MODULE_DESCRIPTION("VirToPhy");


