#ifndef INVALIDSIZEFORMATEXCEPTION_H
#define INVALIDSIZEFORMATEXCEPTION_H
#include "MainException.h"


class InvalidSizeFormatException  : public MainException {
public:
    InvalidSizeFormatException(const unsigned int& code, const char* errorMessage): MainException(code, errorMessage) {}
};

#endif