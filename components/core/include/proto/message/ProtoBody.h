#ifndef ARDUINO_PROTOBODY_H
#define ARDUINO_PROTOBODY_H
#include "BodySize.h"
#include "ContentBody.h"

class ProtoBody {
    private:
        BodySize* body_size;
        ContentBody* content_body;
    public:
        ProtoBody(BodySize* body_size) {
            this->body_size = body_size;
            this->content_body = new ContentBody();
        }
        BodySize* getBodySize() {
            return this->body_size;
        }
        ContentBody* getContentBody() {
            return this->content_body;
        }
};

#endif
