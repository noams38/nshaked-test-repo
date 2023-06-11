#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE (1<<10) // 1GB 
#define INTERVAL 20 
//memory stress Test DRAM 
//allocate of pointer char pointres  




void main (int argc , char ** argv)
{
    char **p;

    // allocate pointer of arrayy at a zize of 4096 

    p = malloc (sizeof(char*)*4096 );

    for (int i = 0 ;i<4096; i++)
        p[i] = malloc(SIZE);
    
    //set all memmory to zero 

 for (j = 0; j < SIZE; j += 2) {
            p[i][j] = 0;
    

    sleep(3);

}