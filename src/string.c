#include "../include/string.h"

size_t strlen(char str[])
{
    for (size_t i = 0; i >= 0; i++)
    {
        if (str[i] == '\0') return i;
    }
}