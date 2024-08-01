#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main(){
    int fd;
    ssize_t bytesRead;
    char buffer[BUFFER_SIZE];

    fd = open("try.txt", O_RDONLY);
    if(fd==-1){
        perror("FIle opening failed");
        exit(EXIT_FAILURE);
    }

    while((bytesRead = read(fd, buffer, BUFFER_SIZE))>0){
        if(write(STDOUT_FILENO, buffer, bytesRead)!=bytesRead){
            perror("Failed to write to stdOut");
            close(fd);
            exit(EXIT_FAILURE);
        }
    }

    if(bytesRead==-1){
        perror("Failed to read file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    if(close(fd)==-1){
        perror("Failed to close file");
        exit(EXIT_FAILURE);
    }

    return 0;
}