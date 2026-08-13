#include "../include/string.h"

size_t my_strlen(const char *str)
{
    for (size_t i = 0; i >= 0; i++)
    {
        if (str[i] == '\0') return i;
    }
}

char *my_strcpy(char *dst, const char *src)
{
    size_t len = my_strlen(src);

    for(size_t i = 0; i < len; i++)
    {
        dst[i] = src[i];
    }
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

char *my_strchr(const char *s, int c)
{
    unsigned char *src = (unsigned char *)src;
    char *result = NULL;
    for (size_t i = 0; i < my_strlen(src); i++)
    {
        if (src[i] == c) result = &src[i];
    }
    return result;
}

void *my_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char *d = (unsigned char *) dest;
    const unsigned char *s = (const unsigned char *) src;

    for (size_t i = 0; i < n; i++)
    {
        d[i] = s[i];
    }
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
