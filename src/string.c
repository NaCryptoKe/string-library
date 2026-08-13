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
