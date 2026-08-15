#include "../include/string.h"
#include <stdlib.h>

void *my_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char *d = (unsigned char *) dest;
    const unsigned char *s = (const unsigned char *) src;

    for (size_t i = 0; i < n; i++)
    {
        d[i] = s[i];
    }
    return d;
}

void *my_memchr(const void *s, int c, size_t n)
{
    unsigned char *str = (unsigned char *)s;
    unsigned char ch = (unsigned char) c;

    unsigned char *result_str = NULL;

    for (size_t i = 0; i < my_strlen(s); i++)
    {
        if (str[i] == ch) result_str = str + i;
    }

    return result_str;
}

int my_memcmp(const void *s1, const void *s2, size_t n)
{
    unsigned char *str1 = (unsigned char*) s1;
    unsigned char *str2 = (unsigned char*) s2;

    for (size_t i = 0; i < n; i++)
    {
        if (str1[i] - str2[i] != 0) return str1[i] - str2[i];
    }
    return 0;
}

void *my_memmove(void *dest, const void *src, size_t n)
{
    if (dest == src || n == 0) 
    {
        return dest;
    }
    unsigned char *d = (unsigned char *) dest;
    unsigned char *s = (unsigned char *) src;
    
    if (d < s)
    {
        // Non-overlapping or dest comes before src. 
        // Copy forward (left to right).
        for (size_t i = 0; i < n; i++)
        {
            d[i] = s[i];
        }
    }
    else
    {
        // Dest comes after src, meaning they might overlap.
        // Copy backward (right to left) to preserve source data.
        for (size_t i = n; i > 0; i--) {
            d[i - 1] = s[i - 1];
        }
    }

    return dest;
}

char *my_strchr(const char *s, int c)
{
    unsigned char *src = (unsigned char *)s;
    char *result = NULL;
    for (size_t i = 0; i < my_strlen(src); i++)
    {
        if (src[i] == c) result = &src[i];
    }
    return result;
}

int my_strcmp(const char *s1, const char *s2)
{
    size_t len = my_strlen(s1);

    for (size_t i = 0; i < len; i++)
    {
        int result = s1[i] - s2[i];
        if (result != 0) return result;
    }
    return 0;
}

char *my_strcpy(char *dest, const char *src)
{
    unsigned char *s = (unsigned char *) src; 

    for(size_t i = 0; i < my_strlen(src); i++)
    {
        dest[i] = s[i];
    }

    return dest;
}

size_t my_strlen(const char *str)
{
    for (size_t i = 0; i >= 0; i++)
    {
        if (str[i] == '\0') return i;
    }
}