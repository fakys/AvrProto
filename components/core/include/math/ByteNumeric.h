//
// Created by fakys on 29.07.2026.
//

#ifndef ARDUINO_BYTENUMERIC_H
#define ARDUINO_BYTENUMERIC_H
#include "AvrArray.h"
#include "errors_code.h"
#include "main.h"
#include "MaxDischarge.h"
#include "MaxNumericFromDischarge.h"

class ByteNumeric {
private:
    //Разряд числа в байтах где разряд получается путем discharge * 8
    unsigned int discharge = 1;

    AvrArray<uint8_t> *num;

public:
    ByteNumeric(unsigned int discharge) {
        if (discharge > MAX_DISCHARGE) {
            throw MaxDischarge{TOTAL_ERRORS, "max discharge error"};
        }
        this->discharge = discharge;
        this->num = new AvrArray<uint8_t>();
        this->num->setCapacity(this->discharge);
    }

    unsigned int getDischarge() {
        return this->discharge;
    }

    void appendByte(int byte) {
        if (this->num->getSize() >= this->discharge) {
            throw MaxNumericFromDischarge(TOTAL_ERRORS, "max numeric from discharge error");
        }

        for (unsigned int y = 0; y < this->discharge; y++) {
            this->num->push(byte, this->discharge - 1 - y);
        }
    }

    AvrArray<uint8_t> *getNumber() {
        return this->num;
    }

    void clear() {
        this->num->clear();
    }

    ~ByteNumeric() {
        delete this->num;
    }
};

#endif //ARDUINO_BYTENUMERIC_H
