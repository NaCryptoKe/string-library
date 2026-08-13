#ifndef STRING_H
#define STRING_H

#include <stddef.h>
#include <stdio.h>

/*
 * string.h (the original) has the following functions
 * 1. memcpy
 * 2. memchr
 * 3. memcmp
 * 4. memmove
 * 5. memset
 * 6. stpcpy
 * 7. stpncpy
 * 8. strcat
 * 9. strchr
 * 10. strcmp
 * 11. strcoll
 * 12. strcoll_l
 * 13. strcpy           [x]
 * 14. strcspn
 * 15. strdup
 * 16. strerror
 * 17. strerror_l
 * 18. strerror_r
 * 19. strlen           [x]
 * 20. strncat
 * 21. strncmp
 * 22. strncpy
 * 23. strndup
 * 24. strnlen
 * 25. strpbrk
 * 26. strrchr
 * 27. strsignal
 * 28. strspn
 * 29. strstr
 * 30. strtok
 * 31. strtok_r
 * 32. strxfrm
 * 33. strxfrm_l
*/

size_t my_strlen(const char str[]);
char *my_strcpy(char *dst, const char *src);
int my_strcmp(const char *s1, const char *s2);
#endif  // STRING_H
