/**
 * Adds a dice roll syscall to the kernel.
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Benjamin Miramontes");
MODULE_DESCRIPTION("Adds a dice roll syscall");
MODULE_VERSION("0.1");


int __init diceroll_init(void)
{
	printk(KERN_INFO "RollDice Module Loaded\n");
	return 0;
}


void __exit diceroll_exit(void)
{
	printk(KERN_INFO "RollDice Module Unloaded\n");
}


module_init(diceroll_init);
module_exit(diceroll_exit);
