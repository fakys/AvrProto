//
// Created by fakys on 29.07.2026.
//

#ifndef ARDUINO_MAXNUMERICFROMDISCHARGE_H
#define ARDUINO_MAXNUMERICFROMDISCHARGE_H

#include "MainException.h"

class MaxNumericFromDischarge : public MainException {
public:
    MaxNumericFromDischarge(const unsigned int& code, const char* errorMessage): MainException(code, errorMessage) {}
};

#endif //ARDUINO_MAXNUMERICFROMDISCHARGE_H
