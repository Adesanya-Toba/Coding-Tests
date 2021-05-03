#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i, temp;
    printf("Enter the array length: ");
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        printf("Enter the values of the array: ");
        scanf("%d", arr + i);
    }


    // Array reversal logic
    /*int* rev_arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++){
        rev_arr[i] = arr[num - 1 - i]; // fill the array forward (in ascending order)
        printf("%d ", *(rev_arr + i));
    }*/

    // OR
    for (i = 0; i < num / 2; i++){
        temp = arr[i];
        arr[i] = arr[num - 1 - i];
        arr[num - 1 - i] = temp;
    }

    printf("Reversed Array: ");
    for (i = 0; i < num; i++) printf("%d ", *(arr + i));

    //free(rev_arr);
    free(arr);
    return 0;
}