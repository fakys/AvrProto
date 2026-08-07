#ifndef ARDUINO_PROTOMESSAGE_H
#define ARDUINO_PROTOMESSAGE_H

#include "main.h"
#include "AvrArray.h"
#include "ProtoBody.h"
#include "ProtoHeader.h"

class ProtoMessage {
private:
    ProtoHeader* header;
    ProtoBody* body;
public:
    ProtoMessage(ProtoHeader* header, ProtoBody* body) {
        this->header = header;
        this->body = body;
    };

    AvrArray<uint8_t>* toByte() {
        auto* byte_message = new AvrArray<uint8_t>();

        for (int i = 0; i < this->getHeader()->getSortContent()->getSize(); i++) {
            byte_message->merge((*this->getHeader()->getSortContent())[i]->getData());
        }

        for (int i = 0; i < this->getBody()->getSortContent()->getSize(); i++) {
            byte_message->merge((*this->getBody()->getSortContent())[i]->getData());
        }

        return byte_message;
    };

    ProtoHeader* getHeader() {
        return header;
    }

    ProtoBody* getBody() {
        return body;
    }

    ~ProtoMessage() {
        delete this->header;
        delete this->body;
    };
};

#endif
