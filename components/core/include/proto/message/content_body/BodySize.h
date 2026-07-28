//
// Created by fakys on 26.07.2026.
//

#ifndef ARDUINO_BODYSIZE_H
#define ARDUINO_BODYSIZE_H
#include "MessageContentInterface.h"
#include "ProtoMessage.h"
#include "proto.h"

class BodySize : public MessageContentInterface {
    public:
    BodySize () : MessageContentInterface () {

    }
    unsigned int getPositionIndex() override {
        return B_SIZE_INDEX;
    };
    unsigned int getSize() override {
        return B_BYTE_FOR_SIZE;
    };
};

#endif //ARDUINO_BODYSIZE_H
