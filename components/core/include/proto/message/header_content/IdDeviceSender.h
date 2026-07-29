#ifndef ARDUINO_IDDEVICESENDER_H
#define ARDUINO_IDDEVICESENDER_H

#include "MessageContentInterface.h"

class IdDeviceSender : public MessageContentInterface {
public:
    unsigned int getPositionIndex() override {
        return H_ID_SENDER_INDEX;
    }
    unsigned int getSize() override {
        return H_BYTE_FOR_ID_SENDER;
    }

    bool validData(uint8_t byte) override {
        return !this->filled();
    };

    bool filled() override {
        return this->data->getSize() == this->getSize();
    };
};

#endif
