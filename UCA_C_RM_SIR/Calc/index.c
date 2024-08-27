#include <stdio.h>
#include "file1.h"
#include "file2.h"

int main(){
    printf("%d\n", add(3, 4));
    printf("%d\n", sub(3, 4));
    printf("%d\n", mul(3, 4));
    printf("%d\n", divi(5, 4));
    printf("%d\n", max(3, 4));
    printf("%d\n", min(3, 4));
    printf("%d\n", mod(13, 5));
    printf("%d\n", abs(3,4, sub));

    return 0;
}
