//
// Created by fakys on 27.07.2026.
//

#ifndef ARDUINO_MESSAGEREADER_H
#define ARDUINO_MESSAGEREADER_H

#include "SenderInterface.h"

class MessageReaderContext {
    private:
    ProtoMessage* message;
    SenderInterface* sender;
    public:
    MessageReaderContext(SenderInterface* sender) : sender(sender) {};

    //чтение сообщения где true = что сообщение готово
    bool readMessage(uint8_t byte);
    bool hasError();
    ProtoMessage* getMessage();
};

#endif //ARDUINO_MESSAGEREADER_H
