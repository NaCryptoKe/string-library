#include "../include/string.h"

#include <stdio.h>
#include <string.h>

int main()
{
    char greet[] = "Hello";
    char greet2[50];

    my_strcpy(greet2, greet);
    printf("%s", greet2);
}