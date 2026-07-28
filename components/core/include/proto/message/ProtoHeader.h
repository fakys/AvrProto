#ifndef ARDUINO_PROTOHEADER_H
#define ARDUINO_PROTOHEADER_H
#include "HeaderSize.h"
#include "IdDeviceRecipient.h"
#include "IdDeviceSender.h"
#include "RequestCode.h"
#include "TunnelId.h"

class ProtoHeader {
    private:
    HeaderSize* header_size;
    IdDeviceRecipient* id_device_recipient;
    TunnelId* tunnel_id;
    IdDeviceSender* id_device_sender;
    RequestCode* request_code;

    public:
    ProtoHeader(HeaderSize* header_size, IdDeviceRecipient* id_device_recipient, TunnelId* tunnel_id, IdDeviceSender* id_device_sender, RequestCode* request_code) {
        this->header_size = header_size;
        this->id_device_recipient = id_device_recipient;
        this->tunnel_id = tunnel_id;
        this->id_device_sender = id_device_sender;
        this->request_code = request_code;
    };

    HeaderSize* getHeaderSize() {
        return header_size;
    }
    IdDeviceRecipient* getIdDeviceRecipient() {
        return id_device_recipient;
    }
    TunnelId* getTunnelId() {
        return tunnel_id;
    }
    IdDeviceSender* getIdDeviceSender() {
        return id_device_sender;
    }
    RequestCode* getRequestCode() {
        return request_code;
    }
};

#endif
