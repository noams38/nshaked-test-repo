#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("file.txt", O_RDONLY); // open the file for reading
    if (fd == -1) {
        perror("open");
        return 1;
    }

    struct stat st;
    if (fstat(fd, &st) == -1) {
        perror("fstat");
        return 1;
    }

    // memory map the file
    char *file_contents = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (file_contents == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // access the file contents as a block of memory
    printf("File contents: %s", file_contents);

    // unmap the file when finished
    if (munmap(file_contents, st.st_size) == -1) {
        perror("munmap");
        return 1;
    }

    close(fd); // close the file descriptor
    return 0;
}
