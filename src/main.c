#include "../include/string.h"

#include <stdio.h>
#include <string.h>

int main()
{
    int size;

    char str1[] = "Nahom";
    char str2[] = "eth";

    size = my_strcspn(str1, str2);
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    printf("The number of characters in str1 before"
         "\nfirst matched character from str2: %d\n", size);
    
    return 0;
}