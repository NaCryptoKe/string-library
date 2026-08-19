#ifndef STRING_H
#define STRING_H

#include <stddef.h>
#include <stdlib.h>
#include <locale.h>

/*
 * string.h (the original) has the following functions
 * 1. memcpy            [x]
 * 2. memchr            [x]
 * 3. memcmp            [x]
 * 4. memmove           [x]
 * 5. memset            [x]
 * 6. stpcpy            [x]
 * 7. stpncpy           [x]
 * 8. strcat            [x]
 * 9. strchr            [x]
 * 10. strcmp           [x]
 * 11. strcoll          [-]
 * 12. strcoll_l        [-]
 * 13. strcpy           [x]
 * 14. strcspn          [x]
 * 15. strdup           [x]
 * 16. strerror         [-]
 * 17. strerror_l       [-]
 * 18. strerror_r       [-]
 * 19. strlen           [x]
 * 20. strncat          [x]
 * 21. strncmp          [x]
 * 22. strncpy          [x]
 * 23. strndup          [x]
 * 24. strnlen          [x]
 * 25. strpbrk          [-]
 * 26. strrchr          [-]
 * 27. strsignal        [-]
 * 28. strspn           [-]
 * 29. strstr           [-]
 * 30. strtok           [-]
 * 31. strtok_r         [-]
 * 32. strxfrm          [-]
 * 33. strxfrm_l        [-]
*/

void *my_memcpy(void *dest, const void *src, size_t n);
void *my_memchr(const void *s, int c, size_t n);
int my_memcmp(const void *s1, const void *s2, size_t n);
void *my_memmove(void *dest, const void *src, size_t n);
void *my_memset(void *s, int c, size_t n);
char *my_stpcpy(char *dest, const char *src);
char *my_stpncpy(char *dest, const char *src, size_t n);
char *my_strcat(char *dest, const char *src);
char *my_strchr(const char *s, int c);
int my_strcmp(const char *s1, const char *s2);
int my_strcoll (const char *s1, const char *s2);
// int my_strcoll_l(const char *s1, const char *s2, locale_t locale);
char *my_strcpy(char *dst, const char *src);
size_t my_strcspn(const char *s, const char *r);
char *my_strdup(const char *s);
size_t my_strlen(const char *str);
char *my_strncat (char *dest, const char *src, size_t n);
int my_strncmp(const char *s1, const char *s2, size_t n);
char *my_strncpy(char *dest, const char *src, size_t n);
char *my_strndup(const char *s, size_t n);
size_t my_strnlen(const char *s, size_t n);

#endif  // STRING_H
