# Протокол дла микроконтроллеров AVR
## О протоколе

#### Данные передаются пока только через uart

#### Билд
```
cmake -S . -B build
```
```
cd ./build && make
```
#### Прошивка МК
```
avrdude -c arduino -p m328p -P /dev/ttyUSB0 -U flash:w:avr_proto.hex:i
```