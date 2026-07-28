//
// Created by fakys on 28.07.2026.
//

#include "MessageConstructor.h"
#include "AvrArray.h"
#include "BodySize.h"

AvrArray<MessageContentInterface*> *MessageConstructor::getBodyContents() {
    //Собираем структуру для тела
    AvrArray<MessageContentInterface*>* content = new AvrArray<MessageContentInterface*>();
    MessageContentInterface* size = new BodySize();
    content->push(size, size->getPositionIndex());
    MessageContentInterface* contentBody = new ContentBody();
    content->push(contentBody, contentBody->getPositionIndex());

    return content;
}


AvrArray<MessageContentInterface*> *MessageConstructor::getHeaderContents() {
    //Собираем структуру для заголовка
    AvrArray<MessageContentInterface*>* content = new AvrArray<MessageContentInterface*>();
    MessageContentInterface* size = new HeaderSize();
    content->push(size, size->getPositionIndex());
    MessageContentInterface* idDeviceRecipient = new IdDeviceRecipient();
    content->push(idDeviceRecipient, idDeviceRecipient->getPositionIndex());
    MessageContentInterface* idDeviceSender = new IdDeviceSender();
    content->push(idDeviceSender, idDeviceSender->getPositionIndex());
    MessageContentInterface* requestCode = new RequestCode();
    content->push(requestCode, requestCode->getPositionIndex());
    MessageContentInterface* tunelId = new TunnelId();
    content->push(tunelId, tunelId->getPositionIndex());

    return content;
}