#ifndef ARDUINO_ARVPROTO_H
#define ARDUINO_ARVPROTO_H

#include "ProtoMessage.h"
#include "SendMessageDto.h"
#include "MessageReaderContext.h"

class ArvProto : public Singleton<ArvProto> {
public:
    ProtoMessage* messageToProto(SendMessageDto* dto);
    MessageReaderContext* createMessageReaderContext(SenderInterface* sender);
};

#endif
