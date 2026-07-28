//
// Created by fakys on 26.07.2026.
//

#ifndef ARDUINO_PROTOTRANSACTIONS_H
#define ARDUINO_PROTOTRANSACTIONS_H

#include "AvrArray.h"
#include "SenderInterface.h"
#include "ProtoDevice.h"

class SenderTransaction {
    private:
        SenderInterface* sender;
        ProtoDevice* device;
        ArvProtoTunnel* tunnel;
        ProtoMessage* lastSenderMessage;
    public:
        SenderTransaction(SenderInterface* sender, ProtoDevice* device, ArvProtoTunnel* tunnel);
        //Метод отправляет данные
        bool sendMessage(ProtoMessage* message);
        ProtoMessage* waitingResponse();
};

#endif //ARDUINO_PROTOTRANSACTIONS_H
