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

        int lenList{}; //вспомогательный метод определения длины списка

        int findEl(char searching_data); //вспомогательный метод поиска элемента

        LinkedList CopyList(); //копируем существующий список для решения задачи

        void add(char new_data); //вспомогательный метод добавления элемента

        void delete_(int num); //вспомогательный метод удаления элемента

        bool isListEmpty(); //вспомогательный метод определения наполненности списка

    public:
        LinkedList();

        ~LinkedList();

        void printDoubleList();

        void printDoubleListInversive();

        void addToTheStart();

        void addToTheEnd();

        void addToTheAnyPosition();

        void outputFile();

        void inputFromFile();

        void DeleteElementByPosition();

        void findElement();

        void DeleteElementByData();

        void DeleteList();

        void repeatingSymbols();

        void checkForEmpty();

        void popLast();

        void popFirst();

        void getLength();
    };

}

#endif //LAB1_DOUBLE_LINKED_LIST_H
