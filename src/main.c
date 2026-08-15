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

    if (sizeof(buf2) < my_strlen("Hello world!"))
        printf("strncpy: truncating character sequence");

    my_strncpy(buf2, "Hello world!", sizeof(buf2));
    len = strnlen(buf2, sizeof(buf2));

    printf("[len = %zu]: ", len);
    fwrite(buf2, 1, len, stdout);
    putchar('\n');

    if (sizeof(buf1) < my_strlen("Hello world!"))
        printf("stpncpy: truncating character sequence");
    p = my_stpncpy(buf1, "Hello world!", sizeof(buf1));
    len = p - buf1;

    printf("[len = %zu]: ", len);
    fwrite(buf1, 1, len, stdout);
    putchar('\n');

    int numbers[5] = {10, 20, 30, 40, 50};

    my_memset(numbers, 0, sizeof(numbers));

    for(int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]); // Output: 0 0 0 0 0
    }

    char dest[20] = "Hello ";
    char src[] = "World!";
    my_strcat(dest, src);
    printf("\n%s\n", dest); // Output: Hello World!
    
    return 0;
}