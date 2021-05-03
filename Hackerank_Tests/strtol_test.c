#include <stdio.h>
#include <stdlib.h>

/* long int strtol(const char *str, char **endptr, int base)
*  converts the initial part of the string in 'str' to a long int value
*  according to the given 'base', which must be between 2 and 36 inclusive,
*  or be the special value 0.
*/

int main () {
   char str[30] = "20 hello This is test 1234";
   char *ptr;
   long ret;

   ret = strtol(str, &ptr, 8); // really powerful function!
   int prin = printf("The number(unsigned long integer) %ld\n", ret);
   printf("String part is |%s|\n", ptr);
   printf("Result of printf is: %d\n", prin);

   return(0);
}