#ifndef ARDUINO_REQUESTCODE_H
#define ARDUINO_REQUESTCODE_H

#include "ArduProtoV1.h"
#include "MessageContentInterface.h"

class RequestCode : public MessageContentInterface {
public:
    unsigned int getPositionIndex() override {
        return H_REQUEST_CODE_INDEX;
    }
    unsigned int getSize() override {
        return H_BYTE_FOR_REQUEST_CODE;
    }
};

#endif
