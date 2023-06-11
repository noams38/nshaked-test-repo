/*

To avoid buffer overflow vulnerabilities, it is important to ensure that all buffers are large enough 
to hold the data being written to them. Additionally, functions like strncpy can be used instead of strcpy 
to limit the amount of data that is written to a buffer. Finally, input validation and 
sanitization can also help prevent buffer overflow vulnerabilities.
*/


#include <string.h>
#include <stdio.h>

void vulnerable_function(char *input) {
    char buffer[5];
    strcpy(buffer, input);
    printf("Buffer contents: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input>\n", argv[0]);
        return 1;
    }
    vulnerable_function(argv[1]);
    return 0;
}
