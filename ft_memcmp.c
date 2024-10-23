#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    size_t i;
    const unsigned char *st;
    const unsigned char * sd;

    st = (const unsigned char *) s1;
    sd = (const unsigned char *) s2;
    i = 0;
    while (i < n)
    {
        if (st[i] == sd[i])
        {
            i++;
        }
        else{
            return (st[i] - sd[i]);
        }
    }
    return (0);
}

// Macros for success and error messages
#define ERROR_MSG(s) "X \033[1;41m"s"\033[0m"
#define SUCCESS_MSG(s) "\xE2\x9C\x93 ""\033[1;32m"s"\033[0m"
#define TEST_FAIL(msg) printf(ERROR_MSG("FAIL")" Test 0x%02X: %s\n", test_case.index, msg)
#define TEST_PASS(msg) printf(SUCCESS_MSG("PASS")" Test 0x%02X: %s\n", test_case.index, msg)

// Test case structure
typedef struct {
    int index;               // Test case index in hexadecimal
    char desc[50];           // Short description
    const void *input1;      // First input (memory block)
    const void *input2;      // Second input (memory block)
    size_t n;                // Number of bytes to compare
    int exp;                 // Expected result (0 if equal, >0 or <0 if different)
} TestCase;

// Array of test cases
TestCase tests[] = {
    {0x01, "Equal memory blocks", "Ben 10", "Ben 10", 6, 0},
    {0x02, "Different memory blocks", "Ben 10", "Ben 11", 6, -1},
    {0x03, "First block longer", "Ben 10", "Ben", 6, 1},
    {0x04, "Second block longer", "Ben", "Ben 10", 6, -1},
    {0x05, "Equal single byte", "A", "A", 1, 0},
    {0x06, "Different single byte", "A", "B", 1, -1},
    {0x07, "Comparison of null byte", "Ben\0", "Ben\1", 6, -1},
    {0x08, "Different bytes at end", "Ben 10", "Ben 10!", 6, -1},
    {0x09, "Full comparison with n = 0", "Ben 10", "Ben 10", 0, 0},
    {0x0A, "Partial comparison, equal", "Ben 10", "Ben 10", 4, 0},
    {0x0B, "Partial comparison, different", "Ben 10", "Ben 11", 4, 0},
};

// Function to run all tests
void run_tests(int (*func_to_test)(const void*, const void*, size_t)) {
    int num_tests = sizeof(tests) / sizeof(tests[0]);

    printf("\n");
    for (int i = 0; i < num_tests; i++) {
        TestCase test_case = tests[i];
        int result = func_to_test(test_case.input1, test_case.input2, test_case.n);

        if (result == test_case.exp) {
            TEST_PASS(test_case.desc);
        } else {
            TEST_FAIL(test_case.desc);
            printf("  -> Exp: %d\n", test_case.exp);
            printf("  -> Got: %d\n", result);
        }
        printf("\n");
    }
}

// Dummy ft_memcmp function for demonstration (replace with your implementation)
int main() {
    run_tests(ft_memcmp); // Run the tests with ft_memcmp function
    return 0;
}
