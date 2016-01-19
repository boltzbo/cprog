#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

#define DRIVER_AUTHOR	"Chakraphan <cchakraphan@gmail.com>"
#define DRIVER_DESC		"A simple driver with defined information"

static int __init initialData __initdata = 3;

static int __init helloKernel2_init(void) {
	printk(KERN_INFO "Hello Kernel with init value: %d\n", initialData);
	return 0;
}

static void __exit helloKernel2_exit(void) {
	printk(KERN_INFO "Kill Hello Kernel 2 success.\n");
}

module_init(helloKernel2_init);
module_exit(helloKernel2_exit);



MODULE_LICENSE("GPL");

MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);

MODULE_SUPPORTED_DEVICE("testdevice");
