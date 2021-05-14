/*  Program to add two numbers without using the 
*   +, -, * or / operators.
*/

#include <stdio.h>

long binary_conv(int dec_num)
{
    int rem, temp = 1;
    long bin_num = 0;

    while(dec_num != 0){
        rem = dec_num % 2;
        dec_num = dec_num / 2;
        bin_num += rem * temp;
        temp*= 10;
    }
    return bin_num;
}

int Add(int x, int y)
{
    // iterate to find all the carry
    while (y != 0){
        // carry will contain the common bits of x and y
        int carry = x & y;

        // sum of bits of x and y where at least one of the bits is not set
        x = x ^ y;

        // Carry is shifted by one so that adding it to x gives the required sum
        y = carry << 1;
    }
    return x;
}

int main()
{
    // Add to the number without using +
    // try 2 + 2 first
    // long result = 2 << 1; // this equals 4

    int num1, num2, result;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    result = Add(num1, num2);

    printf("Result in binary: %ld\n", binary_conv(result));
    printf("Result in decimal: %d\n", result);
}
