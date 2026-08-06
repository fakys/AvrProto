#include "ArvProto.h"


ProtoMessage *ArvProto::messageToProto(SendMessageDto *dto) {
    auto *message = new ProtoMessage(
        new ProtoHeader(),
        new ProtoBody()
    );

    if (message->getHeader()->getIdDeviceRecipient()->validData(dto->getIdRecipient())) {
        message->getHeader()->getIdDeviceRecipient()->appendData(dto->getIdRecipient());
    }

    if (message->getHeader()->getIdDeviceSender()->validData(dto->getIdSender())) {
        message->getHeader()->getIdDeviceSender()->appendData(dto->getIdSender());
    }

    if (message->getHeader()->getRequestCode()->validData(dto->getCode())) {
        message->getHeader()->getRequestCode()->appendData(dto->getCode());
    }

    if (message->getHeader()->getTunnelId()->validData(dto->getTunnelId())) {
        message->getHeader()->getTunnelId()->appendData(dto->getTunnelId());
    }

    if (message->getBody()->getBodySize()->validData(dto->getMessage()->getSize())) {
        message->getBody()->getBodySize()->appendData(dto->getMessage()->getSize());
    }
    message->getBody()->getContentBody()->appendDependenciesContent(message->getBody()->getBodySize());
    for (unsigned int i = 0; i < dto->getMessage()->getSize(); i++) {
        if (message->getBody()->getContentBody()->validData((*dto->getMessage())[i])) {
            message->getBody()->getContentBody()->appendData((*dto->getMessage())[i]);
        }
    }


    return message;
}

MessageReaderContext *ArvProto::createMessageReaderContext(SenderInterface *sender) {
    return new MessageReaderContext(sender);
}
