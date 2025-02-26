#ifndef TESTS_H
#define TESTS_H

#include <iostream>
#include "AddSubClass.h"

#define TEST_ASSERT(condition) \
    if (condition) { \
        std::cout << "Test passed: " << #condition << std::endl; \
    } else { \
        std::cerr << "Test failed: " << #condition << std::endl; \
        exit(1); \
    }

void TestAdd() {
    AddSubClass asc(1);
    TEST_ASSERT(asc.add(1) == 2);
    TEST_ASSERT(asc.add(-1) == 1);
    TEST_ASSERT(asc.add(-2) == -1);
    std::cout << "All Add tests passed!" << std::endl;
}

#endif // TESTS_H