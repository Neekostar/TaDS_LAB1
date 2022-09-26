#include <iostream>
#include "Models/LinkedList.h"
#include "Menu/MyMenu.h"
#include "Menu/MyMenuItem.h"
#include "Models/Errors.h"
#include <cstdlib>

using namespace DoublyLinkedList;

const int pointsOfMenu = 15;

int addEnd() {
    return 1;
}

int addStart() {
    return 2;
}

int addMiddle() {
    return 3;
}

int deletePosition() {
    return 4;
}

int deleteValue() {
    return 5;
}

int print() {
    return 6;
}

int printReverse() {
    return 7;
}

int findElement() {
    return 8;
}

int checkEmpty() {
    return 9;
}

int repeatingValues() {
    return 10;
}

int del() {
    return 11;
}

int input_file() {
    return 12;
}

int output_file() {
    return 13;
}

int len() {
    return 14;
}

int exitProgram() {
    return 15;
}

void startProgramm(LinkedList list, MyMenu menu) {
    try {
        while (menu.runCommand()) {
            if (menu.getSelect() == print()) {
                list.printDoubleList();
            }
            if (menu.getSelect() == printReverse()) {
                list.printDoubleListInversive();
            }
            if (menu.getSelect() == addEnd()) {
                list.addToTheEnd();
            }
            if (menu.getSelect() == addMiddle()) {
                list.addToTheMiddle();
            }
            if (menu.getSelect() == addStart()) {
                list.addToTheStart();
            }
            if (menu.getSelect() == deletePosition()) {
                list.DeleteElementNumber();
            }
            if (menu.getSelect() == deleteValue()) {
                list.DeleteElementData();
            }
            if (menu.getSelect() == findElement()) {
                list.findElement();
            }
            if (menu.getSelect() == checkEmpty()) {
                list.checkForEmpty();
            }
            if (menu.getSelect() == repeatingValues()) {
                list.NotRepeat();
            }
            if (menu.getSelect() == del()) {
                list.DeleteList();
            }
            if (menu.getSelect() == exitProgram()) {
                exit(0);
            }
            if (menu.getSelect() == output_file()) {
                list.outputFile();
            }
            if (menu.getSelect() == input_file()) {
                list.inputFromFile();
            }
            if (menu.getSelect() == len()) {
                list.getLength();
            }
        }

    } catch (const Errors &exception) {
        std::cout << "Error: " << exception.getError() << std::endl;
        startProgramm(list, menu);
    }
}

int main() {
    system("chcp 65001");

    LinkedList list;
    MyMenuItem items[pointsOfMenu]{
            MyMenuItem{"Добавить элемент в конец", addEnd},
            MyMenuItem{"Добавить элемент в начало", addStart},
            MyMenuItem{"Добавить элемент в середину", addMiddle},
            MyMenuItem{"Удалить элемент по номеру", deletePosition},
            MyMenuItem{"Удалить элемент по значению", deleteValue},
            MyMenuItem{"Вывести список на экран", print},
            MyMenuItem{"Вывести список на экран в обратном порядке", printReverse},
            MyMenuItem{"Поиск по значению", findElement},
            MyMenuItem{"Проверка на пустоту списка", checkEmpty},
            MyMenuItem{"Поиск неповторяющихся символов", repeatingValues},
            MyMenuItem{"Удаление списка", del},
            MyMenuItem{"Просмотр файла с данными", input_file},
            MyMenuItem{"Запись в файл", output_file},
            MyMenuItem{"Узнать длину списка", len},
            MyMenuItem{"Выход из программы", exitProgram}
    };
    MyMenu menu("Меню двусвязного списка", items, pointsOfMenu);
    startProgramm(list, menu);
    return 0;
}
