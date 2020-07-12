//#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
#include<linux/fs.h> //For Character device driver

ssize_t chrdrv_read(struct file *file_ops, char __user *buffer, size_t length, loff_t *offset)
{
	printk(KERN_ALERT"Inside %s function", __FUNCTION__);	
	return 0;
}
ssize_t chrdrv_write (struct file *file_ops, const char __user *buffer, size_t length, loff_t *offset)
{
	printk(KERN_ALERT"Inside %s function", __FUNCTION__);
	return length;
}
int chrdrv_open (struct inode *pinode, struct file *file_ops)
{
	printk(KERN_ALERT"Inside %s function", __FUNCTION__);
	return 0;
}
int chrdrv_release (struct inode *pinode, struct file *file_ops)
{
	printk(KERN_ALERT"Inside %s function", __FUNCTION__);
	return 0;

}


struct file_operations file_ops={
	.owner = THIS_MODULE,
	.open = chrdrv_open,
	.read = chrdrv_read,
	.write = chrdrv_write,
	.release = chrdrv_release

};


static int chrdrv_init(void)
{
	printk(KERN_ALERT"Inside %s function", __FUNCTION__);
	register_chrdev(139,"Character Driver",&file_ops);
	return 0;
}

static void chrdrv_exit(void)
{
	printk(KERN_ALERT"Inside %s function", __FUNCTION__);
	unregister_chrdev(139,"Character Driver");
}

module_init(chrdrv_init);
module_exit(chrdrv_exit);