#ifndef ARDUINO_ARVARRAY_H
#define ARDUINO_ARVARRAY_H

#include "errors_code.h"
#include "main.h"
#include "InvalidSizeFormatException.h"

template<typename T>
class AvrArray {
private:
    T* avrArray;
    unsigned int size;
    unsigned int capacity; // выделеная память

    //Уверичивает память если жто требуется
    void reSize() {
        if (this->size >= MAX_MEMORY_LIMIT_FOR_ARRAY) {
            throw InvalidSizeFormatException{TOTAL_ERRORS, "Max memory limit for array"};
        }

        if (this->size * 2 >= MAX_MEMORY_LIMIT_FOR_ARRAY) {
            this->setCapacity(MAX_MEMORY_LIMIT_FOR_ARRAY);
        } else {
            //Просто умножаем 2
            this->setCapacity(this->size * 2);
        }
    }; //Увеличивает размер x2

    void init() {
        if (this->capacity <= 0) {
            throw InvalidSizeFormatException{TOTAL_ERRORS, "Capacity not specified"};
        }

        if (!this->avrArray) {
            this->avrArray = (T*)malloc(sizeof (T) * this->capacity);
        } else {
            this->reSize();
        }
    }

public:
    AvrArray() : avrArray(nullptr), size(0), capacity(DEFAULT_CAPACITY) {
        this->init();
    };

    AvrArray(T *avrArray, unsigned int size) : avrArray(nullptr), size(0), capacity(DEFAULT_CAPACITY) {
        this->avrArray = avrArray;
        this->size = size;
        this->reSize();
    };

    void push(T data, unsigned int index = 0) {
        if (index >= this->capacity) {
            setCapacity(index+1);
        }
        if (this->size >= this->capacity) {
            this->reSize();
        }

        if (index) {
            this->avrArray[index] = data;
        } else {
            this->avrArray[this->size] = data;
        }
        //todo Тут надо что-то с индексами придумать, возможно каждый индекс в массив писать
        this->size++;
    };

    void merge(AvrArray<T>* other) {

        for (unsigned int i = 0; i < other->getSize(); i++) {
            this->push((*other)[i]);
        }
    }

    //Метод выделяет память массиву
    void setCapacity(unsigned int capacity) {
        if (this->size > capacity) {
            throw InvalidSizeFormatException{TOTAL_ERRORS, "Reserved memory is less than occupied memory"};
        }

        if (capacity > MAX_MEMORY_LIMIT_FOR_ARRAY) {
            throw InvalidSizeFormatException{TOTAL_ERRORS, "Max memory limit for array"};
        }

        this->capacity = capacity;
        T* temp = (T*)realloc(this->avrArray, capacity * sizeof(T));
        if (!temp) {
            throw InvalidSizeFormatException{TOTAL_ERRORS, "realloc error"};
        }
        this->avrArray = temp;

    }

    T* getArray() {
        return this->avrArray;
    }

    unsigned int getSize() {
        return this->size;
    };

    unsigned int getCapacity() {
        return this->capacity;
    }

    T& operator [](int index) {
        return this->avrArray[index];
    };

    T& last() {
        return this->avrArray[this->size-1];
    };

    void clear() {
        free(this->avrArray);
        this->avrArray = nullptr;
    }

    ~AvrArray() {
        this->avrArray = nullptr;
    };
};


#endif
