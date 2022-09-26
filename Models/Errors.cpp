//
// Created by nekit on 25.09.2022.
//

#include "Errors.h"
#include <iostream>
#include <fstream>
#include <chrono>

namespace DoublyLinkedList {
    const char *Errors::getError() const {
        return currentError.c_str();
    }

    Errors::Errors(std::string error) {
        currentError = error;
        writeErrorsIntoFile();
    }

    void Errors::writeErrorsIntoFile() {
        std::fstream file;
        auto now = std::chrono::system_clock::now();
        std::time_t end_time = std::chrono::system_clock::to_time_t(now);
        file.open("C:\\Users\\nekit\\CLionProjects\\TaDS_LAB1\\Errors.txt", std::ios::app);
        file << "WARNING: ERROR! " << currentError.c_str() << "|" << std::ctime(&end_time);
        file.close();
    }
}