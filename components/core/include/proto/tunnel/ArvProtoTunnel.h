#ifndef ARDUINO_ARVPROTOTUNEL_H
#define ARDUINO_ARVPROTOTUNEL_H

#include "AvrArray.h"
#include "ArvProto.h"
#include "ProtoDevice.h"
#include "SenderInterface.h"

class ArvProtoTunnel {
    private:
        AvrArray<ProtoDevice*>* devices;
        uint8_t tunel_id;
        ArvProto* proto;
        SenderInterface* sender;
    public:
        ArvProtoTunnel(ArvProto* proto, SenderInterface* sender, uint8_t tunel_id);
        bool appendAppendDeviceInTunnel (ProtoDevice* device);
        ProtoDevice* getDeviceById(uint8_t device_id);
        uint8_t getTunelId();
        AvrArray<ProtoDevice*>* getAllDevices();
        SenderInterface* getSender();
        ArvProto* getProto();
        ~ArvProtoTunnel();
};

#endif
