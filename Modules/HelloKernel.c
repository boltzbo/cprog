#include <linux/init.h>
#include <linux/module.h>

#include <linux/moduleparam.h>

//int param_var = 0;
int param_var[3] = { 0,0,0 };

module_param_array(param_var, int, NULL, S_IRUSR | S_IWUSR);

void display(void) {
	printk(KERN_ALERT "Testing input param value : %d\n", param_var[0]);
	printk(KERN_ALERT "Testing input param value : %d\n", param_var[1]);
	printk(KERN_ALERT "Testing input param value : %d\n", param_var[2]);
}

static int helloKernel_init(void) {
	printk(KERN_ALERT "Hello Kernel, this is not a test.\n");
	display();
	return 0;
}

static void helloKernel_exit(void) {
	printk(KERN_ALERT "Good bye Kernel, see you in your dream.\n");
}

module_init(helloKernel_init);
module_exit(helloKernel_exit);

