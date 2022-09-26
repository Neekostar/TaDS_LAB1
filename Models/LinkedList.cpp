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
        std::cout << "Двусвязный список: ";
        Node *temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl << std::endl;
    }

    void LinkedList::printDoubleListInversive() {
        std::cout << "Двусвязный список в обратном порядке: " << std::endl;
        Node *temp = tail;
        while (temp != nullptr) {
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
        std::cout << "Элемент успешно добавлен в список\n" << std::endl;
        printDoubleList();
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
        std::cout << "Элемент успешно добавлен в список\n" << std::endl;
        printDoubleList();
    }

    void LinkedList::addToTheAnyPosition() {
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
        if (index >= 0 && index <= lenList || isListEmpty()) {
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
                std::cout << "Элемент успешно добавлен в список\n" << std::endl;
                printDoubleList();
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
                std::cout << "Элемент успешно добавлен в список\n" << std::endl;
                printDoubleList();
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
            std::cout << "Элемент успешно добавлен в список\n" << std::endl;
            printDoubleList();
        } else {
            throw Errors{"Incorrect index"};
        }

    }


    void LinkedList::DeleteElementByPosition() {
        int index{};
        printDoubleList();
        std::cout << "Пожалуйства, введите индекс элемента для удаления: ";
        std::cin >> index;
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
            std::cout << "Элемент успешно удален\n" << std::endl;
            printDoubleList();
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

    void LinkedList::DeleteElementByData() {
        char deletingData{};
        std::string data{};
        std::cout << "Введите символ для удаления:\n ";
        std::cin >> data;
        if (data.length() > 1) {
            throw Errors{"Enter only one symbol"};
        } else {
            deletingData = data[0];
        }
        int numberOfDeleteElement = findEl(deletingData);
        delete_(numberOfDeleteElement);
        std::cout << "Элемент успешно удален\n" << std::endl;
        printDoubleList();
    }

    void LinkedList::getLength() {
        std::cout << "Длина вашего списка: " << lenList << std::endl;
        printDoubleList();
    }

    void LinkedList::DeleteList() {
        if (!isListEmpty()) {
            Node *tmp = new Node;
            while (head != nullptr) {
                tmp = head;
                head = head->next;
                delete[] tmp;
            }
            tail = nullptr;
            lenList = 0;
            std::cout << "Список удален.\n";
        } else {
            throw Errors{"List is deleted. Couldn't delete"};
        }

    }

    int LinkedList::findEl(char searching_data) {
        Node *runOnElements = new Node;
        int position = 1;
        runOnElements = head;
        bool flag = false;
        for (int i = 0; i < lenList; i++) {
            if (runOnElements->data == searching_data) {
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
        std::cout << "Введите символ для поиска:\n ";
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
        if (head == nullptr) {
            return true;
        }
        return false;
    }

    void LinkedList::checkForEmpty() {
        if (head == nullptr) {
            throw Errors{"List is empty"};
        } else {
            std::cout << "В списке есть элементы!\n";
            printDoubleList();
        }
    }

    LinkedList LinkedList::CopyList() {
        LinkedList list;
        Node *temp = new Node;
        temp = head;
        for (int i = 0; i < lenList; i++) {
            list.add(temp->data);
            temp = temp->next;
        }
        return list;
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

    void LinkedList::repeatingSymbols() {
        LinkedList list = CopyList();
        Node *temp1 = new Node;
        Node *temp2 = new Node;
        int checkingCondition{};
        temp1 = list.head;
        std::cout << "Символы, которые повторяются в последовательности: ";
        for (int i = 0; i < lenList; i++) {
            checkingCondition = 0;
            if (temp1->data != '\0') {
                temp2 = temp1->next;
                for (int j = i + 1; j < lenList; j++) {
                    if (temp1->data == temp2->data) {
                        checkingCondition = 1;
                        temp2->data = '\0';
                    }
                    temp2 = temp2->next;
                }
                if (checkingCondition != 0) {
                    std::cout << temp1->data << " ";
                }
            }
            temp1 = temp1->next;
        }
        std::cout << std::endl;
    }

    void LinkedList::outputFile() {
        std::ofstream fout;
        fout.open("C:\\Users\\nekit\\CLionProjects\\TaDS_LAB1\\Output.txt", std::ios::out);
        if (fout.is_open()) {
            Node *node = head;
            for (int i = 0; i < lenList; ++i) {
                fout << node->data << " ";
                node = node->next;
            }
            fout.close();
            std::cout << "Запись в файл завершена!" << std::endl;
        } else {
            throw Errors{"File didn't open"};
        }
    }

    void LinkedList::inputFromFile() {
        std::ifstream in;
        std::string line;
        char temp;
        DeleteList();
        in.open("C:\\Users\\nekit\\CLionProjects\\TaDS_LAB1\\Input.txt", std::ios::in);
        if (in.is_open()) {
            while (in.get(temp) && !in.eof()) {
                if (std::isdigit(temp) || std::isalpha(temp)) {
                    add(temp);
                }
            }
            in.close();
            std::cout << "Чтение файла завершено!" << std::endl;
            printDoubleList();
        } else {
            throw Errors{"File didn't open"};
        }
    }

}