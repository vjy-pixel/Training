#include<linux/module.h>
#include<linux/kernel.h>
//#include<linux/init.h>


static int hello_init(void)
{
	printk(KERN_INFO"Hello World!!!\n");
	return 0;
}

static void hello_cleanup(void)
{
	printk(KERN_INFO"Bye!!!\n");

}

module_init(hello_init);
module_exit(hello_cleanup);
