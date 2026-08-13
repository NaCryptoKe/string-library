#include "../include/string.h"

#include <stdio.h>
#include <string.h>

int main()
{
    char greet[] = "Hello";
    char greet2[50];

    char a[] = "AAA";
    char b = 'A';
    printf("%c", *strchr(a, (int)b));
}
