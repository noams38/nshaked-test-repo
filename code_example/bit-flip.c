#include <stdio.h>




//revrse bit function 

unsigned int reverse_bit(unsigned int number)
{
// calculate the numner of bits in an integer 
    unsigned int tempNum = 0;
    unsigned int num_of_bits = 0; 
    unsigned int reversed_num = 0;
    tempNum = number;

    while(tempNum != 0) {
        num_of_bits++;
        tempNum >>= 1;
 
    }

    printf("Number of bits required to represent %d: %d\n", number, num_of_bits);


    //flip the order of the bits based on teh number of bit 
    // last go first 

    for(int i = 0;i < num_of_bits;i++){
        
        if( number & (1 << (num_of_bits -1 -i)))
            reversed_num |= (1 << i);

    }


   return reversed_num;

}


/*
unsigned int reverse_bits(unsigned int num) {
    int num_bits = 0;
    int tmp_num;
    
    tmp_num = num;
    // Count the number of bits required
    while (tmp_num != 0) {
        num_bits++;
        tmp_num >>= 1;
    }
    
    printf("Number of bits required to represent %d: %d\n", num, num_bits);

    unsigned int NO_OF_BITS =  num_bits;                    //sizeof(num) * 8;
    unsigned int reverse_num = 0;
    int i;
    for (i = 0; i < NO_OF_BITS; i++) {
        if ((num & (1 << i)))
            reverse_num |= 1 << ((NO_OF_BITS - 1) - i);
    }
    return reverse_num;
}

*/



int main() {
    unsigned int num = 0b100;
    unsigned int reversed_num = reverse_bit(num);
    printf("Original number: %u (0x%X)\n", num, num);
    printf("Reversed number: %u (0x%X)\n", reversed_num, reversed_num);
    return 0;
}




//count number of bit in a number n 


int temp = n;
int counter = 0 ;

while (temp != 0)
{
    counter++;
    temp =>> 1;
    
} 



// flip the bits 
    for(int i = 0;i < num_of_bits;i++){
        if( number & (1 << (num_of_bits -1 -i)))
            reversed_num |= (1 << i);
        
}


for(int i =0 ;i < num_of_bits;i++)
{
    if( number & 1 << (num_of_bits-i -i)  )
        reverse_bit |= (1 << i); 


}