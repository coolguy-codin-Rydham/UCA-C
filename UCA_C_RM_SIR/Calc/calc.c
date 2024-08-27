
#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}
int sub(int a, int b)
{
    return a - b;
}
int mul(int a, int b)
{
    return a * b;
}
int divi(int a, int b)
{
    if (b == 0)
    {
        printf("Error: Division by zero is not allowed\n");
        return 0;
    }
    return a / b;
}
int max(int a, int b){
    return a>=b?a:b;
}
int min(int a, int b){
    return a<=b?a:b;
}
int mod(int a, int mod){
    return a%mod;
}
int abs(int a, int b, int*(comp)(int , int)){
    int ans = comp(a, b);

    return ans<=0?-1*ans:ans;
}