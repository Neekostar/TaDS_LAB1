#ifndef MYMENU_MYMENU_H
#define MYMENU_MYMENU_H

#include "MyMenuItem.h"
#include <cstddef>

namespace DoublyLinkedList {
    class MyMenu {
    public:
        MyMenu();

        MyMenu(char *, MyMenuItem *, size_t);

        int getSelect() const;

        bool isRun() const;

        char *getTitle();

        size_t getCount() const;

        MyMenuItem *getItems();

        void print();

        int runCommand();

        void setMenuPtr(int *ptr);

    private:
        int m_select{-1};
        size_t m_count{};
        bool m_running{};
        char *m_title{};
        MyMenuItem *m_items{};
        int *m_ptr = nullptr;
    };
}

#endif //MYMENU_CMENU_H
