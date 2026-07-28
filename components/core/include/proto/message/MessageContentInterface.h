//
// Created by fakys on 26.07.2026.
//

#ifndef ARDUINO_MESSAGECONTENTINTERFACE_H
#define ARDUINO_MESSAGECONTENTINTERFACE_H

#include "AvrArray.h"

class MessageContentInterface {
  protected:
    AvrArray<uint8_t>* data;
    AvrArray<MessageContentInterface*>* dependsContent;
  public:

  MessageContentInterface() {}
  virtual unsigned int getPositionIndex();
  virtual unsigned int getSize();

  void setData (AvrArray<uint8_t>* d) {
    this->data = d;
  }
  AvrArray<uint8_t>* getData() {
    return data;
  }
  ~MessageContentInterface() {
    delete data;
  }

  AvrArray<unsigned int> *getDependenciesContentIndex() {
    return nullptr;
  }

  void setDependenciesContent(AvrArray<MessageContentInterface*> * depends) {
    this->dependsContent = depends;
  }
};

#endif //ARDUINO_MESSAGECONTENTINTERFACE_H
