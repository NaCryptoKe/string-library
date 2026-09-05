#include "../include/string.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

static int failures = 0;

#define CHECK(cond, msg) do { \
    if (!(cond)) { printf("FAIL: %s (line %d)\n", msg, __LINE__); failures++; } \
} while (0)

static void test_strlen(void) {
    CHECK(my_strlen("") == 0, "strlen empty");
    CHECK(my_strlen("hello") == 5, "strlen hello");
    CHECK(my_strlen("a") == 1, "strlen a");
}

static void test_strcpy(void) {
    char buf[32];
    memset(buf, 'X', sizeof(buf));
    my_strcpy(buf, "hello");
    CHECK(strcmp(buf, "hello") == 0, "strcpy hello");
    CHECK(buf[5] == '\0', "strcpy null terminator");

    char buf2[8];
    my_strcpy(buf2, "");
    CHECK(buf2[0] == '\0', "strcpy empty");
}

static void test_strcat(void) {
    char buf[32] = "foo";
    my_strcat(buf, "bar");
    CHECK(strcmp(buf, "foobar") == 0, "strcat foobar");

    char buf2[32] = "";
    my_strcat(buf2, "onlysrc");
    CHECK(strcmp(buf2, "onlysrc") == 0, "strcat empty dest");

    char buf3[32] = "foo";
    my_strcat(buf3, "");
    CHECK(strcmp(buf3, "foo") == 0, "strcat empty src");
}

static void test_strcmp(void) {
    CHECK(my_strcmp("abc", "abc") == 0, "strcmp equal");
    CHECK(my_strcmp("abc", "abd") < 0, "strcmp less");
    CHECK(my_strcmp("abd", "abc") > 0, "strcmp greater");
    CHECK(my_strcmp("abc", "abcdef") < 0, "strcmp prefix shorter");
    CHECK(my_strcmp("abcdef", "abc") > 0, "strcmp prefix longer");
    CHECK(my_strcmp("", "") == 0, "strcmp both empty");
    CHECK(my_strcmp("", "a") < 0, "strcmp empty vs nonempty");
    CHECK((my_strcmp("abc", "abc") == 0) == (strcmp("abc","abc")==0), "strcmp matches libc sign (eq)");
    CHECK((my_strcmp("abc", "abz") < 0) == (strcmp("abc","abz")<0), "strcmp matches libc sign (lt)");
}

static void test_strncmp(void) {
    CHECK(my_strncmp("abcxx", "abcyy", 3) == 0, "strncmp equal prefix");
    CHECK(my_strncmp("abc", "abd", 3) < 0, "strncmp diff within n");
    CHECK(my_strncmp("ab", "abc", 3) < 0, "strncmp shorter string stops at nul");
    CHECK(my_strncmp("abc", "abc", 0) == 0, "strncmp n=0");
}

static void test_strchr(void) {
    const char *s = "hello world";
    CHECK(my_strchr(s, 'h') == strchr(s, 'h'), "strchr first char");
    CHECK(my_strchr(s, 'o') == strchr(s, 'o'), "strchr first occurrence (should match libc's FIRST match)");
    CHECK(my_strchr(s, 'z') == NULL, "strchr not found");
    CHECK(my_strchr(s, '\0') == s + strlen(s), "strchr null terminator");
}

static void test_strncat(void) {
    char buf[32] = "foo";
    my_strncat(buf, "barbaz", 3);
    CHECK(strcmp(buf, "foobar") == 0, "strncat truncates to n");

    char buf2[32] = "foo";
    my_strncat(buf2, "ba", 5);
    CHECK(strcmp(buf2, "fooba") == 0, "strncat shorter src than n");
}

static void test_strncpy(void) {
    char buf[10];
    memset(buf, 'X', sizeof(buf));
    my_strncpy(buf, "hi", 5);
    CHECK(memcmp(buf, "hi\0\0\0", 5) == 0, "strncpy pads with nulls");

    char buf2[10];
    memset(buf2, 'X', sizeof(buf2));
    my_strncpy(buf2, "hello world", 5);
    CHECK(memcmp(buf2, "hello", 5) == 0, "strncpy truncates, no implicit null");
}

