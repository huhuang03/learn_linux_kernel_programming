#include <linux/init.h>
#include <linux/module.h>

MODULE_AUTHOR("th");
MODULE_LICENSE("Dual BSD/GPL");
MODULE_DESCRIPTION("LLKD book:ch04/hellworld_lkm: hello world, our first LKM");
MODULE_VERSION("0.0.1");

static int __init hello_init(void)
{
    printk(KERN_INFO "Hello, world\n");
    return 0;
}

static void __exit hello_exit(void) {
    printk(KERN_ALERT "Goodbye, cruel world\n");
}

module_init(hello_init);
module_exit(hello_exit);