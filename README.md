# MY_STRING

A from scratch implementation of the C standard library in `<string.h>`, prefixed with `my_` to avoid clashing with the original ones.

## Why?

Built as a learning project only utilizing man pages, and trial & error.

It helped me understand:

- standard stirng
- memory functions
- pointer arithmetic
- edge cases (overlapping memory)
- and other implementations that real codebases have to handle correctly

## Implemented functions

- my_memcpy, my_memmove, my_memset, my_memchr, my_memcmp
- my_strcpy, my_strncpy, my_stpcpy, my_stpncpy
- my_strcat, my_strncat
- my_strcmp, my_strncmp, my_strcoll
- my_strchr
- my_strlen, my_strnlen
- my_strdup, my_strndup
- my_strcspn

See `included/string.h` for the full checklist of what's covered versus the real `<string.h>`

## Building

```bash
gcc -Wall -Wextra -std=c11 -c src/string.c
```

## Running the tests

``` bash
gcc -Wall -Wextra -std=c11 -g -fsanitize=address,undefined src/string.c src/main.c -o main
./main
```

## NOTES

- No dynamic memory is used except in my_strdup / my_strndup, matching the real functions
- my_strcoll does not implement the locale aware collation; it falls back to plain byte-wise comparison
- This is not intended as a production replacement for `<string.h>`. It exists for learning purposes.