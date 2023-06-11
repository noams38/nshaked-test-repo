#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/usbdevice_fs.h>

#define USBDEV "/dev/bus/usb/001/001"
#define USB_EP_IN 0x81
#define USB_EP_OUT 0x01

int main(int argc, char **argv)
{
    int fd;
    struct usbdevfs_urb *urb;
    char buffer[64];
    int nbytes;

    // Open the USB device
    fd = open(USBDEV, O_RDWR);
    if (fd < 0) {
        perror("Unable to open USB device");
        exit(1);
    }

    // Allocate memory for the URB
    urb = malloc(sizeof(struct usbdevfs_urb));
    if (!urb) {
        perror("Unable to allocate memory for URB");
        exit(1);
    }

    // Fill in the URB fields
    memset(urb, 0, sizeof(struct usbdevfs_urb));
    urb->type = USBDEVFS_URB_TYPE_INTERRUPT;
    urb->endpoint = USB_EP_IN;
    urb->buffer = buffer;
    urb->buffer_length = sizeof(buffer);
    urb->status = -1;

    // Submit the URB to the USB device
    if (ioctl(fd, USBDEVFS_SUBMITURB, urb) < 0) {
        perror("Unable to submit URB to USB device");
        exit(1);
    }

    // Wait for the URB to complete
    while (urb->status == -1) {
        if (ioctl(fd, USBDEVFS_REAPURBNDELAY, &urb) < 0) {
            perror("Unable to reap URB from USB device");
            exit(1);
        }
    }

    // Check the number of bytes received
    if (urb->status == 0) {
        nbytes = urb->actual_length;
        printf("Received %d bytes from USB device\n", nbytes);
    } else {
        perror("Error receiving data from USB device");
        exit(1);
    }

    // Free the memory allocated for the URB
    free(urb);

    // Close the USB device
    close(fd);

    return 0;
}
