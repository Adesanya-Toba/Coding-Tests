#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 69;

    /*
    *   is x = 3, if true, x++
    *   if not, x--
    */
    x == 3 ? x++ : x--;

    /* doesn't work */
    // x = isTrue() ? 4 : 7;

    printf("New value of x is: %d\n", x);
}