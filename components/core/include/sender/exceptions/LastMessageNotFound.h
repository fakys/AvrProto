//
// Created by fakys on 27.07.2026.
//

#ifndef ARDUINO_LASTMESSAGENOTFOUND_H
#define ARDUINO_LASTMESSAGENOTFOUND_H
#include "MainException.h"

class LastMessageNotFound : public MainException {
    public:
    LastMessageNotFound(const unsigned int& code, const char* errorMessage): MainException(code, errorMessage) {}
};

#endif
