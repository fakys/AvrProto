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

    AvrArray<uint8_t>* toByte();

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
