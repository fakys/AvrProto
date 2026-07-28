//
// Created by fakys on 27.07.2026.
//


#include "ArvProtoTunnel.h"
#include "SenderTransaction.h"
#include "LastMessageNotFound.h"

SenderTransaction::SenderTransaction(SenderInterface* sender, ProtoDevice* device, ArvProtoTunnel* tunnel) {
    this->sender = sender;
    this->device = device;
    this->tunnel = tunnel;
};

bool SenderTransaction::sendMessage(ProtoMessage* message) {
    bool result = true;
    AvrArray<uint8_t>* byteArr = message->toByte();
    for (int i = 0; i < byteArr->getSize(); i++) {
        if (sender->sendMessage((*byteArr)[i])) { //Отправляем сообщение
            result = false;
            break;
        }
    }

    if (result) {
        this->lastSenderMessage = message;
    }

    return result;
}

//Получение ответа от сообщения
ProtoMessage* SenderTransaction::waitingResponse() {
    if (!this->lastSenderMessage) {
        throw LastMessageNotFound{TOTAL_ERRORS, "last sender message not found"};
    }
    //Создаем контекст для чтения сообщения
    MessageReaderContext* context = this->tunnel->getProto()->createMessageReaderContext(this->sender);

    // todo timeout
    while (1) {
        //todo проверки не пустой ли буфер
        uint8_t byte = sender->receiveMessage();
        if (context->readMessage(byte)) {
            if (!context->hasError()) {
                ProtoMessage* message = context->getMessage();
                if (
                    //Если тунели сходятся
                    message->getHeader()->getTunnelId()->getData()->last() == this->tunnel->getTunelId() &&
                    //Если это то устройство которому мы ранее отправляли сообщение
                    message->getHeader()->getIdDeviceSender()->getData()->last() == this->lastSenderMessage->getHeader()->getIdDeviceRecipient()->getData()->last() &&
                    //Нам ли пришло это сообщение
                    message->getHeader()->getIdDeviceRecipient()->getData()->last() == SENDER_ID
                ) {
                    return message;
                }
            } else {
                //Если есть ошибки в текущем контексте, создаем новый
                delete context;
                context = this->tunnel->getProto()->createMessageReaderContext(this->sender);
            }
        }
    }
    //todo ошибки если мы не дождались ответа
}