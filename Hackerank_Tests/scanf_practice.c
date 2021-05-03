#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char ch;
    char s[30];
    char sentence[40];

    scanf("%c\n", &ch);
    scanf("%s\n", s);
    scanf("%[^\n]%*c", sentence);

    printf("%c\n",ch);
    printf("%s\n", s);
    printf("%s\n",sentence);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}