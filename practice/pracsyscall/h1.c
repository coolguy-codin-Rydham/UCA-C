#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <error.h>
#include <sys/types.h>

// int main()
// {
//     int fd;
//     fd = open("foo.txt", O_WRONLY | O_CREAT, 0644);
//     write(fd, "hello World", 11);
//     close(fd);

//     return 0;
// }

// int main(){
//     int fd ;
//     fd = open("foo.txt", O_WRONLY|O_CREAT,  644);
//     if(fd<0){
//         perror("foo");
//         exit(1);
//     }
//     printf("Opened");

//     return 0;
// }

// int main(){
//     pid_t p = fork();
//     if(p<0){
//         perror("fork fail");
//         exit(1);
//     }
//     printf("Hello world!, process_id(pid) = %d \n", getpid());
//     return 0;
// }

// int main(){
//     fork();
//     printf("Hello\n");
//     fork();
//     fork();
//     printf("World\n");
//     return 0;
// }

// int main()
// {
//     pid_t p = fork();
//     if (p < 0)
//     {
//         perror("fork fail");
//         exit(1);
//     }
//     else if(p==0)
//     {
//         printf("Hello from Child\n");
//     }    
//     else{
//         printf("Hello from Parent\n");
//     }

//     return 0;
// }

int main(){
    int x = 1;
    pid_t p = fork();

    if(p==0){
        printf("Child x=%d\n", ++x);
    }
    else if(p>0){
        printf("Parent x=%d\n", --x);
    }

    return 0;
}