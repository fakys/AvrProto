#ifndef ARDUINO_MAINEXCEPTION_H
#define ARDUINO_MAINEXCEPTION_H

class MainException {
public:
    const unsigned int& code;
    const char* errorMessage;
    MainException(const unsigned int& code, const char* errorMessage): code(code), errorMessage(errorMessage) {};
};

#endif //ARDUINO_MAINEXCEPTION_H
