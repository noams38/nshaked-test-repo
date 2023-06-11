#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/io.h>

#define PCI_CONFIG_ADDR 0xCF8
#define PCI_CONFIG_DATA 0xCFC

#define PCI_VENDOR_ID 0x00
#define PCI_DEVICE_ID 0x02
#define PCI_COMMAND 0x04
#define PCI_STATUS 0x06
#define PCI_CLASS 0x08
#define PCI_SUBCLASS 0x09
#define PCI_HEADER_TYPE 0x0E

#define PCI_CONFIG_ENABLE (1UL << 31)

#define PCI_BUS(bus) ((bus) << 16)
#define PCI_SLOT(slot) ((slot) << 11)
#define PCI_FUNC(func) ((func) << 8)

uint32_t pci_config_read32(uint8_t bus, uint8_t slot, uint8_t func, uint8_t offset) {
    uint32_t addr = PCI_CONFIG_ENABLE | PCI_BUS(bus) | PCI_SLOT(slot) | PCI_FUNC(func) | (offset & 0xFC);
    
    printf("address = %x",addr);
    
    outl(addr, PCI_CONFIG_ADDR);
    return inl(PCI_CONFIG_DATA);
}

int main() {
    // Read vendor ID and device ID from PCI device at bus 0, device 2, function 0
    uint16_t vendor_id = pci_config_read32(0, 2, 0, PCI_VENDOR_ID) & 0xFFFF;
    uint16_t device_id = pci_config_read32(0, 2, 0, PCI_DEVICE_ID) >> 16;
    
    printf("Vendor ID: 0x%04X\n", vendor_id);
    printf("Device ID: 0x%04X\n", device_id);

    return 0;
}
