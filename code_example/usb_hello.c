#include <linux/module.h>
#include <linux/usb.h>

static struct usb_device_id hello_usb_table[] = {
    { USB_DEVICE(0x0e0f, 0x0003) },
    { USB_DEVICE_INFO(Device ,Subclass, Protocol) } /* Terminating entry */
};
MODULE_DEVICE_TABLE(usb, hello_usb_table);

static int hello_usb_probe(struct usb_interface *interface, const struct usb_device_id *id)
{
    printk(KERN_INFO "Hello, USB device!\n");
    return 0;
}

static void hello_usb_disconnect(struct usb_interface *interface)
{
    printk(KERN_INFO "Goodbye, USB device!\n");
}

static struct usb_driver hello_usb_driver = {
    .name = "hello_usb",
    .id_table = hello_usb_table,
    .probe = hello_usb_probe,
    .disconnect = hello_usb_disconnect,
};

static int __init hello_usb_init(void)
{
    int result = usb_register(&hello_usb_driver);
    if (result < 0) {
        printk(KERN_ALERT "Failed to register hello_usb driver: %d\n", result);
        return result;
    }
    printk(KERN_INFO "hello_usb driver registered\n");
    return 0;
}

static void __exit hello_usb_exit(void)
{
    usb_deregister(&hello_usb_driver);
    printk(KERN_INFO "hello_usb driver unregistered\n");
}

module_init(hello_usb_init);
module_exit(hello_usb_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Hello, world! USB device driver for Linux");
