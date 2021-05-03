#include <stdio.h>
#include <stdlib.h>

int main()
{
    int digit[10];
    int test;
    int sum = 0;
    printf("Type in a number: ");
    scanf("%d", &test);

    /*digit[0] = test % 10;
    test = test / 10;
    digit[1] = test % 10;
    test = test / 10;
    digit[2] = test;*/

    for (int i = 0; i< 9; i++)
    {
        digit[i] = test % 10;
        test = test / 10;
        sum += digit[i]; 
    }

    printf("%d\n", digit[0]);
    printf("%d\n", digit[1]);
    printf("%d\n", digit[2]);
    printf("%d\n", digit[3]);
    printf("%d\n", digit[4]);
    printf("\n");

    printf("The sum of these numbers are: %d\n", sum);
}