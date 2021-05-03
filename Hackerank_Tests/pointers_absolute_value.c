#include <stdio.h>
#include <stdlib.h>

void update(int *a,int *b) {
    // Complete this function
    int tempa, tempb;  
    tempa = *a + *b;
    tempb = (*a) - (*b);
    *a = tempa;
    *b = abs(tempb);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    printf("This code outputs the sum and absolute difference of 2 integers.\n");
    printf("\n");
    printf("Please type in 2 integers, press enter after each one:\n");
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("\n");
    printf("Their sum is: %d\n", a);
    printf("Their absolute difference is:%d\n", b);

    return 0;
}