#include <linux/init.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>
#include <linux/slab.h>

#define MY_DEV_NAME "panic_test"
#define DEBUG_FLAG "PROC_TEST_DEV: "
MODULE_AUTHOR("Zheng");
MODULE_LICENSE("Dual BSD/GPL");

int test_open (struct inode *, struct file *);
ssize_t test_read (struct file *, char __user *, size_t, loff_t *);
ssize_t test_write (struct file *, const char __user *, size_t, loff_t *);


static struct file_operations my_drv = {
	.open = test_open,
	.read = test_read,
	.write = test_write,
};

int test_open (struct inode * test_inode, struct file * test_file) {
	// Do nothing
	return 0;
}

ssize_t test_read (struct file *test_file, char __user *buf, size_t size, loff_t *offset)
{
	// panic
	(1, DEBUG_FLAG"device read invoked, panic\n");
	return (ssize_t)0;
}

ssize_t test_write (struct file *test_file, const char __user *buf, size_t size, loff_t *offset)
{
	// panic
	WARN(1, DEBUG_FLAG"device write invoked, panic\n");
	return (ssize_t)0;
}

int __init test_init(void)
{
	struct proc_dir_entry *test_entry;
	const struct file_operations *my_fops = &my_drv;
	
	test_entry = proc_create(MY_DEV_NAME, S_IRUGO|S_IWUGO, NULL, my_fops);
	if (!test_entry)
		printk(DEBUG_FLAG "proc init failed\n");
	printk(DEBUG_FLAG "panic test drive is up");
	return 0;
}

module_init(test_init);