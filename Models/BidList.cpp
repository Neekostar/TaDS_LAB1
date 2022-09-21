#include "BidList.h"
#include <iostream>

namespace LinkedList {
    BidList::BidList() {
        head = nullptr;
        tail = nullptr;
        lenList = 0;
    }

    void BidList::printList() {
        std::cout << "Список: ";
        Node *tmp = head;
        while (tmp != nullptr) {
            std::cout << tmp->data << " ";
            tmp = tmp->next;
        }
        std::cout << std::endl << std::endl;
    }

    void BidList::AddToEnd() {
        char _data{};
        std::cout << "Введите символ для добавления в список: ";
        std::cin >> _data;
        lenList++;
        Node *tmp = new Node;
        tmp->next = nullptr;
        tmp->data = _data;
        if (!isListEmpty()) {
            tmp->prev = tail;
            tail->next = tmp;
            tail = tmp;
        } else {
            tmp->prev = NULL;
            head = tail = tmp;
        }
    }

    void BidList::AddToStart() {
        char _data{};
        std::cout << "Введите символ для добавления в список: ";
        std::cin >> _data;
        lenList++;
        Node *tmp = new Node;
        tmp->data = _data;
        tmp->prev = nullptr;
        if (!isListEmpty()) {
            tmp->next = head;
            head->prev = tmp;
            head = tmp;
        } else {
            tmp->next = NULL;
            head = tail = tmp;
        }
    }

    void BidList::AddToMid() {
        char _data{};
        std::cout << "Введите символ для добавления в список: ";
        std::cin >> _data;
        Node *tmp = new Node;
        tmp->data = _data;
        Node *cyc = new Node;
        cyc = head;
        int position{};
        if (lenList > 2) {
            position = lenList / 2;
            for (int i = 0; i < position; i++) {
                cyc = cyc->next;
            }
            tmp->next = cyc->next;
            tmp->prev = cyc->prev;
            cyc->next = tmp;
            cyc = cyc->next;
            cyc->prev = tmp;
            lenList++;
        } else {
            std::cout << "Добавление в середину возможно при количестве элементов более двух!\n";
        }
    }

    void BidList::DeleteElementNumber() {
        int num{};
        printList();
        std::cout << "Пожалуйства, введите номер для удаления: ";
        std::cin >> num;
        if (lenList < num || num <= 0) {
            std::cout << "Введен неверный индекс. Удаление невозможно\n";

        } else {
            num--;
            Node *tmp = new Node;
            Node *tmp2 = new Node;
            Node *deleteTmp = new Node;
            Node *cyc = new Node;
            cyc = head;
            for (int i = 0; i < num; i++) {
                cyc = cyc->next;
            }
            deleteTmp = cyc;
            if (head != deleteTmp & tail != deleteTmp) {
                tmp = deleteTmp->next;
                tmp2 = deleteTmp->prev;
                tmp2->next = tmp;
                tmp->prev = tmp2;
            } else if (head == deleteTmp) {
                tmp = deleteTmp->next;
                head = tmp;
                tmp->prev = NULL;
            } else if (tail == deleteTmp) {
                tmp = deleteTmp->prev;
                tail = tmp;
                tmp->next = NULL;
            }
            std::cout << "Удаление успешно завершено!\n";
            lenList--;
        }

    }

    void BidList::delete_(int num) {
        if (lenList < num || num <= 0) {
            std::cout << "Введен неверный индекс. Удаление невозможно\n";

        } else {
            num--;
            Node *tmp = new Node;
            Node *tmp2 = new Node;
            Node *deleteTmp = new Node;
            Node *cyc = new Node;
            cyc = head;
            for (int i = 0; i < num; i++) {
                cyc = cyc->next;
            }
            deleteTmp = cyc;
            if (head != deleteTmp & tail != deleteTmp) {
                tmp = deleteTmp->next;
                tmp2 = deleteTmp->prev;
                tmp2->next = tmp;
                tmp->prev = tmp2;
            } else if (head == deleteTmp) {
                tmp = deleteTmp->next;
                head = tmp;
                tmp->prev = NULL;
            } else if (tail == deleteTmp) {
                tmp = deleteTmp->prev;
                tail = tmp;
                tmp->next = NULL;
            }
            std::cout << "Удаление успешно завершено!\n";
            lenList--;
        }
    }

    void BidList::DeleteElementData() {
        char _data{};
        std::cout << "Введите символ для удаления: ";
        std::cin >> _data;
        int numberOfDeleteElement = findEl(_data);
        delete_(numberOfDeleteElement);
    }

    void BidList::DeleteList() {
        if (!isListEmpty()) {
            Node *tmp = new Node;
            while (head != NULL) {
                tmp = head;
                head = head->next;
                delete[] tmp;
            }
            tail = NULL;
            lenList = 0;
            std::cout << "Список удален.\n";
        } else {
            std::cout << "Список пустой. Удаление невозможно\n";
        }

    }

    int BidList::findEl(char _data) {
        Node *cyc = new Node;
        int position = 1;
        cyc = head;
        bool flag = false;
        for (int i = 0; i < lenList; i++) {
            if (cyc->data == _data) {
                flag = true;
                break;
            } else {
                cyc = cyc->next;
                position++;
            }
        }
        if (!flag) {
            return -1;

        } else {
            return position;
        }

    }

    void BidList::findElement() {
        char _data{};
        std::cout << "Введите символ для поиска: ";
        std::cin >> _data;
        int result{};
        result = findEl(_data);
        if (result == -1) {
            std::cout << "Элемент не найден! Проверьте вводимые данные\n";
        } else {
            std::cout << "Элемент найден под номером " << result << " с данными: " << _data << "\n";
        }
    }

    bool BidList::isListEmpty() {
        if (head == NULL) {
            return true;
        }
        return false;
    }

    void BidList::printEmpty() {
        if (head == NULL) {
            std::cout << "Список пуст!!!\n";
        } else {
            std::cout << "Список не пуст!\n";
            printList();
        }
    }

    BidList BidList::CopyList() {
        BidList a;
        Node *tmp = new Node;
        tmp = head;
        for (int i = 0; i < lenList; i++) {
            a.add(tmp->data);
            tmp = tmp->next;
        }
        return a;
    }

    void BidList::add(char _data) {
        lenList++;
        Node *tmp = new Node;
        tmp->next = nullptr;
        tmp->data = _data;
        if (!isListEmpty()) {
            tmp->prev = tail;
            tail->next = tmp;
            tail = tmp;
        } else {
            tmp->prev = NULL;
            head = tail = tmp;
        }
    }

    void BidList::NotRepet() {
        BidList a = CopyList();
        Node *tmp = new Node;
        Node *tmp2 = new Node;
        int st{};
        tmp = a.head;
        std::cout << "Символы, которые входят в последовательность по одному разу: ";
        for (int i = 0; i < lenList; i++) {
            st = 0;
            if (tmp->data != '\0') {
                tmp2 = tmp->next;
                for (int j = i + 1; j < lenList; j++) {
                    if (tmp->data == tmp2->data) {
                        st = 1;
                        tmp2->data = '\0';
                    }
                    tmp2 = tmp2->next;
                }
                if (st == 0) {
                    std::cout << tmp->data << " ";
                }
            }
            tmp = tmp->next;
        }
        std::cout << std::endl;
    }
} // KVA