#include<stdio.h>
typedef struct  
{  
    int a;   
    char b;   
    char c;  
}sample;

int main(void) {
    sample ptr;

    //calc size 

    int size = (char*)(&ptr+1) - (char*)(&ptr); 



    printf("Size of structure sample using sizeof: %lu\n", sizeof(sample));
    //ptr++;
	printf("Size of structure is: %d\n", (int)size);
	return 0;
}



