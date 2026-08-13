#include "../include/string.h"

#include <stdio.h>
#include <string.h>

int main()
{
    char greet[] = "Hello";
    char greet2[50];

    int a = 20;
    int b = 10;

    printf("Value of b before memcpy: %d\n", b);

    my_memcpy(&b, &a, sizeof(int));

    printf("Value of b after memcpy: %d\n", b);
}
