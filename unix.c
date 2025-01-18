#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
 
#define BUFSIZE 256
    
// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }
    struct stat file_stat;
    if (stat(argv[1], &file_stat) != 0) {
        perror("stat");
        return -1;
    }
    printf("File size: %lld bytes\n", (long long) file_stat.st_size);
}
