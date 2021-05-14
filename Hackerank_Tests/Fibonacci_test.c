#include <stdio.h>

#define MAX_NUMBER 47
 
// Cache array
unsigned long f[MAX_NUMBER+1] = { 0 };
 
/*
 * Calculates and returns the n-th Fibonacci Number
 */
unsigned long fibonacci(unsigned long n) {
    if (0 == n) return 0;
    if (1 == n) return 1;
    if (0 == f[n]) {
        f[n] = fibonacci(n-2) + fibonacci(n-1);
    }
    return f[n];
}
int main()
{
    unsigned long var = 8ul, fib;
    fib = fibonacci(var);
    printf("Fibonacci of %lu is: %lu\n", var, fib);
    
    printf("Fibonacci sequence of %d is: ", var);
    for (int i = 0; i < MAX_NUMBER; ++i){
        printf("%ld ", f[i]);
    }
    printf("\n");
}