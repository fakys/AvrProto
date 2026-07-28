//
// Created by fakys on 27.07.2026.
//

#ifndef ARDUINO_SENDTMEOUTEXCEPTION_H
#define ARDUINO_SENDTMEOUTEXCEPTION_H

#include "MainException.h"

class SendTmeOutException : public MainException {
public:
    SendTmeOutException(const unsigned int& code, const char* errorMessage): MainException(code, errorMessage) {}
};

#endif //ARDUINO_SENDTMEOUTEXCEPTION_H
