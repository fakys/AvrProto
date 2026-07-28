#ifndef ARDUINO_SENDMESSAGEDTO_H
#define ARDUINO_SENDMESSAGEDTO_H
#include "main.h"
#include "AvrArray.h"

class SendMessageDto {
    private:
        AvrArray<uint8_t>* message;
        uint8_t id_sender;
        uint8_t id_recipient;
        uint8_t tunnel_id;
        uint8_t code;
    public:
    SendMessageDto(uint8_t id_sender, uint8_t code=0, AvrArray<uint8_t>* message = nullptr, uint8_t id_recipient = 0, uint8_t tunnel_id = 0) {
        this->tunnel_id = tunnel_id;
        this->code = code;
        this->id_recipient = id_recipient;
        this->message = message;
    }

    AvrArray<uint8_t>* getMessage() {
        return message;
    }

    uint8_t getIdSender() {
        return id_sender;
    }

    uint8_t getIdRecipient() {
        return id_recipient;
    }

    uint8_t getTunnelId() {
        return tunnel_id;
    }
};

#endif
