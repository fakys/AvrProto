#ifndef ARDUINO_IDDEVICERECIPIENT_H
#define ARDUINO_IDDEVICERECIPIENT_H

#include "ArduProtoV1.h"
#include "MessageContentInterface.h"

class IdDeviceRecipient : public MessageContentInterface {
public:
    unsigned int getPositionIndex() override {
        return H_ID_RECIPIENT_INDEX;
    }
    unsigned int getSize() override {
        return H_BYTE_FOR_ID_RECIPIENT;
    }
};

#endif
