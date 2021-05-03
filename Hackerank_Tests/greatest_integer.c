#include <stdio.h>
#include <stdlib.h>

/*
Add `int max_of_four(int a, int b, int c, int d)` here.
*/

int max_of_four( int a, int b, int c, int d);

int greatest(int* A, int size)
{
    int greatest = A[0]; //A[0] == *(A + 0)
    for (int i = 0; i < size; i++)
    {
        if (greatest < *(A + i))
        {
            greatest = A[i];
        }
    }
    return greatest;
}


int main() {
    int A[] = {2, 7, 1, 9, 13, 2, 1};
    int i = 0, size = 5;
    int* B = (int*)calloc(size, sizeof(int));


    printf("Please input some numbers; press enter after each number:\n"); 
    while(1)
    {
        scanf("%d", &B[i]);
        if ((char)B[i] == '\z') break; //I need to get the right escape condition
        i++;
    }

    int greatest_no = greatest(B, size);
    printf("The greatest number is: %d\n", greatest_no);

    printf("[");
    for (int i = 0; i < size; i++)
    {   
        printf("%d ", B[i]);
    }
    printf("]");

    free(B);

    /*int a, b, c, d;
    
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("The greatest number is %d.\n", ans);
    printf("\n");
    
    int max = greatest(A, sizeof(A)/sizeof(int));
    printf("The greatest number in the array is %d\n", max);*/

}

int max_of_four( int a, int b, int c, int d)
{
    int greatest;
    
    if (a>b && a>c && a>d)
    {
        greatest = a;
    }

    else if (b>a && b>c && b>d)
    {
        greatest = b;
    }

    else if (c>a && c>b && c>d)
    {
        greatest = c;
    }

    else if (d>a && d>b && d>c)
    {
        greatest = d;
    }

    else if (a==b && b==c && c==d)
    {
        greatest = a;
    }
   
    return greatest;
}