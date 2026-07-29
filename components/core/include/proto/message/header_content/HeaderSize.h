#ifndef ARDUINO_HEADERSIZE_H
#define ARDUINO_HEADERSIZE_H

#include "MessageContentInterface.h"
#include "proto.h"
#include "ByteNumeric.h"

class HeaderSize : public MessageContentInterface {
protected:
    ByteNumeric* data;
public:
    HeaderSize() : MessageContentInterface() {
        this->data = new ByteNumeric(this->HeaderSize::getSize());
    }

    unsigned int getPositionIndex() override {
        return H_SIZE_INDEX;
    }

    AvrArray<uint8_t>* getData() override {
        return this->data->getNumber();
    }

    void appendData (uint8_t byte) override {
        this->data->appendByte(byte);
    }

    unsigned int getSize() override {
        return H_BYTE_FOR_SIZE;
    }

    bool validData(uint8_t byte) override {
        return !this->filled();
    };

    bool filled() override {
        return this->data->getNumber()->getSize() == this->data->getDischarge();
    };
};

#endif
