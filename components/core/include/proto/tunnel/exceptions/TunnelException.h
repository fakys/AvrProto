//
// Created by fakys on 26.07.2026.
//

#ifndef ARDUINO_TUNNELEXCEPTION_H
#define ARDUINO_TUNNELEXCEPTION_H

#include "MainException.h"

class TunnelException : public MainException {
public:
    TunnelException(const unsigned int& code, const char* errorMessage): MainException(code, errorMessage) {}
};

#endif //ARDUINO_TUNNELEXCEPTION_H
