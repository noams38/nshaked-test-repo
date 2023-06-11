#include <stdio.h>


unsigned char reorder_bits(unsigned char n) {
    unsigned char result = 0;
    int num_bits = sizeof(n) * 8; // Number of bits in the integer

    printf("number of bits : %u\n", num_bits);

    for (int i = 0; i < num_bits; i++) {
        unsigned int bit = (n >> (num_bits -1 - i)) & 1; // Extract the i-th bit from n
        printf("bits : %u\n", bit);
        result |= bit << (i); // Shift the bit to its new position in the result
    }

    return result;
}


int main() {
    unsigned char num = 4;
    printf("Original number: %u\n", num);
    unsigned char reversed_num = reorder_bits(num);
    printf("Reversed number: %u\n", reversed_num);
    return 0;
}