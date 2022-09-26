//
// Created by nekit on 25.09.2022.
//

#ifndef TADS_LAB1_ERRORS_H
#define TADS_LAB1_ERRORS_H

#include <string>
#include <string_view>

namespace DoublyLinkedList {
    class Errors {
    public:
        Errors(std::string error);

        const char *getError() const;

    private:
        void writeErrorsIntoFile();

        std::string currentError;
    };
}
#endif //TADS_LAB1_ERRORS_H
