//
// Created by fakys on 27.07.2026.
//

#include "ArvProtoTunnel.h"

#include "SenderTransaction.h"
#include "SendTmeOutException.h"

ArvProtoTunnel::ArvProtoTunnel(ArvProto* proto, SenderInterface* sender, uint8_t tunel_id) {
    this->proto = proto;
    this->sender = sender;
    this->tunel_id = tunel_id;
}

bool ArvProtoTunnel::appendAppendDeviceInTunnel(ProtoDevice* device) {
    ProtoMessage* msg = nullptr;
    SenderTransaction* transaction = nullptr;
    ProtoMessage* responseInvite = nullptr;
    try {
        //Приглашение в тунель
        msg = this->proto->messageToProto(new SendMessageDto(SENDER_ID, INVITE_IN_TUNNEL, nullptr, device->getDeviceId(), tunel_id));
        transaction = new SenderTransaction(this->sender, device, this);
        bool sendInvite = transaction->sendMessage(msg); //Отправляем приглашение
        if (sendInvite) {
            //Получаем ответ на приглашение
            responseInvite = transaction->waitingResponse();
            if (responseInvite && responseInvite->getHeader()->getRequestCode()->getData()->last() == ACCEPT_TUNNEL_INVITE) {
                //Приглашение принято
                this->devices->push(device);

                delete msg;
                msg = nullptr;
                delete transaction;
                transaction = nullptr;
                delete responseInvite;
                responseInvite = nullptr;

                return true;
            }
        }
    } catch (SendTmeOutException& exp) {

    }

    delete msg;
    msg = nullptr;
    delete transaction;
    transaction = nullptr;
    delete responseInvite;
    responseInvite = nullptr;

    return false;
}

ProtoDevice* ArvProtoTunnel::getDeviceById(uint8_t device_id) {
    for (uint8_t i = 0; i < this->devices->getSize(); i++) {
        if ((*this->devices)[i]->getDeviceId() == device_id) {
            return (*this->devices)[i];
        }
    }
    return nullptr;
}

uint8_t ArvProtoTunnel::getTunelId() {
    return this->tunel_id;
}

AvrArray<ProtoDevice*>* ArvProtoTunnel::getAllDevices() {
    return this->devices;
}

SenderInterface* ArvProtoTunnel::getSender() {
    return this->sender;
}

ArvProto* ArvProtoTunnel::getProto() {
    return this->proto;
}

ArvProtoTunnel::~ArvProtoTunnel() {
    delete this->devices;
    this->devices = nullptr;
    this->sender = nullptr;
    this->proto = nullptr;
}