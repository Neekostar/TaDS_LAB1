#ifndef LAB1_BIDLIST_H
#define LAB1_BIDLIST_H

namespace LinkedList {
    struct Node {
        char data;
        Node *next;
        Node *prev;
    };

    class BidList {
    private:
        Node *head;
        Node *tail;
        int lenList{};

        int findEl(char _data);

        BidList CopyList();

        void add(char _data);

        void delete_(int num);

        bool isListEmpty();

    public:
        BidList();

        void printList();

        void AddToStart();

        void AddToEnd();

        void AddToMid();

        void DeleteElementNumber();

        void findElement();

        void DeleteElementData();

        void DeleteList();

        void NotRepet();

        void printEmpty();
    };

} // KVA

#endif //LAB1_BIDLIST_H
