#include "../include/string.h"

#include <stdio.h>
#include <string.h>

int main()
{
    char greet[] = "Hello";
    char *greet2 = (char *)my_memchr(greet, 'e', 5);

    if (greet2 != NULL)
    {
        printf("%s", greet2);
    }
    return 0;
}