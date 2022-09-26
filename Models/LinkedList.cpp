#include "LinkedList.h"
#include <iostream>
#include <fstream>
#include "Errors.h"
#include <cstring>
#include <string>
#include <limits>
#include <cstdlib>

namespace DoublyLinkedList {
    LinkedList::LinkedList() {
        head = nullptr;
        tail = nullptr;
        lenList = 0;
    }

    LinkedList::~LinkedList() {
        while (head) {
            tail = head->next;
            delete head;
            head = tail;
        }
        lenList = 0;
    }

    void LinkedList::printDoubleList() {
        std::cout << "Двусвязный спсиок: ";
        Node *temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl << std::endl;
    }

    void LinkedList::printDoubleListInversive() {
        std::cout << "Список в обратном переборе: " << std::endl;
        Node *temp = tail;
        while (temp != NULL) {
            std::cout << temp->data << " ";
            temp = temp->prev;
        }
        std::cout << std::endl << std::endl;
    }

    void LinkedList::addToTheEnd() {
        std::string data{};
        char new_data{};
        std::cout << "Введите символ для добавления в список: ";
        std::cin >> data;
        if (data.length() > 1) {
            throw Errors{"Enter only one symbol"};
        } else {
            new_data = data[0];
        }
        lenList++;
        Node *temp = new Node;
//        temp->next = nullptr;
//        temp->data = new_data;
//        if (!isListEmpty()) {
//            temp->prev = tail;
//            tail->next = temp;
//            tail = temp;
//        } else {
//            temp->prev = NULL;
//            head = tail = temp;
//        }
        temp->data = new_data;
        if (isListEmpty()) {
            temp->prev = nullptr;
            head = temp;
        } else {
            tail->next = temp;
            temp->prev = tail;
        }
        temp->next = nullptr;
        tail = temp;
    }

    void LinkedList::addToTheStart() {
        char new_data{};
        std::string data{};
        std::cout << "Введите символ для добавления в список: ";
        std::cin >> data;
        if (data.length() > 1) {
            throw Errors{"Enter only one symbol"};
        } else {
            new_data = data[0];
        }
        lenList++;
        Node *temp = new Node;
        temp->data = new_data;
        temp->prev = nullptr;
        if (!isListEmpty()) {
            temp->next = head;
            head->prev = temp;
            head = temp;
        } else {
            temp->next = nullptr;
            head = tail = temp;
        }
    }

    void LinkedList::addToTheMiddle() {
//        char new_data{};
//        std::cout << "Введите символ для добавления в список: ";
//        std::cin >> new_data;
//        Node *tmp = new Node;
//        tmp->data = new_data;
//        Node *cyc = new Node;
//        cyc = head;
//        int position{};
//        if (lenList > 2) {
//            position = lenList / 2;
//            for (int i = 0; i < position; i++) {
//                cyc = cyc->next;
//            }
//            tmp->next = cyc->next;
//            tmp->prev = cyc->prev;
//            cyc->next = tmp;
//            cyc = cyc->next;
//            cyc->prev = tmp;
//            lenList++;
//        } else {
//            std::cout << "Добавление в середину возможно при количестве элементов более двух!\n";
//        }
        int index{};
        char new_data{};
        std::string data{};
        std::cout << "Введите позицию для добавления нового элемента" << std::endl;
        std::cin >> index;
        std::cout << "Введите значение нового элемента" << std::endl;
        std::cin >> data;
        if (data.length() > 1) {
            throw Errors{"Enter only one symbol"};
        } else {
            new_data = data[0];
        }
        if (index >= 0 && index < lenList || isListEmpty()) {
            if (index == 0) {
                Node *temp = new Node;
                temp->data = new_data;
                temp->prev = nullptr;
                if (!isListEmpty()) {
                    temp->next = head;
                    head->prev = temp;
                    head = temp;
                } else {
                    temp->next = nullptr;
                    head = tail = temp;
                }
                return;
            }
            if (index == lenList) {
                Node *temp = new Node;
                temp->data = new_data;
                if (isListEmpty()) {
                    temp->prev = nullptr;
                    head = temp;
                } else {
                    tail->next = temp;
                    temp->prev = tail;
                }
                temp->next = nullptr;
                tail = temp;
                return;

            }
            Node *left = head;
            for (int i = 0; i < index - 1; ++i) {
                left = left->next;

            }
            Node *right = left->next;
            Node *temp = new Node;
            temp->next = right;
            temp->prev = left;
            left->next = temp;
            right->prev = temp;
            temp->data = new_data;
            lenList++;
        } else {
            throw Errors{"Incorrect index"};
        }

    }


