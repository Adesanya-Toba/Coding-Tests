#include <stdio.h>

long binary_conv(int dec_num)
{
    int rem, temp = 1;
    long bin_num = 0;

    while(dec_num != 0){
        rem = dec_num % 2;
        dec_num = dec_num / 2;
        bin_num += rem * temp;
        temp *= 10;
    }
    return bin_num;
}

int main()
{
    // int dec_num;
    // long bin_num = 0l;
    // printf("Enter the number to convert: ");
    // scanf("%d", &dec_num);
    // bin_num = binary_conv(dec_num);
    // printf("The binary of %d is %ld\n", dec_num, bin_num);

    // Add to the number without using +
    // try 2 + 2 first
    // long result = 2 << 1; // this equals 4

    int num1, num2;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    long result;
    if ((num1 || num2) > 15){
        num1 = num1 >> 4;
    }
    result = num1 | num2;
    printf("Result in binary: %ld\n", binary_conv(result));
    printf("Result in decimal: %d\n", result);
}