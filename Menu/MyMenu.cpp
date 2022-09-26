//
// Created by nekit on 17.09.2022.
//
#include "MyMenu.h"
#include <iostream>
#include <typeinfo>
#include "C:\\Users\\nekit\\CLionProjects\\TaDS_LAB1\\Models\\Errors.h"

namespace DoublyLinkedList {

    MyMenu::MyMenu(char *title, MyMenuItem *items, size_t count) : m_title(title), m_items(items), m_count(count) {}

    MyMenu::MyMenu() {};

    int MyMenu::getSelect() const {
        return m_select;
    }

    bool MyMenu::isRun() const {
        return m_running;
    }

    size_t MyMenu::getCount() const {
        return m_count;
    }

    char *MyMenu::getTitle() {
        return m_title;
    }

    MyMenuItem *MyMenu::getItems() {
        return m_items;
    }

    void MyMenu::print() {
        std::cout << m_title << "\n";
        for (size_t i{}; i < m_count; ++i) {
            std::cout << i + 1 << ". ";
            m_items[i].print();
            std::cout << std::endl;
        }
    }

    int MyMenu::runCommand() {
        print();
        std::cout << "\nВыберите пункт меню:\n ";
        std::cin >> m_select;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore();
            throw Errors{"String was entered. Enter only digit."};
        }
        if (m_select > m_count || m_select <= 0) {
            throw Errors{"Enter correct point of menu"};
        } else {
            return m_items[m_select - 1].run();
        }
    }

    void MyMenu::setMenuPtr(int *ptr) {
        m_ptr = ptr;
    }
}