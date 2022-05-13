#include <linux/init.h>
#include <linux/module.h>

MODULE_AUTHOR("th");
MODULE_LICENSE("Dual BSD/GPL");
MODULE_DESCRIPTION("LLKD book:ch04/printk_loglvl: print in different");
MODULE_VERSION("0.0.1");

static int __init printk_loglvl_init(void)
{
    pr_emerg("Hello, world @ log-level KERN_EMERG [0]\n");
    pr_notice("Hello, world @ log-level KERN_NOTICE [5]\n");
    pr_info("Hello, world @ log-level KERN_INFO [6]\n");
    pr_debug("Hello, world @ log-level KERN_DEBUG [7]\n");
    return 0;
}

static void __exit printk_loglvl_exit(void) {
    pr_info("Goodbye, world @ log-level KERN_INFO [6]\n");
}

module_init(printk_loglvl_init);
module_exit(printk_loglvl_exit);