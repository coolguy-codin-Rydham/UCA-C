#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>



int main(){
    
    char buffer[100];

    int fd = open("try.txt", O_RDONLY );

    ssize_t bytes_read = read(fd, buffer, sizeof(buffer));
    // printf("%d\n", fd);

    printf("%s\n", buffer);

    return 0;
}