#include <stdio.h>

int main()
{
    char buffer[50];
    int a = 10, b = 20, c;
    c = a + b;
    a = snprintf(buffer, 11, "Sum is %d\n", c);
 
    // The string "sum of 10 and 20 is 30" is stored
    // into buffer instead of printing on stdout
    printf("%s", buffer);
    printf("%d\n", a);
    return 0;
}