// Define the register address and value to change


volatile uint32_t* reg_address = (volatile uint32_t*)0x12345678
//volatile uint32_t  * register_address = (volatile uint32_t  *)0x12345678

uint32_t value_to_change = 0x5; // 00000101


// the value you wish to change 101 0x5 
//uint32_t value_to_change = 0x5; // Binary: 101
//uint32_t value_to_write = 0x5;

// Define the bit location to change (starting from the least significant bit)
uint32_t bit_location = 10;




// Define a bit mask with 3 bits set to 1 at the specified location
uint32_t bit_mask = (0x7 << bit_location);  //111000000000

//uint32_t bit_mask = (0x7 << bit_location); // Binary: 111000000000


// Clear the 3 bits at the specified location in the register value

uint32_t new_reg_value = *reg_address & (~bit_mask);
new_reg_value |= value_to_change << bit_location;

*reg_address = new_reg_value;




uint32_t new_register_value = (*register_address) &(~bit_mask);


//uint32_t reg_value = (*reg_addr) & (~bit_mask);

// Set the 3 bits with the desired value

new_register_value | = ((value_to_change << bit_location) & bit_mask)
 
//reg_value |= ((value_to_change << bit_location) & bit_mask);

// Write the updated register value back to the register

*register_address = new_register_value;

//*reg_addr = reg_value;
