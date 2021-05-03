// Binary converter 2 (using arrays). Didn't realize I had done one before now.

#include <stdio.h>
#define ARRAY_SIZE 4 // this should be variable, depending on the decimal number


void arrayPrint(char* array, int size)
{
    printf("Binary number (as an array) is: ");
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%d", array[i]);
    }
    printf("\n");
}

/*  Uses an array of integers to store the binary number
    Array size is a POF (point of failure), function seg faults
    if dec_num convert doesn't fit in the array
*/
void binary_conv(int dec_num)
{
    int i;
    char bin_num[ARRAY_SIZE] = {0};

    for (i = ARRAY_SIZE - 1; dec_num > 0; i--)
    {
        bin_num[i] = (dec_num % 2);
        dec_num = dec_num / 2;
    }
    arrayPrint(bin_num, ARRAY_SIZE);
}

/*  Uses a single integer to store binary number
*/
long binary_conv2(int dec_num)
{
    int temp = 1, rem;
    long bin_num = 0;

    while (dec_num != 0)
    {
        rem = dec_num % 2;
        dec_num = dec_num / 2;
        bin_num += rem * temp;
        temp *= 10; 
    }
    return bin_num;
}


int main()
{
    int dec_num;
    printf("Enter the decimal number to convert: ");
    scanf("%d", &dec_num);
    binary_conv(dec_num);
    printf("Binary of %d is %ld\n", dec_num, binary_conv2(dec_num));

    //TO:DO Check how to return array from a function
}