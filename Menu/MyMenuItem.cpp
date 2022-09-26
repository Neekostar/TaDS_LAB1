#include "MyMenuItem.h"
#include <iostream>

using namespace std;

namespace DoublyLinkedList {
    MyMenuItem::MyMenuItem(char *item_name, Func func) : m_item_name(item_name), m_func(func) {}

    char *MyMenuItem::getName() {
        return m_item_name;
    }

    void MyMenuItem::print() {
        std::cout << m_item_name;
    }

    int MyMenuItem::run() {
        return m_func();
    }
}