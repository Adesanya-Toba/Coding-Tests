#include <stdio.h>
#include <string.h>

int main()
{
    char* str1 = "1.00";
    char* str2 = "0.9";
    int ret;

    ret = memcmp(str1, str2, strlen(str1));
    if (ret > 0) 
        printf("str1 is greater than str2\n");
    else if (ret < 0)
        printf("str1 is less than str2\n");
    else if (ret == 0)
        printf("str1 is equal to str2\n");

}