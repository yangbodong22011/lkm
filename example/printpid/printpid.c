/*************************************************************************
	> File Name: hello.c
	> Author: 
	> Mail: 
	> Created Time: Wed 04 Oct 2017 09:44:35 PM CST
 ************************************************************************/

#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/list.h>
#include<linux/init_task.h>

static int printpid_init(void)
{
    struct task_struct *task,*p;
    struct list_head *pos;
    int count = 0;
    printk(KERN_ALERT "Printpid begin\n");
    task = &init_task;
    list_for_each(pos, &task->tasks) {
        p = list_entry(pos, struct task_struct, tasks);
        count++;
        printk(KERN_ALERT "%d ---> %s\n", p->pid, p->comm);
    }
    printk(KERN_ALERT "the number of process is: %d\n",count);
    return 0;
}

static void printpid_exit(void)
{
    printk(KERN_ALERT "Printpid out\n");
}

module_init(printpid_init);
module_exit(printpid_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("YangBodong");
MODULE_DESCRIPTION("This is list_for_each task_struct");


