#include <iostream>
#include "AddSubClass.h"

int main() {
    std::cout << "Hello, to the Github Demo!" << std::endl;

    AddSubClass asc(10);
    asc.add(5);

    std::cout << "Value: " << asc.get_value() << std::endl;

    return 0;
}