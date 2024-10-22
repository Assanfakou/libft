#include <stddef.h>
#include "libft.h"
#include <stdio.h>

void    *ft_memmove(void *dest, const void *src, size_t n)
{                                                                                                           
    char    *de;
    const char *sr;
    size_t i;

    de = (char *) dest;
    sr = (const char *) src;
    if (de == sr)
        return (de);
    if (de > sr)
    {
        i = 0;
        while (i < n)
        {
            de[i] = sr[i];
            i++;
        }
    }else{
        i = n;
        while (i > 0)
        {
            de[i - 1] = sr[i - 1];
            i--;
        }
    }
    return (de);
}
#include <string.h>

/*int main ()
{
    char st[] = "helloworld";

    ft_memmove(st + 2, st + 5, 5);
    printf("%s\n", st);
}*/
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
    char input[50];           // Input buffer before moving
    size_t n;                 // Number of bytes to move
    size_t dest_offset;       // Offset where to move the bytes in input
    char expected[50];        // Expected result after moving
} TestCase;

// Array of test cases
TestCase tests[] = {
    {0x01, "Non-overlapping move", "Ben 10 is cool", 6, 10, "Ben 10 is Ben 10 is cool"},
    {0x02, "Overlapping move forward", "Hello World", 5, 6, "Hello Hello World"},
    {0x03, "Overlapping move backward", "Hello World", 5, 1, "HHello World"},
    {0x04, "Move to same location", "No Change", 10, 0, "No Change"},
    {0x05, "Moving beyond string length", "Too long string", 20, 0, "Too long string"},
    {0x06, "Empty move", "Data", 0, 2, "Data"},
    {0x07, "Zero-length move", "Alien X", 0, 0, "Alien X"},
    {0x08, "Single character move", "Z", 1, 0, "Z"},
};

// Function to run all tests
void run_tests(void *(*func_to_test)(void *, const void *, size_t)) {
    int num_tests = sizeof(tests) / sizeof(tests[0]);

    printf("\n");
    for (int i = 0; i < num_tests; i++) {
        TestCase test_case = tests[i];
        
        // Create a copy of input to modify
        char buffer[50];
        strcpy(buffer, test_case.input);

        // Run the function to test
        func_to_test(buffer + test_case.dest_offset, buffer, test_case.n);

        // Check if the result matches the expected output
        if (strcmp(buffer, test_case.expected) == 0) {
            TEST_PASS(test_case.desc);
        } else {
            TEST_FAIL(test_case.desc);
            printf("  -> Expected: \"%s\"\n", test_case.expected);
            printf("  -> Got: \"%s\"\n", buffer);
        }
        printf("\n");
    }
}

// Dummy ft_memmove function for demonstration (replace with your implementation)

int main() {
    run_tests(ft_memmove); // Run the tests with ft_memmove function
    return 0;
}
