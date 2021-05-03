#include <stdio.h>
#include <stdlib.h>
#include <libconfig.h>

void arrayPrint(char* array);

int main()
{
    FILE *fpoint;
    fpoint = fopen("test.txt", "a+");

    char buff[200];

    fseek(fpoint, 20, SEEK_SET);
    fgets(buff, 200, fpoint);

    // while (!feof(fpoint))
    // {    
    //     fgets(buff, 100, fpoint);
    //     puts(buff);
    // }
    //fprintf(fpoint, "%s", "\nToba");

    arrayPrint(buff);
    fclose(fpoint);
}

void arrayPrint(char* array)
{
    for (int i = 0; array[i] != '\0'; i++)
    {
        printf("%c", array[i]);
    }
}