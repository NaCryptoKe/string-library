#include "../include/string.h"

#include <stdio.h>
#include <string.h>

int main()
{
    char greet[] = "Hello";
    char greet2[3];

    my_memmove(greet2, greet, 3);
    
    for (int i = 0; i < 3; i++)
    {
        printf("%c", greet2[i]);
    }

    return 0;
}