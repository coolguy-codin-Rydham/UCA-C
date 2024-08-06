#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>




void createFile(){
    int fd = open("tempfile.txt", O_RDONLY);


    write(fd, "hello World", 11);

    ssize_t bytesRead;
    char buffer[11];
    while((bytesRead = read(fd, buffer, sizeof(buffer)))>0){}   

    write(STDOUT_FILENO, buffer, bytesRead);
}

void print(char arr[]){
    write(1, "hello world\n", 11);
}


int main(){
    // createFile("hello");

    int sz;
    char *buffer = (char*)malloc(100*sizeof(char));


    int fd = open("temp.txt", O_WRONLY | O_CREAT, O_TRUNC, 0644);

    if(fd < 0){
        perror("r1");
        exit(1);
    }

    sz = write(fd, "Hello World\n", strlen("Hello World\n"));

    fd = open("temp.txt", O_RDONLY);

    sz  = read(fd, buffer, strlen("Hello World\n"));

    buffer[sz] = '\0';

    close(fd);

    write(1, buffer, sz);

    free(buffer);
    return 0;
}