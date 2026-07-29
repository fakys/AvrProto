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

  MessageContentInterface() {
    this->data = new AvrArray<uint8_t>();
  }
  virtual unsigned int getPositionIndex();
  virtual unsigned int getSize();

  virtual void appendData (uint8_t byte) {
    this->data->push(byte);
  }

  virtual AvrArray<uint8_t>* getData() {
    return data;
  }

  virtual bool validData(uint8_t byte);
  virtual bool filled();

  virtual ~MessageContentInterface() {
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
