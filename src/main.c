#include "../include/string.h"

#include <stdio.h>
#include <string.h>

int main()
{
    char greet[] = "Hello";
    char greet2[50];

    int a = 20;
    int b = 10;


    printf("%d", my_memcmp(&b, &a, 2));

}
