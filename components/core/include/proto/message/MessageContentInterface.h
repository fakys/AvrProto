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
    this->dependsContent = new AvrArray<MessageContentInterface*>();
  }
  virtual unsigned int getPositionIndex() {
    return 0;
  };
  virtual unsigned int getSize() {
    return 0;
  };

  virtual void appendData (uint8_t byte) {
    this->data->push(byte);
  }

  virtual AvrArray<uint8_t>* getData() {
    return data;
  }

  virtual bool validData(uint8_t byte) {
    return false;
  };

  virtual bool filled() {
    return false;
  };

  virtual ~MessageContentInterface() {
    data->clear();
    this->dependsContent->clear();
    delete data;
    delete this->dependsContent;
  }


  void appendDependenciesContent(MessageContentInterface* depends) {
    (*this->dependsContent)[depends->getPositionIndex()] = depends;
  }
};

#endif //ARDUINO_MESSAGECONTENTINTERFACE_H
