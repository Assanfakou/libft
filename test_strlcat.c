#include <stdio.h>
#include <string.h>

char *ft_strlcat(char *dest, char *src, unsigned int n);

void test_ft_strlcat(char *dest, char *src, unsigned int n, const char *test_name) {
    char original_dest[100];
    strcpy(original_dest, dest);
    
    printf("Test: %s\n", test_name);
    printf("Before: dest = \"%s\", src = \"%s\", n = %u\n", dest, src, n);
    
    char *result = ft_strlcat(dest, src, n);
    
    printf("After:  dest = \"%s\"\n", dest);
    printf("Result: %s\n", (result == dest) ? "Correct" : "Incorrect");
    printf("Original dest: %s\n", original_dest);
    printf("\n");
}

int main() {
    char dest[100];

    // Test 1: Basic concatenation
    strcpy(dest, "Hello ");
    test_ft_strlcat(dest, "World!", 100, "Basic concatenation");

    // Test 2: Concatenation with exact size
    strcpy(dest, "Hello ");
    test_ft_strlcat(dest, "World!", 12, "Exact size");

    // Test 3: Truncation
    strcpy(dest, "Hello ");
    test_ft_strlcat(dest, "World!", 10, "Truncation");

    // Test 4: Empty source string
    strcpy(dest, "Hello");
    test_ft_strlcat(dest, "", 10, "Empty source");

    // Test 5: Empty destination string
    strcpy(dest, "");
    test_ft_strlcat(dest, "Hello", 10, "Empty destination");

    // Test 6: Size smaller than destination length
    strcpy(dest, "Hello");
    test_ft_strlcat(dest, "World!", 3, "Size smaller than dest length");

    return 0;
}
