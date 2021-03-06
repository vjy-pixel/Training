#include<linux/init.h>
#include<linux/fs.h>
#include<linux/module.h>
#include<linux/device.h>
#include<linux/kernel.h>
#include<linux/uaccess.h>

#define BUFSIZE 256

static char message[BUFSIZE]= "";//to carry a string from user space

static int __chrdrv_init(void);
static void __chrdrv_exit(void);
int chrdrv_open(struct inode *, struct file *);
int chrdrv_release(struct inode *, struct file *);

int chrdrv_open (struct inode *pinode, struct file *file_ops)
{
	//printk(KERN_ALERT"Inside %s function", __FUNCTION__);
	printk(KERN_ALERT "Device opened successfuly");
	return 0;
}

ssize_t chrdrv_read(struct file *file_ops, char __user *buffer, size_t length, loff_t *offset)
{
	printk(KERN_INFO"Inside %s function", __FUNCTION__);
	if(length > BUFSIZE)
		return -EINVAL;

	if(copy_to_user(buffer, message, length) != 0)
		return -EFAULT;
	
	return 0;
}
ssize_t chrdrv_write (struct file *file_ops, const char __user *buffer, size_t length, loff_t *offset)
{
	printk(KERN_INFO"Inside %s function", __FUNCTION__);
	if(length > BUFSIZE)
		return -EINVAL;

	if(copy_from_user(message, buffer, length) != 0)
		return -EFAULT;

	printk(KERN_INFO "Received Message from user:%s\n",message);
	return 0;
}
int chrdrv_release (struct inode *pinode, struct file *file_ops)
{
	//printk(KERN_ALERT"Inside %s function", __FUNCTION__);
	printk(KERN_ALERT "Device Closed Successfuly");
	return 0;

}


struct file_operations file_ops={
	.owner = THIS_MODULE,
	.open = chrdrv_open,
	.read = chrdrv_read,
	.write = chrdrv_write,
	.release = chrdrv_release

};


/*initialization function*/
static int __chrdrv_init(void)
{
	printk(KERN_INFO"In %s function", __FUNCTION__);
	register_chrdev(240,"char_drv",&file_ops);
	return 0;
}

/*exit function*/
static void __chrdrv_exit(void)
{
	printk(KERN_INFO"In %s function", __FUNCTION__);
	unregister_chrdev(240,"char_drv");
}

module_init(__chrdrv_init);
module_exit(__chrdrv_exit);

MODULE_LICENSE("GPL");
