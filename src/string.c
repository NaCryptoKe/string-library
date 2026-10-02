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
    const unsigned char *str = (const unsigned char *) s;
    unsigned char ch = (unsigned char) c;

    for (size_t i = 0; i < n; i++)
    {
        if (str[i] == ch) return (void *) (str + i);
    }

    return NULL;
}

int my_memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char *str1 = (const unsigned char *) s1;
    const unsigned char *str2 = (const unsigned char *) s2;

    for (size_t i = 0; i < n; i++)
    {
        if (str1[i] != str2[i]) return (int) str1[i] - (int) str2[i];
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
    const unsigned char *s = (const unsigned char *) src;

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

void *my_memset(void *s, int c, size_t n)
{
    unsigned char *src = (unsigned char *) s;
    unsigned char ch = (unsigned char) c;

    for (size_t i = 0; i < n; i++)
    {
        src[i] = ch;
    }

    return s;
}

char *my_stpcpy(char *dest, const char *src)
{
    size_t i;
    for (i = 0; src[i] != '\0'; i++)
    {
        dest[i] = src[i];
    }
    dest[i] = '\0';

    return dest + i;
}

char *my_stpncpy(char *dest, const char *src, size_t n)
{
    size_t len = my_strlen(src);
    my_strncpy(dest, src, n);

    return dest + (len < n ? len : n);
}

char *my_strcat(char *dest, const char *src)
{
    size_t dlen = my_strlen(dest);
    size_t i;

    for (i = 0; src[i] != '\0'; i++)
    {
        dest[dlen + i] = src[i];
    }
    dest[dlen + i] = '\0';

    return dest;
}

char *my_strchr(const char *s, int c)
{
    unsigned char ch = (unsigned char) c;
    size_t i = 0;

    for (;; i++)
    {
        if ((unsigned char) s[i] == ch) return (char *) &s[i];
        if (s[i] == '\0') break;
    }

    return NULL;
}

int my_strcmp(const char *s1, const char *s2)
{
    size_t i = 0;

    while (s1[i] != '\0' && s1[i] == s2[i])
    {
        i++;
    }

    return (unsigned char) s1[i] - (unsigned char) s2[i];
}

int my_strcoll (const char *s1, const char *s2)
{
    // Locale-aware collation isn't implemented; fall back to a plain
    // byte-wise comparison (equivalent to the "C" locale).
    return my_strcmp(s1, s2);
}

// TODO: not implemented yet.
// int my_strcoll_l(const char *s1, const char *s2, locale_t locale)
// {
//     // tbd
// }

char *my_strcpy(char *dest, const char *src)
{
    size_t i;

    for (i = 0; src[i] != '\0'; i++)
    {
        dest[i] = src[i];
    }
    dest[i] = '\0';

    return dest;
}

size_t my_strcspn(const char *s, const char *r)
{
    const unsigned char *source = (const unsigned char *) s;
    const unsigned char *reject = (const unsigned char *) r;

    size_t len = my_strlen(s);
    size_t rlen = my_strlen(r);

    for (size_t i = 0; i < len; i++)
    {
        for (size_t j = 0; j < rlen; j++)
        {
            if (source[i] == reject[j]) return i;
        }
    }

    return len;
}

char *my_strdup(const char *s)
{
    size_t len = my_strlen(s);

    char *result = (char *) malloc((len + 1) * sizeof(char));
    if (result == NULL) return NULL;

    my_strcpy(result, s);

    return result;
}

size_t my_strlen(const char *str)
{
    size_t i;
    for (i = 0; str[i] != '\0'; i++)
    {
        // counting
    }
    return i;
}

char *my_strncat (char *dest, const char *src, size_t n)
{
    size_t d_len = my_strlen(dest);
    size_t i;

    for (i = 0; i < n && src[i] != '\0'; i++)
    {
        dest[d_len + i] = src[i];
    }
    dest[d_len + i] = '\0';

    return dest;
}

int my_strncmp(const char *s1, const char *s2, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        unsigned char c1 = (unsigned char) s1[i];
        unsigned char c2 = (unsigned char) s2[i];

        if (c1 != c2) return (int) c1 - (int) c2;
        if (c1 == '\0') return 0;
    }

    return 0;
}

char *my_strncpy(char *dest, const char *src, size_t n)
{
    size_t len = my_strlen(src) >= n ? n : my_strlen(src);

    for (size_t i = 0; i < len; i++)
    {
        dest[i] = src[i];
    }

    for (size_t i = len; i < n; i++)
    {
        dest[i] = '\0';
    }

    return dest;
}

char *my_strndup(const char *s, size_t n)
{
    size_t len = my_strlen(s);
    size_t copy_len = len < n ? len : n;

    char *result = (char *) malloc((copy_len + 1) * sizeof(char));
    if (result == NULL) return NULL;

    my_strncpy(result, s, copy_len);
    result[copy_len] = '\0';

    return result;
}

size_t my_strnlen(const char *s, size_t n)
{
    size_t i;
    for (i = 0; i < n && s[i] != '\0'; i++)
    {
        // counting
    }
    return i;
}