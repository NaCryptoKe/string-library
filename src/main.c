#include "../include/string.h"

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[50];
    char *next_position = buffer;

    next_position = my_stpcpy(next_position, "Fast ");
    next_position = my_stpcpy(next_position, "String ");
    next_position = my_stpcpy(next_position, "Concatenation!");

    printf("Result: %s\n", buffer);

    char    *p;
    char    buf1[20];
    char    buf2[20];
    size_t  len;

    if (sizeof(buf2) < strlen("Hello world!"))
        printf("strncpy: truncating character sequence");

    strncpy(buf2, "Hello world!", sizeof(buf2));
    len = strnlen(buf2, sizeof(buf2));

    printf("[len = %zu]: ", len);
    fwrite(buf2, 1, len, stdout);
    putchar('\n');

    if (sizeof(buf1) < strlen("Hello world!"))
        printf("stpncpy: truncating character sequence");
    p = stpncpy(buf1, "Hello world!", sizeof(buf1));
    len = p - buf1;

    printf("[len = %zu]: ", len);
    fwrite(buf1, 1, len, stdout);
    putchar('\n');
    
    return 0;
}