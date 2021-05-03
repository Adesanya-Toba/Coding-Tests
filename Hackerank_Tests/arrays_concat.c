#include <stdio.h>
#include <string.h>

int main()
{
    char* text = "hello";
    char sndBuf[20];
    char* text2 = "Toba";

    //memcpy(sndBuf, text, 6);
    // memset(text, '\0', strlen(text));
    strcat(sndBuf, text);
    printf("received: %s\n", text);
    // strcat(sndBuf, text2);
    // printf("received: %s\n", sndBuf);
    // sndBuf[0] = '\0';
    // printf("SendBuf: %c\n", sndBuf[2]);

}