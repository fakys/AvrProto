//
// Created by fakys on 29.07.2026.
//

#ifndef ARDUINO_MAXDISCHARGE_H
#define ARDUINO_MAXDISCHARGE_H
#include "MainException.h"

class MaxDischarge : public MainException {
public:
    MaxDischarge(const unsigned int& code, const char* errorMessage): MainException(code, errorMessage) {}
};
#endif //ARDUINO_MAXDISCHARGE_H
