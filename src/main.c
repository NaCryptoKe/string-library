#include "../include/string.h"

#include <stdio.h>

int main()
{
    char greet[] = "Hello";

    printf("Size of greet is %zu, it should be 5", strlen(greet));
}