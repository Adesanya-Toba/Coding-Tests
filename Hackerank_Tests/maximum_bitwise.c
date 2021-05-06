#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*  Calculates the maximum value for the bitwise operations 
*   &, | and ^, and prints them out as long as they are less than
*   k (threshold)
*
*   The operands for operations are derived from n
*   a b   and or xor
*   1 2   0   3  3
*   1 3   1   3  2
*   2 3   2   3  1
*
*   So the output would be
*   2   // maximum from the & operation (less than k)
*   0   // maximum from the | operation (less than k)
*   2   // maximum from the ^ operation (less than k)
*/
void calculate_the_maximum(int n, int k) {
    int andRes = 0, orRes = 0, xorRes = 0;
    int temp = 0;
    int oper = 0;

    for (int i = 1; i < n; i++)
    {
        oper = i + 1;
        while(oper < n + 1){
            temp = i & oper;
            if (temp > andRes && temp < k){ // stores max in andRes
                andRes = temp;
            }
            oper++;
        }
    }
    temp = 0;
    oper = 0;
    
    for (int i = 1; i < n; i++)
    {
        oper = i + 1;
        while(oper < n + 1){
            temp = i | oper;
            if (temp > orRes && temp < k){ // stores max in orRes
                orRes = temp;
            }
            oper++;
        }
    }
    temp = 0;
    oper = 0;
    
    for (int i = 1; i < n; i++)
    {
        oper = i + 1;
        while(oper < n + 1){
            temp = i ^ oper;
            if (temp > xorRes && temp < k){ // stores max in xorRes
                xorRes = temp;
            }
            oper++;
        }
    }
    
    printf("%d\n", andRes);
    printf("%d\n", orRes);
    printf("%d\n", xorRes);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}