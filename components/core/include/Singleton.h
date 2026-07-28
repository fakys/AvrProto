//
// Created by fakys on 27.07.2026.
//

#ifndef ARDUINO_SINGLETON_H
#define ARDUINO_SINGLETON_H

template<typename T>
class Singleton {
  private:
    static T* object;
  public:
    static T* find() {
      if (!object) {
        object = new T;
      }
      return object;
    };
};

#endif //ARDUINO_SINGLETON_H
