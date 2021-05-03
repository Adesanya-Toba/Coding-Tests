#include <stdio.h>
#include <string.h>

long decimalToBinary(int decimalnum)
{
    long binarynum = 0;
    int rem, temp = 1;

    while (decimalnum != 0)
    {
        rem = decimalnum % 2;
        decimalnum = decimalnum / 2;
        binarynum = binarynum + rem * temp;
        temp = temp * 10;
    }
    return binarynum;
}
int main()
{
    int n = 20566;
    printf("Enter the number to convert: ");
    scanf("%d", &n);
    printf("Equivalent Binary Number is: %ld \n", decimalToBinary(n));

    // char b[100];
    // sprintf(b,"%d",n);
    // printf("\n The string for the num is: %c\n", n);
    //getchar();
    
    // printf("Enter the number to convert: ");
    // scanf("%d", &n);
    // for ( i = 0; n > 0; i++)
    // {
    //     result[i] = n % 2;
    //     n = n / 2;
    // }
    // printf("\nBinary of Given Number is= ");
    // for (i = i - 1; i >= 0; i--)
    // {
    //     printf("%d", result[i]);
    // }
    // printf("\n");
}