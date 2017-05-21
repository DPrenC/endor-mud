#include "path.h"
#include <properties.h>
#include <materials.h>
#include <sounds.h>

inherit KHA_ROOM;

create()
{
    ::create();
    SetIntShort("el pasillo de las celdas");
    SetIntLong("Continúas hasta la siguiente puerta.\nHay otra celda al norte.\n");
    SetIndoors(1);
    SetIntBright(15);
    SetIntNoise("No oyes nada en especial.\n");
    SetIntSmell("Huele a ... ¿Humedad?\n");
    AddExit("este",("16esqui"));
    AddExit("oeste",("14pas"));
    AddExit("norte","./celda11");
    AddDoor("norte","la puerta de la celda",
        "Es una puerta de hierro totalmente lisa.\n",
        ({"puerta","puerta de celda","puerta de la celda"}),2,
        ([P_MATERIAL:M_HIERRO, P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_metalica"),
            P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_metalica")]));
    SetLocate("las mazmorras");
}
