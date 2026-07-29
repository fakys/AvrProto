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

    //Хранит в себе уже сортированный контент
    AvrArray<MessageContentInterface*>* sortContent;
    public:
    ProtoHeader() {
        this->sortContent = new AvrArray<MessageContentInterface*>();

        this->header_size = new HeaderSize();
        this->sortContent->push(this->header_size, this->header_size->getPositionIndex());
        this->id_device_recipient = new IdDeviceRecipient();
        this->sortContent->push(this->id_device_recipient, this->id_device_recipient->getPositionIndex());
        this->tunnel_id = new TunnelId();
        this->sortContent->push(this->tunnel_id, this->tunnel_id->getPositionIndex());
        this->id_device_sender = new IdDeviceSender();
        this->sortContent->push(this->id_device_sender, this->id_device_sender->getPositionIndex());
        this->request_code = new RequestCode();
        this->sortContent->push(this->request_code, this->request_code->getPositionIndex());
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

    AvrArray<MessageContentInterface*>* getSortContent() {
        return this->sortContent;
    }
};

#endif
