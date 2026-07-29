#ifndef ARDUINO_PROTOBODY_H
#define ARDUINO_PROTOBODY_H
#include "BodySize.h"
#include "ContentBody.h"

class ProtoBody {
    private:
        BodySize* body_size;
        ContentBody* content_body;

        //Хранит в себе уже сортированный контент
        AvrArray<MessageContentInterface*>* sortContent;
    public:
        ProtoBody() {
            this->sortContent = new AvrArray<MessageContentInterface*>();

            this->body_size = new BodySize();
            this->sortContent->push(this->body_size, this->body_size->getPositionIndex());
            this->content_body = new ContentBody();
            this->sortContent->push(this->content_body, this->content_body->getPositionIndex());
        }
        BodySize* getBodySize() {
            return this->body_size;
        }

        ContentBody* getContentBody() {
            return this->content_body;
        }

        AvrArray<MessageContentInterface*>* getSortContent() {
            return this->sortContent;
        }
};

#endif
