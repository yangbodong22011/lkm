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

static int pid;

module_param(pid, int, 0644);

static int printpid_init(void)
{
    struct task_struct *p;
    struct vm_area_struct *temp;

    printk("The virtual memory areas(VMA) are:\n");
    p = pid_task(find_vpid(pid), PIDTYPE_PID);
    //p = find_task_by_vpid(pid);
    temp = p->mm->mmap;

    while (temp) {
        printk("strat:%p\tend:%p\n", (unsigned long*)temp->vm_start, (unsigned long*)temp->vm_end);
        temp = temp->vm_next;
    }

    return 0;
}

static void printpid_exit(void)
{
    printk(KERN_ALERT "Printpid out\n");
    return;
}

module_init(printpid_init);
module_exit(printpid_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("YangBodong");
MODULE_DESCRIPTION("foreach VMA");


