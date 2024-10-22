#include "libft.h"

void    *ft_memchr(const void *s, int c, size_t n)
{
    size_t i;
    const unsigned char *st;
    unsigned char l;

    st = (const unsigned char *) s;
    l = (unsigned char) c;
    if (n == 0)
    {
        return (NULL);
    }
    i = 0;
    while (i < n)
    {
        if (st[i] == l)
        {
            return (void *)(st + i);
        }
        i++;
    }
    return (NULL);
}
#include <stdio.h>
#include <string.h>

// Macros for success and error messages
#define ERROR_MSG(s) "X \033[1;41m"s"\033[0m"
#define SUCCESS_MSG(s) "\xE2\x9C\x93 ""\033[1;32m"s"\033[0m"
#define TEST_FAIL(msg) printf(ERROR_MSG("FAIL")" Test 0x%02X: %s\n", test_case.index, msg)
#define TEST_PASS(msg) printf(SUCCESS_MSG("PASS")" Test 0x%02X: %s\n", test_case.index, msg)

// Test case structure
typedef struct {
    int index;                // Test case index in hexadecimal
    char desc[50];            // Short description
    const char *input;        // Input buffer
    int c;                    // Character to find
    size_t n;                 // Number of bytes to search
    const char *expected;     // Expected pointer result
} TestCase;

// Array of test cases
TestCase tests[] = {
    {0x01, "Find middle character", "Hello, World!", 'W', 13, "World!"},
    {0x02, "Find first character", "Ben 10 is cool", 'B', 15, "Ben 10 is cool"},
    {0x03, "Find last character", "Ben 10 is cool", 'l', 15, "l"},
    {0x04, "Character not found", "Alien X", 'Z', 8, NULL},
    {0x05, "Find null terminator", "Null terminator\0 test", '\0', 20, "Null terminator\0 test"},
    {0x06, "Empty string", "", 'A', 0, NULL},
    {0x07, "Single character match", "A", 'A', 1, "A"},
    {0x08, "Single character no match", "A", 'B', 1, NULL},
};

// Function to run all tests
void run_tests(void *(*func_to_test)(const void *, int, size_t)) {
    int num_tests = sizeof(tests) / sizeof(tests[0]);

    printf("\n");
    for (int i = 0; i < num_tests; i++) {
        TestCase test_case = tests[i];

        // Run the function to test
        char *result = (char *)func_to_test(test_case.input, test_case.c, test_case.n);

        // Check if the result matches the expected output
        if ((result == NULL && test_case.expected == NULL) || (result && strcmp(result, test_case.expected) == 0)) {
            TEST_PASS(test_case.desc);
        } else {
            TEST_FAIL(test_case.desc);
            if (result) {
                printf("  -> Expected: \"%s\"\n", test_case.expected);
                printf("  -> Got: \"%s\"\n", result);
            } else {
                printf("  -> Expected: NULL\n");
                printf("  -> Got: %s\n", result);
            }
        }
        printf("\n");
    }
}

int main() {
    run_tests(ft_memchr); // Run the tests with ft_memchr function
    return 0;
}
