#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(){
    const char *filePath = "try.txt";

    int fd;

    fd = open(filePath, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    if(fd == -1){
        perror("Error Creating File");
        return 1;
    }

    const char *content = "Hello, World!\n";

    if(write(fd, content, 14)==-1){
        perror("Error Writing to file");
        close(fd);
        return 1;
    }

    if(close(fd)==-1){
        perror("Error Closing File");
        return 1;
    }
    printf("File Created and written to successfully\n");
    return 0;
}