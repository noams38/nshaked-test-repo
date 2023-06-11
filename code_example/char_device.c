#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "mydevice"
#define BUFFER_SIZE 1024

MODULE_LICENSE("GPL");

static int major_number;
static char buffer[BUFFER_SIZE];
static int buffer_len = 0;

// Open function
static int device_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "mydevice: device opened\n");
    return 0;
}

// Release function
static int device_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "mydevice: device released\n");
    return 0;
}

// Read function
static ssize_t device_read(struct file *file, char *buf, size_t count, loff_t *pos) {
    int bytes_to_read = count;
    if (bytes_to_read > buffer_len) {
        bytes_to_read = buffer_len;
    }
    if (copy_to_user(buf, buffer, bytes_to_read) != 0) {
        return -EFAULT;
    }
    buffer_len -= bytes_to_read;
    memmove(buffer, buffer + bytes_to_read, buffer_len);
    return bytes_to_read;
}

// Write function
static ssize_t device_write(struct file *file, const char *buf, size_t count, loff_t *pos) {
    int bytes_to_write = count;
    if (bytes_to_write > BUFFER_SIZE - buffer_len) {
        bytes_to_write = BUFFER_SIZE - buffer_len;
    }
    if (copy_from_user(buffer + buffer_len, buf, bytes_to_write) != 0) {
        return -EFAULT;
    }
    buffer_len += bytes_to_write;
    return bytes_to_write;
}

// File operations struct
static const struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = device_open,
    .release = device_release,
    .read = device_read,
    .write = device_write,
};

// Init function
static int __init mydevice_init(void) {
    major_number = register_chrdev(0, DEVICE_NAME, &fops);
    if (major_number < 0) {
        printk(KERN_ALERT "mydevice: failed to register a major number\n");
        return major_number;
    }
    printk(KERN_INFO "mydevice: registered successfully with major number %d\n", major_number);
    return 0;
}

// Exit function
static void __exit mydevice_exit(void) {
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "mydevice: unregistered successfully\n");
}

module_init(mydevice_init);
module_exit(mydevice_exit);
