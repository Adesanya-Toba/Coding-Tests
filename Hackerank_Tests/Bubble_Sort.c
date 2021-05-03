#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ASCENDING 1
#define DESCENDING 0

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int *A, int size, int order) // order: 1 for ascending, 0 for descending
{
    int times_run = 1;

    for (int i = 1; i < size; i++)
    {
        int flag = 0;

        for (int j = 0; j < size - 1; j++)
        {
            if (order == 1)
            {
                if (A[j] > A[j + 1])
                {
                    swap(&A[j], &(A[j + 1]));
                    flag = 1;
                    printf("%d\n", times_run);
                    times_run++;
                }
            }
            else
            {
                if (A[j] < A[j + 1])
                {
                    swap(&A[j], &(A[j + 1]));
                    flag = 1;
                }
            }
        }
        if (flag == 0) break;
    }
}

int main()
{
    int A[] = {5, 13, 3, 8, 10, 9, 11, 78, -1, 0};

    int B[2] = {0, 5};
    printf("Original array: ");
    for (int i = 0; i < sizeof(A) / sizeof(int); i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    //swap(B, (B+1));

    BubbleSort(A, sizeof(A) / sizeof(int), ASCENDING);

    printf("Sorted array: ");
    for (int i = 0; i < sizeof(A) / sizeof(int); i++)
    {
        printf("%d ", A[i]);
    }
}