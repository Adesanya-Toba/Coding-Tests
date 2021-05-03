#include <stdio.h>
#define MAXBUFLEN 1000


void buffPrint(char* array)
{
    for (int i = 0; array[i] != '\0'; i++)
    {
        printf("%c", array[i]);
    }
}


int main()
{
    char source[MAXBUFLEN + 1];
    FILE *fp = fopen("my_config.cfg", "r");
    if (fp != NULL)
    {
        size_t newLen = fread(source, sizeof(char), MAXBUFLEN, fp);
        if (ferror(fp) != 0)
        {
            fputs("Error reading file", stderr);
        }
        else
        {
            source[newLen++] = '\0'; /* Just to be safe. */
            buffPrint(source);
        }

        fclose(fp);
    }
}

