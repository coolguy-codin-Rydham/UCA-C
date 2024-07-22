#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include<limits.h>


int main()
{

    printf("%d\n", INT_MAX);
    // Measuring Program Runtime
    struct timeval before;
    gettimeofday(&before, NULL);
    long long before_millis = before.tv_sec*1000LL + before.tv_usec/1000;
    // printf("Hello");

    struct timeval after;
    gettimeofday(&after, NULL);
    long long after_millis = after.tv_sec*1000LL + after.tv_usec/1000;

    // printf("Printf ran in : %llu millis seconds", after_millis-before_millis);


    //Random Numbers
    // srand(time(NULL)); //seed, call only one time for the life of program
    // for(int i=0;i<3;i++){
    //     int value = rand() % (100+1);
    //     printf("%d\n", value);
    // }
    return 0;
}