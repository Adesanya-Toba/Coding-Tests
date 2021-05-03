#include <stdio.h>
#include <string.h>

int main()
{
    char payload[30];
    int var = 1;

    char *pre_payload = "Hello World %d!\n";
    for (int i = 1; i < 10; i++){

        sprintf(payload, pre_payload, i);
        printf("%s", payload);
    }

    /* strcat (char* s1, const char* s2) */
    // appends s2 to the end of s1.
    //strcat(data, payload);

    return 0;
}