#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>

MODULE_AUTHOR("Boikivskiy Andriy");
MODULE_DESCRIPTION("Hello, world with parameter in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");

static uint hello_count = 1;
module_param(hello_count, uint, S_IRUGO);
MODULE_PARM_DESC(hello_count, "Amount of 'Hello world' to be printed");


static int __init hello_init(void)
{
	uint i;	

	if(hello_count == 0) {
    		printk(KERN_WARNING "'hello_count' value is 0\n");
  	} else if(hello_count >= 5 && hello_count <= 10) {
    		printk(KERN_WARNING "'hello_count'=%i value is between 5 and 10\n",hello_count);
  	} else if(hello_count > 10) {
    		printk(KERN_ERR "'hello_count'=%i value is under 10\n",hello_count);
    		return -EINVAL;
  	}

  	for(i = 0; i < hello_count; i++){
    		printk(KERN_INFO "Hello, world!\n");
  	}
  	return 0;
}

static void __exit hello_exit(void)
{
	/* Do nothing here right now */
}

module_init(hello_init);
module_exit(hello_exit);
