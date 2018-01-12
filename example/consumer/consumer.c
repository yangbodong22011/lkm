/*************************************************************************
	> File Name: module.c
	> Author: bodong.ybd
	> Mail: yangbodong22011 at gmail dot com 
 ************************************************************************/

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/semaphore.h>
#include <linux/kthread.h>
#include <linux/sched.h>
#include <asm/atomic.h>
#include <linux/delay.h>

#define PRODUCT_NUMS 10

static struct semaphore sem_producer;
static struct semaphore sem_consumer;
static char product[12];
static atomic_t num;
static int producer(void *product);
static int consumer(void *product);
static int id = 1;
static int consume_num = 1;

static int producer(void *p) {
    char *product = (char *)p;
    int i;
    atomic_inc(&num);
    printk("producer[%d] start...\n", current->pid);
    for (i = 0; i < PRODUCT_NUMS; ++i) {
        down(&sem_producer);
        snprintf(product, 16, "%d product", id++);
        printk("producer[%d] produce :%s\n", current->pid, product);
        up(&sem_consumer);
    }
    printk("producer[%d] exit...\n", current->pid);
    return 0;
}

static int consumer(void *p) {
    char *product = (char *)p;

    printk("consumer[%d] start...\n", current->pid);
    for (;;) {
        msleep(100);
        down_interruptible(&sem_consumer);
        if(consume_num >= PRODUCT_NUMS * atomic_read(&num)) break;
        printk("consumer[%d] consume :%s\n", current->pid, product);
        consume_num++;
        memset(product, '\0', 16);
        up(&sem_producer);
    }
    printk("consumer [%d] exit...\n", current->pid);
    return 0;
}

static int __init consumer_init(void)
{
    printk(KERN_ALERT "Enter Module\n");
    sema_init(&sem_producer, 0);
    sema_init(&sem_consumer, 1);
    atomic_set(&num, 0);
    //kernel_thread(producer, product, CLONE_KERNEL);
    //kernel_thread(consumer, product, CLONE_KERNEL);
    kthread_run(producer, product, CLONE_KERNEL);
    kthread_run(consumer, product, CLONE_KERNEL);
    return 0;
}

static void __exit consumer_exit(void)
{
    printk(KERN_ALERT "Leave Module\n");
}

module_init(consumer_init);
module_exit(consumer_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Yang Bodong");

