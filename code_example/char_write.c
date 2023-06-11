#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main() {
    FILE *fp;
    char *filename = "example.txt";
    char buffer[BUFFER_SIZE];
    size_t nread;

    // Open file for writing
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file for writing\n");
        exit(1);
    }

    // Write buffer to file

    for (int i = 0; i < BUFFER_SIZE; i++) {
        buffer[i] = i % 256; // fill buffer with test data
    }

    for (int i = 0; i < BUFFER_SIZE; i++) 
        fprintf(fp,"%c" , buffer[i]);

    // Close file
    fclose(fp);

    // Open file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file for reading\n");
        exit(1);
    }

    // Read file into buffer
    nread = fread(buffer, 1, BUFFER_SIZE, fp);

    for (int j = 0; j < BUFFER_SIZE; j++) {
        if (buffer[j] != j % 256) {
            printf("Data mismatch\n");
            return -1;
        }
        
    }


    // Close file
    fclose(fp);

    // Print buffer contents
    printf("Read %ld bytes from file:\n", nread);
    printf("%s\n", buffer);

    return 0;
}
