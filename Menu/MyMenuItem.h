#ifndef MYMENU_CPP_MYMENUITEM_H
#define MYMENU_CPP_MYMENUITEM_H

namespace DoublyLinkedList {
    class MyMenuItem {
    public:
        typedef int(*Func)();

        MyMenuItem(char *, Func);

        Func m_func{};
        char *m_item_name{};

        char *getName();

        void print();

        int run();
    };
}

#endif //MYMENU_CPP_MYMENUITEM_H
