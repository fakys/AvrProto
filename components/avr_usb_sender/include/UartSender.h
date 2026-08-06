//
// Created by fakys on 27.07.2026.
//

#ifndef ARDUINO_AVRUSBSENDER_H
#define ARDUINO_AVRUSBSENDER_H
#include "SenderTransaction.h"
#include "Singleton.h"

class UartSender : public SenderInterface, public Singleton<UartSender> {
public:
    UartSender();
    bool sendMessage(uint8_t byte) override;
    uint8_t receiveMessage() override;
    bool bufferReadyReadData() override;
    bool bufferReadySendData() override;
    bool dataSuccessSend() override;
};

#endif //ARDUINO_AVRUSBSENDER_H
