//
// Created by fakys on 29.07.2026.
//

#include "MessageReaderContext.h"
#include "ProtoMessage.h"

bool MessageReaderContext::readMessage(uint8_t byte) {
    if (this->messageReady) {
        return true;
    }

    if (!this->message) {
        if (byte != START_BYTE) {
            //Если нет начального байта в сообщении то ошибка
            this->error = true;
        } else {
            //Если в начале сообщения стоит стартовый байт, то создаем сообщение
            this->message = new ProtoMessage(
                new ProtoHeader(),
                new ProtoBody()
            );
        }
    } else {
        if (!this->fill_header) {
            for (int i = 0; i < this->message->getHeader()->getSortContent()->getSize() - 1; i++) {
                //Если блок не заполнен
                if (!(*this->message->getHeader()->getSortContent())[i]->filled()) {
                    //Если данные для этого блока валидны, заполняем их
                    if (
                        (*this->message->getHeader()->getSortContent())[i]->validData(byte)
                    ) {
                        (*this->message->getHeader()->getSortContent())[i]->appendData(byte);

                        //Если это поиледный блок в заголовке, мы ставим флаг что заголовок заполнен
                        if (
                            i == this->message->getHeader()->getSortContent()->getSize() - 1 &&
                            (*this->message->getHeader()->getSortContent())[i]->filled()
                        ) {
                            this->fill_header = true;
                        }
                    } else {
                        this->error = true;
                    }
                }
            }
        } else {
            //Как только заполнели заголовок заполняем тело
            for (int i = 0; i < this->message->getBody()->getSortContent()->getSize() - 1; i++) {
                //Если блок не заполнен
                if (!(*this->message->getBody()->getSortContent())[i]->filled()) {
                    //Если данные для этого блока валидны, заполняем их
                    if (
                        (*this->message->getBody()->getSortContent())[i]->validData(byte)
                    ) {
                        (*this->message->getBody()->getSortContent())[i]->appendData(byte);

                        //Если мы все заполнили то ставим флаг готовности сообщения
                        if (
                            i == this->message->getBody()->getSortContent()->getSize() - 1 &&
                            (*this->message->getBody()->getSortContent())[i]->filled()
                        ) {
                            this->messageReady = true;
                        }
                    } else {
                        this->error = true;
                    }
                }
            }
        }
    }
    return true;
}

bool MessageReaderContext::hasError() {
    return this->error;
}

bool MessageReaderContext::getMessageReady() {
    return this->messageReady;
}

ProtoMessage *MessageReaderContext::getMessage() {
    return this->message;
}
