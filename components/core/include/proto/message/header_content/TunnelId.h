#ifndef ARDUINO_TUNNELID_H
#define ARDUINO_TUNNELID_H

#include "MessageContentInterface.h"
#include "ArduProtoV1.h"

class TunnelId : public MessageContentInterface {
public:
    unsigned int getPositionIndex() override {
        return H_TUNNEL_ID_INDEX;
    }
    unsigned int getSize() override {
        return H_BYTE_FOR_TUNNEL_ID;
    }
};

#endif
