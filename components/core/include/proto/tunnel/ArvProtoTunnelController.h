#ifndef ARDUINO_ARVPROTOTUNELCONTROLLER_H
#define ARDUINO_ARVPROTOTUNELCONTROLLER_H

#include "ArvProtoTunnel.h"
#include "AvrArray.h"
#include "SenderInterface.h"
#include "Singleton.h"

class ArvProtoTunnelController : public Singleton<ArvProtoTunnelController> {
    private:
        AvrArray<ArvProtoTunnel*>* tunnels;
    public:
        ArvProtoTunnelController() {
            tunnels = new AvrArray<ArvProtoTunnel*>();
        }
        //Для создания тунеля нам надо перадать протокол по которому мы передаем даныне и через какой интерфейс для отправки
        ArvProtoTunnel* createTunnel(ArvProto* proto, SenderInterface* sender);
        ArvProtoTunnel* getTunnelById(uint8_t tunel_id);
        bool hasTunnelById(uint8_t tunel_id);
        bool dropTunnelById(uint8_t tunel_id);
};

#endif
