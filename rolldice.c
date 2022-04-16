/**
 * Adds a dice roll device driver to the kernel.
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/fs.h>

#define DEVICE_NAME "dice"


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Benjamin Miramontes");
MODULE_DESCRIPTION("Adds a dice roll device driver");
MODULE_VERSION("0.1");


static long rolldice_ioctl(struct file *fp, unsigned int cmd, unsigned long arg)
{
	(void)fp;
	(void)cmd;
	(void)arg;

	printk(KERN_INFO "RollDice: ioctl called!\n");

	return 0;
}


static const struct file_operations rolldice_file_ops = {
        .owner          = THIS_MODULE,
        .unlocked_ioctl = rolldice_ioctl,
};


static dev_t dev;
static struct cdev *cdevp;


int __init rolldice_init(void)
{
	int status;
	printk(KERN_INFO "RollDice: Module Loading ...\n");
	
	status = alloc_chrdev_region(&dev, 1, 1, DEVICE_NAME);
	if (status != 0)
	{
		return -EFAULT;
	}

	cdevp =	cdev_alloc();
	if (cdevp == NULL)
	{
		return -ENOMEM;
	}

	cdev_init(cdevp, &rolldice_file_ops);

	status = cdev_add(cdevp, dev, 1);
	if (status != 0)
	{
		return status;
	}

	printk(KERN_INFO "RollDice: Device registered with major %d\n", MAJOR(dev));
        printk(KERN_INFO "RollDice: e.g. 'mknod /dev/%s c %d %d'\n",
               DEVICE_NAME, MAJOR(dev), MINOR(dev));

	printk(KERN_INFO "RollDice: Module Loaded\n");
	return 0;
}


void __exit rolldice_exit(void)
{
	unregister_chrdev_region(dev, 1);
	printk(KERN_INFO "RollDice: Module Unloaded\n");
}


module_init(rolldice_init);
module_exit(rolldice_exit);
