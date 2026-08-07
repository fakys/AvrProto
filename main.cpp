#include "main.h"
#include "ArvProto.h"

int main() {
    ArvProto* proto = ArvProto::find();
    auto* message =  new AvrArray<uint8_t>(new uint8_t[4]{'t','e','s','t'}, 4);
    ProtoMessage* mess =  proto->messageToProto(new SendMessageDto(
    1,
    2,
    message,
    2
    ));
    AvrArray<uint8_t>* b = mess->toByte();
    for (int i = 0; i < b->getSize(); i++) {
        std::cout << (int)(*b)[i] << std::endl;
    }
}