    void LinkedList::DeleteElementNumber() {
        int index{};
        printDoubleList();
        std::cout << "Пожалуйства, введите индекс элемента для удаления: ";
        std::cin >> index;
//        if (lenList < index || index <= 0) {
//            throw Errors{"Invalid delete index"};
//
//        } else {
//            index--;
//            Node *tmp = new Node;
//            Node *tmp2 = new Node;
//            Node *deleteTmp = new Node;
//            Node *cyc = new Node;
//            cyc = head;
//            for (int i = 0; i < index; i++) {
//                cyc = cyc->next;
//            }
//            deleteTmp = cyc;
//            if (head != deleteTmp & tail != deleteTmp) {
//                tmp = deleteTmp->next;
//                tmp2 = deleteTmp->prev;
//                tmp2->next = tmp;
//                tmp->prev = tmp2;
//            } else if (head == deleteTmp) {
//                tmp = deleteTmp->next;
//                head = tmp;
//                tmp->prev = NULL;
//            } else if (tail == deleteTmp) {
//                tmp = deleteTmp->prev;
//                tail = tmp;
//                tmp->next = NULL;
//            }
//            std::cout << "Удаление успешно завершено!\n";
//            lenList--;
//        }
        if (index >= 0 && index < lenList) {
            if (isListEmpty()) {
                throw Errors{"List is empty. Couldn't delete element"};
            }
            if (lenList == 1) {
                delete head;
                head = nullptr;
                tail = head;
            } else if (index == 0) {
                popFirst();
            } else if (index == lenList - 1) {
                popLast();
            } else {
                Node *left = head;
                for (int i = 0; i < index - 1; ++i) {
                    left = left->next;
                }
                Node *right = left->next->next;
                left->next = right;
                right->prev = left;
            }
            lenList--;
        } else {
            throw Errors{"Invalid index. Select correct index"};
        }

    }

    void LinkedList::popLast() {
        tail = tail->prev;
        tail->next = nullptr;
    }

    void LinkedList::popFirst() {
        head = head->next;
        tail->next = nullptr;
    }

    void LinkedList::delete_(int num) {
        if (lenList < num || num < 0) {
            throw Errors{"Invalid symbol when deleting by value"};

        } else {
            num--;
            Node *temp1 = new Node;
            Node *temp2 = new Node;
            Node *tempForDelete = new Node;
            Node *runOnElements = new Node;
            runOnElements = head;
            for (int i = 0; i < num; i++) {
                runOnElements = runOnElements->next;
            }
            tempForDelete = runOnElements;
            if (head != tempForDelete & tail != tempForDelete) {
                temp1 = tempForDelete->next;
                temp2 = tempForDelete->prev;
                temp2->next = temp1;
                temp1->prev = temp2;
            } else if (head == tempForDelete) {
                temp1 = tempForDelete->next;
                head = temp1;
                temp1->prev = nullptr;
            } else if (tail == tempForDelete) {
                temp1 = tempForDelete->prev;
                tail = temp1;
                temp1->next = nullptr;
            }
            std::cout << "Удаление успешно завершено!\n";
            lenList--;
        }
    }

