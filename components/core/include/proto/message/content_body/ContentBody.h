//
// Created by fakys on 26.07.2026.
//

#ifndef ARDUINO_CONTENTBODY_H
#define ARDUINO_CONTENTBODY_H

#include "MessageContentInterface.h"
#include "proto.h"

class ContentBody : public MessageContentInterface {
public:
    unsigned int getPositionIndex() override {
        return B_CONTENT_INDEX;
    }

    unsigned int getSize() override {
        auto* size = (BodySize*)(*this->dependsContent)[B_SIZE_INDEX];

        //todo тут бы придумать универсальный метод
        return (unsigned int)((uint16_t)(*size->getData())[0] << 8 | (*size->getData())[1]);
    }

    bool validData(uint8_t byte) override {
        return !this->filled();
    };

    bool filled() override {
        return this->data->getSize() == this->getSize();
    };
};

#endif //ARDUINO_CONTENTBODY_H
