#ifndef ARDUINO_ARDUPROTOV1_H
#define ARDUINO_ARDUPROTOV1_H

//Настройки протокола V1

//Байт с которого начинается транзакция
//Через него и определяется версия протокола
#define START_BYTE 0xAA

//Коды запросов
//Пришлашение в тунель
#define INVITE_IN_TUNNEL 1
//Приглашение на тунель принято
#define ACCEPT_TUNNEL_INVITE 2
//Исключение из тунеля
#define EXCLUDE_FROM_TUNNEL 3
//Cообщение о том что устройство было исключено из тунеля
#define ACCEPT_EXCLUDE_FROM_TUNNEL 4
//Закрытие тунеля, оно не требует подтверждения как при исключении
#define CLOSE_TUNNEL 5

//Заголовок

//Размер заголовка
//Колличиство байт для указания размера в заголовке
#define H_BYTE_FOR_SIZE 1
//Порядковый номер в запросе
#define H_SIZE_INDEX 0

//Колличиство байт для указания id усьройства получалетя в заголовке
#define H_BYTE_FOR_ID_RECIPIENT 1
//Порядковый номер в запросе
#define H_ID_RECIPIENT_INDEX 1

//Колличиство байт для указания id тунеля в заголовке
#define H_BYTE_FOR_TUNNEL_ID 1
//Порядковый номер в запросе
#define H_TUNNEL_ID_INDEX 2

//Колличиство байт для указания id усьройства отправителя в заголовке
#define H_BYTE_FOR_ID_SENDER 1
//Порядковый номер в запросе
#define H_ID_SENDER_INDEX 3

//Колличиство байт для указания старус запроса в заголовке
#define H_BYTE_FOR_REQUEST_CODE 1
//Порядковый номер в запросе
#define H_REQUEST_CODE_INDEX 4



//Тело

//Колличиство байт для указания размера в теле
#define B_BYTE_FOR_SIZE 2
//Порядковый номер в запросе
#define B_SIZE_INDEX 1

//Порядковый номер
#define B_CONTENT_INDEX 2




//Колличиство элементов в заголовке и в теле
#define COUNT_ELEMENTS_IN_BODY 2
#define COUNT_ELEMENTS_IN_HEADER 2

#endif