    void LinkedList::DeleteElementData() {
        char deletingData{};
        std::string data{};
        std::cout << "Введите символ для удаления: ";
        std::cin >> data;
        if (data.length() > 1) {
            throw Errors{"Enter only one symbol"};
        } else {
            deletingData = data[0];
        }
        int numberOfDeleteElement = findEl(deletingData);
        delete_(numberOfDeleteElement);
    }

    void LinkedList::getLength() {
        std::cout << "Длина вашего списка: " << lenList << std::endl;
    }

    void LinkedList::DeleteList() {
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

    int LinkedList::findEl(char _data) {
        Node *runOnElements = new Node;
        int position = 1;
        runOnElements = head;
        bool flag = false;
        for (int i = 0; i < lenList; i++) {
            if (runOnElements->data == _data) {
                flag = true;
                break;
            } else {
                runOnElements = runOnElements->next;
                position++;
            }
        }
        if (!flag) {
            return -1;

        } else {
            return position;
        }

    }

    void LinkedList::findElement() {
        char searchingData{};
        std::string data{};
        std::cout << "Введите символ для поиска: ";
        std::cin >> data;
        if (data.length() > 1) {
            throw Errors{"Enter only one symbol"};
        } else {
            searchingData = data[0];
        }
        int result{};
        result = findEl(searchingData);
        if (result == -1) {
            throw Errors{"Element not found when searching"};
        } else {
            std::cout << "Элемент " << searchingData << " найден под номером " << result << "\n";
        }
    }

    bool LinkedList::isListEmpty() {
        if (head == NULL) {
            return true;
        }
        return false;
    }

    void LinkedList::checkForEmpty() {
        if (head == nullptr) {
            throw Errors{"List empty"};
        } else {
            std::cout << "В списке есть элементы!\n";
            printDoubleList();
        }
    }

    LinkedList LinkedList::CopyList() {
        LinkedList a;
        Node *tmp = new Node;
        tmp = head;
        for (int i = 0; i < lenList; i++) {
            a.add(tmp->data);
            tmp = tmp->next;
        }
        return a;
    }

    void LinkedList::add(char new_data) {
        lenList++;
        Node *tmp = new Node;
        tmp->next = nullptr;
        tmp->data = new_data;
        if (!isListEmpty()) {
            tmp->prev = tail;
            tail->next = tmp;
            tail = tmp;
        } else {
            tmp->prev = nullptr;
            head = tail = tmp;
        }
    }

    void LinkedList::NotRepeat() {
        LinkedList a = CopyList();
        Node *temp = new Node;
        Node *temp2 = new Node;
        int st{};
        temp = a.head;
        std::cout << "Символы, которые входят в последовательность по одному разу: ";
        for (int i = 0; i < lenList; i++) {
            st = 0;
            if (temp->data != '\0') {
                temp2 = temp->next;
                for (int j = i + 1; j < lenList; j++) {
                    if (temp->data == temp2->data) {
                        st = 1;
                        temp2->data = '\0';
                    }
                    temp2 = temp2->next;
                }
                if (st != 0) {
                    std::cout << temp->data << " ";
                }
            }
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void LinkedList::outputFile() {
        std::ofstream fout;
        fout.open("C:\\Users\\nekit\\CLionProjects\\TaDS_LAB1\\Output.txt", std::ios::out);
        Node *node = head;
        for (int i = 0; i < lenList; ++i) {
            fout << node->data << " ";
            node = node->next;
        }
        fout.close();
        std::cout << "Запись в файл завершена!" << std::endl;
    }

    void LinkedList::inputFromFile() {
        std::ifstream in;
        std::string line;
        char temp;
        in.open("C:\\Users\\nekit\\CLionProjects\\TaDS_LAB1\\Input.txt", std::ios::in);
        while (in.get(temp) && !in.eof()) {
            if (std::isdigit(temp) || std::isalpha(temp)) {
                add(temp);
            }
        }
        in.close();
        std::cout << "Чтение файла завершено!" << std::endl;
        printDoubleList();
    }

}