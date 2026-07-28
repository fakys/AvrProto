#ifndef ARDUINO_IDDEVICESENDER_H
#define ARDUINO_IDDEVICESENDER_H

#include "ArduProtoV1.h"
#include "MessageContentInterface.h"

class IdDeviceSender : public MessageContentInterface {
public:
    unsigned int getPositionIndex() override {
        return H_ID_SENDER_INDEX;
    }
    unsigned int getSize() override {
        return H_BYTE_FOR_ID_SENDER;
    }
};

#endif
