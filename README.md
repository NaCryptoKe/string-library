# MY_STRING

A from scratch implementation of the C standard library in `<string.h>`, prefixed with `my_` to avoid clashing with the original ones.

## Why?

Built as a learning project only utilizing man pages, and trial & error.

It helped me understand:

- standard string
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

### Not implemented yet

- my_strcoll_l (declared only)
- my_strerror, my_strerror_l, my_strerror_r
- my_strpbrk, my_strrchr, my_strsignal, my_strspn, my_strstr
- my_strtok, my_strtok_r
- my_strxfrm, my_strxfrm_l

See `include/my_string.h` for the full checklist of what's covered versus the real `<string.h>`.

## Project layout

```
.
├── include/
│   └── my_string.h      # public prototypes + coverage checklist
├── src/
│   ├── string.c         # the implementations
│   └── main.c           # test suite
├── Makefile
└── README.md
```

## Building

With the Makefile:

```bash
make          # builds the test binary (sanitizers enabled)
```

Or by hand, compiling the library on its own:

```bash
gcc -Wall -Wextra -std=c11 -Iinclude -c src/string.c
```

## Running the tests

With the Makefile:

```bash
make test
```

Or by hand:

```bash
gcc -Wall -Wextra -std=c11 -g -fsanitize=address,undefined -Iinclude src/string.c src/main.c -o main
./main
```

The tests build and run with AddressSanitizer and UndefinedBehaviorSanitizer so
that out-of-bounds accesses and undefined behaviour fail loudly instead of
silently passing.

## NOTES

- No dynamic memory is used except in my_strdup / my_strndup, matching the real functions
- my_strcoll does not implement the locale aware collation; it falls back to plain byte-wise comparison
- my_memmove compares addresses as `uintptr_t`, since relational comparison of
  pointers into different objects is undefined behaviour in strict ISO C
- The header lives at `include/my_string.h` (not `string.h`) so that it can never
  shadow the system `<string.h>` when `-Iinclude` is on the search path
- This is not intended as a production replacement for `<string.h>`. It exists for learning purposes.