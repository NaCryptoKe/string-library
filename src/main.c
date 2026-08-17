#include "../include/string.h"

#include <stdio.h>
#include <string.h>

int main()
{
    int size;

    char *str1 = "Nahom";
    char *dup = my_strdup(str1);

    if (dup == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }
    
    // 3. Print and manipulate the duplicated string
    printf("Original:  %s\n", str1);
    printf("Duplicate: %s\n", dup);
    
    // 4. Free the allocated memory to avoid memory leaks
    free(dup);
    
    return 0;
}