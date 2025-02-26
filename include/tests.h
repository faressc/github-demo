#ifndef TESTS_H
#define TESTS_H

#include <iostream>
#include <cassert>
#include "AddSubClass.h"

void TestAdd() {
    AddSubClass asc(1);
    assert(asc.add(1) == 2);
    assert(asc.add(-1) == 1);
    assert(asc.add(-2) == -1);
    assert(asc.add(-2) == -1);
    std::cout << "All Add tests passed!" << std::endl;
}

#endif // TESTS_H