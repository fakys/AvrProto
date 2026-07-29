//
// Created by fakys on 26.07.2026.
//

#ifndef ARDUINO_BODYSIZE_H
#define ARDUINO_BODYSIZE_H
#include "MessageContentInterface.h"
#include "ProtoMessage.h"
#include "ByteNumeric.h"

class BodySize : public MessageContentInterface {
protected:
    ByteNumeric* data;
public:
    BodySize() : MessageContentInterface() {
        this->data = new ByteNumeric(this->BodySize::getSize());
    }
    unsigned int getPositionIndex() override {
        return B_SIZE_INDEX;
    };
    unsigned int getSize() override {
        return B_BYTE_FOR_SIZE;
    };

    AvrArray<uint8_t>* getData() override {
        return this->data->getNumber();
    }

    void appendData (uint8_t byte) override {
        this->data->appendByte(byte);
    }

    bool validData(uint8_t byte) override {
        return !this->filled();
    };

    bool filled() override {
        return this->data->getNumber()->getSize() == this->data->getDischarge();
    };
};

#endif //ARDUINO_BODYSIZE_H
