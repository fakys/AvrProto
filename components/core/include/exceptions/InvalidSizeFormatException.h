//
// Created by fakys on 26.07.2026.
//

#ifndef ARDUINO_INVALIDSIZEFORMATEXCEPTION_H
#define ARDUINO_INVALIDSIZEFORMATEXCEPTION_H

#include "MainException.h"

class InvalidSizeFormatException : public MainException {
public:
    InvalidSizeFormatException(const unsigned int& code, const char* errorMessage): MainException(code, errorMessage) {}
};

#endif //ARDUINO_INVALIDSIZEFORMATEXCEPTION_H
