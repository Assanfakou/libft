#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
    unsigned char *ptr;
    size_t i;

    ptr = malloc(nmemb * size);
    if (ptr == NULL)
        return (NULL);
    i = 0;
    while (i < nmemb * size)
    {
        ptr[i] = 0;
        i++;
    }
    return (void *)(ptr);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>

#define ERROR_MSG(s) "X \033[1;41m"s"\033[0m"
#define SUCCESS_MSG(s) "\xE2\x9C\x93 ""\033[1;32m"s"\033[0m"
#define TEST_FAIL(msg) printf(ERROR_MSG("FAIL")" Test 0x%02X: %s\n", test_case.index, msg)
#define TEST_PASS(msg) printf(SUCCESS_MSG("PASS")" Test 0x%02X: %s\n", test_case.index, msg)

typedef struct {
    int index;          // Test case index in hexadecimal
    char desc[100];     // Short description
    size_t count;       // Number of elements
    size_t size;        // Size of each element
    int exp_null;       // Expected NULL return (1 for NULL, 0 for valid pointer)
    size_t exp_size;    // Expected total size
    int exp_zeroed;     // Expected to be zeroed (1 for yes, 0 for no)
} TestCase;

// Function prototype
void *ft_calloc(size_t count, size_t size);

// Array of test cases
TestCase tests[] = {
    // Basic allocation tests
    {0x01, "Basic int array allocation", 5, sizeof(int), 0, 5 * sizeof(int), 1},
    {0x02, "Basic char array allocation", 10, sizeof(char), 0, 10, 1},
    {0x03, "Single element allocation", 1, sizeof(double), 0, sizeof(double), 1},
    
    // Zero and NULL tests
    {0x04, "Zero count allocation", 0, sizeof(int), 0, 0, 1},
    {0x05, "Zero size allocation", 5, 0, 0, 0, 1},
    {0x06, "Both zero allocation", 0, 0, 0, 0, 1},
    
    // Edge cases
    {0x07, "Large count allocation", 1000000, sizeof(char), 0, 1000000, 1},
    {0x08, "SIZE_MAX count overflow", SIZE_MAX, sizeof(int), 1, 0, 0},
    {0x09, "SIZE_MAX size overflow", 1, SIZE_MAX, 1, 0, 0},
    {0x0A, "Overflow multiplication", SIZE_MAX/2 + 1, 2, 1, 0, 0},
    
    // Typical use cases
    {0x0B, "Struct-sized allocation", 1, 256, 0, 256, 1},
    {0x0C, "String buffer allocation", 100, sizeof(char), 0, 100, 1},
    {0x0D, "Array of pointers", 10, sizeof(void*), 0, 10 * sizeof(void*), 1},
};

int check_zeroed_memory(void *ptr, size_t total_size) {
    unsigned char *bytes = (unsigned char*)ptr;
    for (size_t i = 0; i < total_size; i++) {
        if (bytes[i] != 0) {
            return 0;
        }
    }
    return 1;
}

void run_tests() {
    int num_tests = sizeof(tests) / sizeof(tests[0]);
    int passed = 0;
    printf("\nRunning ft_calloc tests...\n\n");
    
    for (int i = 0; i < num_tests; i++) {
        TestCase test_case = tests[i];
        void *result = ft_calloc(test_case.count, test_case.size);
        
        // Test for NULL when expected
        if (test_case.exp_null) {
            if (result == NULL) {
                TEST_PASS(test_case.desc);
                passed++;
            } else {
                TEST_FAIL(test_case.desc);
                printf("  -> Expected: NULL\n");
                printf("  -> Got: valid pointer\n");
                free(result);
            }
            continue;
        }
        
        // Test for valid allocation and zeroing
        if (result == NULL && !test_case.exp_null) {
            TEST_FAIL(test_case.desc);
            printf("  -> Expected: valid pointer\n");
            printf("  -> Got: NULL\n");
            continue;
        }
        
        // Check if memory is zeroed when expected
        int is_zeroed = check_zeroed_memory(result, test_case.exp_size);
        if (test_case.exp_zeroed && !is_zeroed) {
            TEST_FAIL(test_case.desc);
            printf("  -> Memory not properly zeroed\n");
            free(result);
            continue;
        }
        
        TEST_PASS(test_case.desc);
        passed++;
        free(result);
    }
    
    printf("\nTest Summary: %d/%d tests passed\n\n", passed, num_tests);
}

int main() {
    run_tests();
    return 0;
}

/*
int main ()
{
    char *st = ft_calloc(5, sizeof(int));
    printf("%d\n", *(st + 0));
    printf("%d\n", *(st + 1));
    printf("%d\n", *(st + 2));
    printf("%d\n", *(st + 3));
    printf("%d\n", *(st + 4));
    printf("%d\n", *(st + 5));
    printf("%d\n", *(st + 6));
    printf("%d\n", *(st + 7));
    printf("%d\n", *(st + 8));
    printf("%d\n", *(st + 9));
    printf("%d\n", st[10]);
}*/