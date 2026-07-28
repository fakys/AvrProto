//
// Created by fakys on 28.07.2026.
//

#ifndef ARDUINO_MESSAGECONSTRUCTOR_H
#define ARDUINO_MESSAGECONSTRUCTOR_H
#include "AvrArray.h"
#include "MessageContentInterface.h"

class MessageConstructor {
public:
    AvrArray<MessageContentInterface*>* getHeaderContents();
    AvrArray<MessageContentInterface*>* getBodyContents();
};

#endif //ARDUINO_MESSAGECONTRUCTOR_H
