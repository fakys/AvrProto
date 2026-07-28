//
// Created by fakys on 26.07.2026.
//

#include "ArvProtoTunnelController.h"

#include "ProtoMessage.h"
#include "SenderTransaction.h"
#include "TunnelException.h"
#include "main.h"

ArvProtoTunnel *ArvProtoTunnelController::createTunnel(ArvProto* proto, SenderInterface* sender) {
    //Создаем тунель
    //todo генерировать id
    auto* tunnel = new ArvProtoTunnel(proto, sender, 0);
    this->tunnels->push(tunnel);
    return tunnel;
}

ArvProtoTunnel *ArvProtoTunnelController::getTunnelById(uint8_t tunel_id) {
    for (int i = 0; i < this->tunnels->getSize(); i++) {
        if ((*this->tunnels)[i]->getTunelId() == tunel_id) {
            return (*this->tunnels)[i];
        }
    }
    throw TunnelException{TOTAL_ERRORS, "Tunnel not found"};
}
bool ArvProtoTunnelController::hasTunnelById(uint8_t tunel_id) {
    for (int i = 0; i < this->tunnels->getSize(); i++) {
        if ((*this->tunnels)[i]->getTunelId() == tunel_id) {
            return true;
        }
    }
    return false;
}

bool ArvProtoTunnelController::dropTunnelById(uint8_t tunel_id) {
    ArvProtoTunnel* tunnel = getTunnelById(tunel_id);
    AvrArray<ProtoDevice*>* devices = tunnel->getAllDevices();
    bool AllSend = true;
    //Отправляем всем устройствам в тенели сообщение об его закрытии
    for (int i = 0; i < devices->getSize(); i++) {
        ProtoMessage* msg = tunnel->getProto()->messageToProto(new SendMessageDto(SENDER_ID, CLOSE_TUNNEL, nullptr, (*devices)[i]->getDeviceId(), tunel_id));
        auto* transaction = new SenderTransaction(tunnel->getSender(), (*devices)[i], tunnel);
        bool sendTr = transaction->sendMessage(msg);
        if (!sendTr) {
            AllSend = false;
        }
    }
    delete tunnel;

    return AllSend;
}