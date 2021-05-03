#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//%d (integer), %c (character), %s (string), %f (float) respectively.
int main()
{
	int a, b;
    float c, d;

    
    //d = 6.893;
    //printf ("%.2f\n", d); //setting to 2 decimal places (%0.2f)

    scanf("%d %d\n", &a, &b);
    scanf("%f %f\n", &c, &d);

    printf("%d %d\n", (a + b), (a - b));
    printf("%.1f %.1f\n", (c + d), (c - d)); //1 decimal place
    
    return 0;
}