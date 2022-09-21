#include <iostream>
#include "Models/BidList.h"
#include "Menu/MyMenu.h"
#include "Menu/MyMenuItem.h"

using namespace LinkedList;

int addElSt() {
    return 2;
}

int addElEnd() {
    return 1;
}

int addElMid() {
    return 3;
}

int deleteNum() {
    return 4;
}

int deleteData() {
    return 5;
}

int print() {
    return 6;
}

int findEl() {
    return 7;
}

int empty() {
    return 8;
}

int solve() {
    return 9;
}

int del() {
    return 10;
}

int ex() {
    return 11;
}

void startProgramm(BidList list, MyMenu menu) {
    while (menu.runCommand()) {
        if (menu.getSelect() == print()) {
            list.printList();
        }
        if (menu.getSelect() == addElEnd()) {
            list.AddToEnd();
        }
        if (menu.getSelect() == addElMid()) {
            list.AddToMid();
        }
        if (menu.getSelect() == addElSt()) {
            list.AddToStart();
        }
        if (menu.getSelect() == deleteNum()) {
            list.DeleteElementNumber();
        }
        if (menu.getSelect() == deleteData()) {
            list.DeleteElementData();
        }
        if (menu.getSelect() == findEl()) {
            list.findElement();
        }
        if (menu.getSelect() == empty()) {
            list.printEmpty();
        }
        if (menu.getSelect() == solve()) {
            list.NotRepet();
        }
        if (menu.getSelect() == del()) {
            list.DeleteList();
        }
        if (menu.getSelect() == ex()) {
            exit(0);
        }
    }
}

#ifndef LAB1_STARTPROGRAM_H
#define LAB1_STARTPROGRAM_H

#endif //LAB1_STARTPROGRAM_H
