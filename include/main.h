#ifndef ARDUINO_MAIN_H
#define ARDUINO_MAIN_H


//максикмальный размер массива в байтах
#define MAX_MEMORY_LIMIT_FOR_ARRAY 1024

#define DEFAULT_CAPACITY 1

//Максимальная кратность в байтах
#define MAX_DISCHARGE 2

#include "proto.h"

#ifdef X86_ARCHITECTURE
#include <iostream>
#include <cstdint>
#elifdef AVR_ARCHITECTURE
#include <avr/io.h>
#include <util/delay.h>
#include "stdlib.h"
#include "stdint.h"
#include <util/setbaud.h>
#endif

#include "proto.h"

#endif //ARDUINO_MAIN_H
