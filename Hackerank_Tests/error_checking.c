#include <stdio.h>
#include <string.h>
#include <errno.h> // contains the global variable 'errno' which is set whenever a system call returns a -1
#include <stdlib.h>


/*  fprintf useful for sending texts to specific streams
*   like stderror, stdout. Unlike printf which sends to stdout directly.
*/
#define CHECK(X) ({int val = (X); val == (-1) ? \
                    ({fprintf(stderr, "ERROR (" __FILE__ ":%d) --%s\n", \
                    __LINE__, strerror(errno)); \
                    exit(-1);}): val;})

int test(int tst)
{
    if(tst == 10){
        printf("Works");
        return 1;
    }
    else
        errno = 22; // Invalid argument. Looks like max value is 133
        return -1;
}

int main()
{
    int var = 12;

    CHECK(test(var));
    printf(": %d\n", var);
}