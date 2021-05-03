/* Factorial using Recursion */

#include <stdio.h>
#include <stdlib.h>

int fact(int n)
{
    // int factorial;
    if (n == 0) return 1; // Exit condition
    return n * fact(n -1);

    //return factorial; 
}

int main()
{
    int ans = fact(4);
    printf("%d\n", ans);
}