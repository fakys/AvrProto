#ifndef ARDUINO_HEADERSIZE_H
#define ARDUINO_HEADERSIZE_H

#include "MessageContentInterface.h"
#include "proto.h"

class HeaderSize : public MessageContentInterface {
public:
    unsigned int getPositionIndex() override {
        return H_SIZE_INDEX;
    }

    unsigned int getSize() override {
        return H_BYTE_FOR_SIZE;
    }
};

#endif
