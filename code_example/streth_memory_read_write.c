#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BLOCK_SIZE (1 << 8) // 1 GB block size




int main()
{
 
  time_t t;
   
   
/* Intializes random number generator */
srand((unsigned) time(&t));
// allocate memory block

char* block = malloc(BLOCK_SIZE);

if (block == NULL) {
        printf("Error: failed to allocate memory block\n");
        return 1;
    }

// fill block with random data

for(int i = 0 ; i < BLOCK_SIZE;i++)
    block[i] = (char) rand() % 0xff;


    // repeatedly perform operations on the data
    for (int k = 0 ; ;k++ ){
        printf("itereation = %d", k);
        // read from random locations in the block
        for (int j = 0 ;j < 10000;j++){
            int index = rand() % BLOCK_SIZE;
            char value = (char) block[index];
            printf("address %p val %c \n",(void*)&block[index],value);
        }


        // write to random locations in the block
        for ( int j = 0 ;j < 10000;j++){
            int index = rand() % BLOCK_SIZE;
            block[index] = (char) rand() % 0xff;
            char value = block[index];
            printf("address %p val %c  index %d\n",(void*)&block[index],value,index);
        }




    }
}

/*
int main() {
    void* block = malloc(BLOCK_SIZE); // allocate memory block
    if (block == NULL) {
        printf("Error: failed to allocate memory block\n");
        return 1;
    }

    // fill block with random data
    srand(time(NULL));
    for (int i = 0; i < BLOCK_SIZE; i++) {
        ((char*)block)[i] = rand() & 0xff;
    }

    // repeatedly perform operations on the data
    for (int i = 0; ; i++) {
        printf("Iteration %d\n", i);

        // read from random locations in the block
        for (int j = 0; j < 100000; j++) {
            int index = rand() % BLOCK_SIZE;
            volatile char value = ((char*)block)[index];
        }

        // write to random locations in the block
        for (int j = 0; j < 100000; j++) {
            int index = rand() % BLOCK_SIZE;
            ((char*)block)[index] = rand() & 0xff;
        }
    }

    return 0;
}

*/
