#ifndef ARDUINO_PROTODEVICE_H
#define ARDUINO_PROTODEVICE_H
#include <cstdint>
#include "SendMessageDto.h"
#include "ArvProto.h"

class ProtoDevice {
    private:
        uint8_t device_id;
    public:
        ProtoDevice(uint8_t device_id);
        uint8_t getDeviceId();
};

#endif
