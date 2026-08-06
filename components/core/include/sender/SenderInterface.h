//
// Created by fakys on 26.07.2026.
//

#ifndef ARDUINO_SENDERINTERFACE_H
#define ARDUINO_SENDERINTERFACE_H
#include "Singleton.h"
#include "main.h"

class SenderInterface : public Singleton<SenderInterface> {
    public:
    virtual bool sendMessage(uint8_t byte);
    virtual uint8_t receiveMessage();
    //Буфер готов к чтению наддных
    virtual bool bufferReadyReadData();
    //Буфер готов к отправки данных
    virtual bool bufferReadySendData();
    //Данные успешно отправленные от приняты получателем
    virtual bool dataSuccessSend();
};

#endif //ARDUINO_SENDERINTERFACE_H
