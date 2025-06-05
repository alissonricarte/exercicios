#include <stdio.h>

int fib(int);
int main(){
    int n = 5;
    printf("%d\n", fib(n));
    return 0;
}
int fib(int n){
    if(n < 2){
        return 1;
    }
    else{
        return fib(n - 1) + fib(n - 2);
    }
}
