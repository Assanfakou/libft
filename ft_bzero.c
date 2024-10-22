#include "libft.h"

void    ft_bzero(void *s, size_t n)
{
    size_t i;
    char    *st;

    st = (char *) s;
    i = 0;
    while (i < n)
    {
        st[i] = 0;
        i++;
    }
}
/*int main ()
{
    char st[10];
    int i;

    i = 0;
    while (i < 10)
    {
        st[i] = i;
        i++;
    }
    ft_bzero(st, 10);
    i = 0;
    while (i < 10)
    {
        printf("%d " , st[i]);
        i++;
    }
}
*/
#include <stdio.h>
#include <string.h>

// Macros for success and error messages
#define ERROR_MSG(s) "X \033[1;41m"s"\033[0m"
#define SUCCESS_MSG(s) "\xE2\x9C\x93 ""\033[1;32m"s"\033[0m"
#define TEST_FAIL(msg) printf(ERROR_MSG("FAIL")" Test 0x%02X: %s\n", test_case.index, msg)
#define TEST_PASS(msg) printf(SUCCESS_MSG("PASS")" Test 0x%02X: %s\n", test_case.index, msg)

// Test case structure
typedef struct {
    int index;               // Test case index in hexadecimal
    char desc[50];           // Short description
    char input[50];          // Input buffer to be zeroed
    size_t n;                // Number of bytes to zero
    char expected[50];       // Expected result after zeroing
} TestCase;

// Array of test cases
TestCase tests[] = {
    {0x01, "Zeroing a short string", "Ben 10", 6, "\0\0\0\0\0\0"},
    {0x02, "Zeroing an empty string", "", 0, ""},
    {0x03, "Zeroing a longer string", "Heatblast", 5, "\0\0\0\0\0"},
    {0x04, "Zeroing beyond string length", "Forearms", 15, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"},
    {0x05, "Zeroing a null buffer", "", 0, ""},
    {0x06, "Zeroing a single character", "A", 1, "\0"},
    {0x07, "Zeroing multiple characters", "Alien X", 4, "\0\0\0\0 Alien X"},
    {0x08, "Zeroing full buffer", "Ben 10 is cool", 14, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"},
};

// Function to run all tests
void run_tests(void (*func_to_test)(void *, size_t)) {
    int num_tests = sizeof(tests) / sizeof(tests[0]);

    printf("\n");
    for (int i = 0; i < num_tests; i++) {
        TestCase test_case = tests[i];
        // Create a copy of input to modify
        char buffer[50];
        strcpy(buffer, test_case.input);

        // Run the function to test
        func_to_test(buffer, test_case.n);

        // Check if the result matches the expected output
        if (strncmp(buffer, test_case.expected, test_case.n) == 0) {
            TEST_PASS(test_case.desc);
        } else {
            TEST_FAIL(test_case.desc);
            printf("  -> Expected: \"%.*s\"\n", (int)test_case.n, test_case.expected);
            printf("  -> Got: \"%.*s\"\n", (int)test_case.n, buffer);
        }
        printf("\n");
    }
}

// Dummy ft_bzero function for demonstration (replace with your implementation)

int main() {
    run_tests(ft_bzero); // Run the tests with ft_bzero function
    return 0;
}
