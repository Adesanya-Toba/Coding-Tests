#include <stdio.h>
#include <assert.h>

int main()
{
    int x = 8;
    x++;

    //assert(x == 7);
    //return 1;

    while (1){
        printf("still in the while loop!\n");
        if (x == 9){
            return 0; // return 1 exits the while loop
        }
    }
}