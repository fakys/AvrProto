#ifndef ARDUINO_REQUESTCODE_H
#define ARDUINO_REQUESTCODE_H

#include "MessageContentInterface.h"

class RequestCode : public MessageContentInterface {
public:
    unsigned int getPositionIndex() override {
        return H_REQUEST_CODE_INDEX;
    }
    unsigned int getSize() override {
        return H_BYTE_FOR_REQUEST_CODE;
    }

    bool validData(uint8_t byte) override {
        //todo Проверять на все известные коды
        return !this->filled();
    };

    bool filled() override {
        return this->data->getSize() == this->getSize();
    };
};

#endif