static void test_strdup_strndup(void) {
    char *d = my_strdup("hello");
    CHECK(strcmp(d, "hello") == 0, "strdup content");
    free(d);

    char *n = my_strndup("hello world", 5);
    CHECK(strcmp(n, "hello") == 0, "strndup truncated content");
    free(n);

    char *n2 = my_strndup("hi", 10);
    CHECK(strcmp(n2, "hi") == 0, "strndup n > strlen");
    free(n2);
}

static void test_memchr(void) {
    const char *s = "hello";
    CHECK(my_memchr(s, 'l', 5) == memchr(s, 'l', 5), "memchr matches libc (first match)");
    CHECK(my_memchr(s, 'z', 5) == NULL, "memchr not found");

    // memchr must work on arbitrary bytes including embedded nulls
    unsigned char buf[5] = {1, 0, 3, 4, 0};
    CHECK(my_memchr(buf, 0, 5) == buf + 1, "memchr embedded null - finds first zero byte");
    CHECK(my_memchr(buf, 4, 5) == buf + 3, "memchr arbitrary byte after embedded null");
}

static void test_memcmp(void) {
    CHECK(my_memcmp("abc", "abc", 3) == 0, "memcmp equal");
    CHECK(my_memcmp("abc", "abd", 3) < 0, "memcmp less");
    unsigned char a[3] = {0, 1, 2};
    unsigned char b[3] = {0, 1, 3};
    CHECK(my_memcmp(a, b, 3) < 0, "memcmp unsigned byte compare");
}

static void test_memmove_overlap(void) {
    char buf[] = "abcdefgh";
    my_memmove(buf + 2, buf, 5); // overlapping, dest after src
    CHECK(memcmp(buf, "ababcdeh", 8) == 0, "memmove overlap dest>src");

    char buf2[] = "abcdefgh";
    my_memmove(buf2, buf2 + 2, 5);
    CHECK(memcmp(buf2, "cdefgfgh", 8) == 0, "memmove overlap dest<src");
}

static void test_stpcpy_stpncpy(void) {
    char buf[32];
    char *end = my_stpcpy(buf, "hi");
    CHECK(strcmp(buf, "hi") == 0, "stpcpy content");
    CHECK(end == buf + 2, "stpcpy return points at nul");

    char buf2[32];
    memset(buf2, 'X', sizeof(buf2));
    char *end2 = my_stpncpy(buf2, "hi", 5);
    CHECK(end2 == buf2 + 2, "stpncpy return when src shorter than n (points at copied nul)");
    CHECK(memcmp(buf2, "hi\0\0\0", 5) == 0, "stpncpy pads with nulls");

    char buf3[32];
    char *end3 = my_stpncpy(buf3, "hello world", 5);
    CHECK(end3 == buf3 + 5, "stpncpy return when src longer than n");
}

static void test_strcspn(void) {
    CHECK(my_strcspn("hello", "lo") == 2, "strcspn basic");
    CHECK(my_strcspn("hello", "xyz") == 5, "strcspn no match -> full length");
    CHECK(my_strcspn("hello", "") == 5, "strcspn empty reject set");
}

static void test_strnlen(void) {
    CHECK(my_strnlen("hello", 3) == 3, "strnlen capped");
    CHECK(my_strnlen("hi", 10) == 2, "strnlen shorter than n");
}

static void test_strcoll(void) {
    CHECK(my_strcoll("abc", "abd") < 0, "strcoll falls back to byte compare");
}

int main(void) {
    test_strlen();
    test_strcpy();
    test_strcat();
    test_strcmp();
    test_strncmp();
    test_strchr();
    test_strncat();
    test_strncpy();
    test_strdup_strndup();
    test_memchr();
    test_memcmp();
    test_memmove_overlap();
    test_stpcpy_stpncpy();
    test_strcspn();
    test_strnlen();
    test_strcoll();

    if (failures == 0) {
        printf("ALL TESTS PASSED\n");
        return 0;
    } else {
        printf("%d TEST(S) FAILED\n", failures);
        return 1;
    }
}