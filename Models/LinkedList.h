#ifndef LAB1_DOUBLE_LINKED_LIST_H
#define LAB1_DOUBLE_LINKED_LIST_H

namespace DoublyLinkedList {
    struct Node {
        char data;
        Node *next, *prev;
    };

    class LinkedList {
    private:
        Node *head, *tail;
        int lenList{};

        int findEl(char _data);

        LinkedList CopyList();

        void add(char new_data);

        void delete_(int num);

        bool isListEmpty();

    public:
        LinkedList();

        ~LinkedList();

        void printDoubleList();

        void printDoubleListInversive();

        void addToTheStart();

        void addToTheEnd();

        void addToTheMiddle();

        void outputFile();

        void inputFromFile();

        void DeleteElementNumber();

        void findElement();

        void DeleteElementData();

        void DeleteList();

        void NotRepeat();

        void checkForEmpty();

        void popLast();

        void popFirst();

        void getLength();
    };

}

#endif //LAB1_DOUBLE_LINKED_LIST_H
