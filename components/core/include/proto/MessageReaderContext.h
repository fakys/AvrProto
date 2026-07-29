//
// Created by fakys on 27.07.2026.
//

#ifndef ARDUINO_MESSAGEREADER_H
#define ARDUINO_MESSAGEREADER_H

#include "SenderInterface.h"
#include "ByteNumeric.h"
#include "ProtoMessage.h"

class MessageReaderContext {
private:
    bool error = false;
    bool messageReady = false;
    ProtoMessage* message = nullptr;
    SenderInterface* sender;
protected:
    bool fill_header = false;
public:
    MessageReaderContext(SenderInterface* sender) : sender(sender) {};

    //чтение сообщения где true = что сообщение готово
    bool readMessage(uint8_t byte);
    bool hasError();
    bool getMessageReady();
    ProtoMessage* getMessage();
};

#endif //ARDUINO_MESSAGEREADER_H
