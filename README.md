# Протокол дла микроконтроллеров AVR
## О протоколе

#### Данные передаются пока только через uart
#### Прошивка МК
```
avrdude -c arduino -p m328p -P /dev/ttyUSB0 -U flash:w:arduino.hex:i
```