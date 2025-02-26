#ifndef ADDSUBCLASS_H
#define ADDSUBCLASS_H

#include <iostream>

class AddSubClass {
public:
    AddSubClass() = delete;
    AddSubClass(int a) {
        m_value = a;
        std::cout << "AddSubClass object created with value: " << a << std::endl;
    }
    ~AddSubClass() = default;

    int add(int b) {
        m_value += b;
        return m_value;
    }

    int get_value() {
        return m_value;
    }

    void set_value(int value) {
        m_value = value;
    }

    void clear_value() {
        m_value = 0;
    }

private:
    int m_value;
};

#endif // ADDSUBCLASS_H