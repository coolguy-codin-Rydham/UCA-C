#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define max_size 1024

char buffer[max_size];
char *oldFilename;
char *newFilename;

int open_file()
{
    int fd = open(oldFilename, O_RDONLY);

    ssize_t bytesRead;
    if (fd == -1)
    {
        printf("Error Opening FIle");
        return -1;
    }

    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0)
    {
        if (write(STDOUT_FILENO, buffer, bytesRead) != bytesRead)
        {
            printf("Error Storing File");
            close(fd);
            return -2;
        }
    }

    if (bytesRead == -1)
    {
        printf("Error Reading File");
        return -3;
    }
    if (close(fd) == -1)
    {
        printf("Error Closing File");
        return -4;
    }

    return fd;
}

int write_file(int sizeActual)
{
    int fd = open(newFilename, O_WRONLY | O_CREAT, 777);
    ssize_t bytes_written;
    if (fd == -1)
    {
        printf("Error Opening FIle");
        return -1;
    }
    bytes_written = write(fd, buffer, sizeActual);
    if (bytes_written == -1)
    {
        printf("Error Writing File");
        return -2;
    }

    if (close(fd) == -1)
    {
        printf("Error Closing File");
        return -3;
    }

    return fd;
}

int main(int argc, char *argv[])
{
    printf("%d", argc);

    oldFilename = argv[1];
    newFilename = argv[2];

    int a = open_file();

    int sizeActual = 0;

    for (int i = 0; i < max_size; i++)
    {
        if (buffer[i] == '\0')
        {
            break;
        }
        sizeActual++;
    }

    printf("\n%d\n", sizeActual);

    int b = write_file(sizeActual);

    return 0;
}