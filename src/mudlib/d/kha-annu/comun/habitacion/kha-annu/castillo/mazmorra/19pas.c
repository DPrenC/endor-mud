#include "path.h"
#include <properties.h>
#include <materials.h>
#include <sounds.h>

inherit KHA_ROOM;

create()
{
    ::create();
    SetIntShort("el pasillo de las celdas");
    SetIntLong("Continúas hasta la siguiente puerta. La puerta queda al este.\nEste pasillo es "
        "siempre igual, muros desnudos y puertas. Al sur hay una esquina, al norte sigue el "
        "pasillo.\n");
    SetIndoors(1);
    SetIntBright(10);
    SetIntNoise("No oyes nada en especial.\n");
    SetIntSmell("Huele a ... humedad?\n");
    AddDetail(({"reja"}),"La reja deja ver parte de la habitación, nada en especial.\n");
    AddExit("norte",("18pas"));
    AddExit("sur",("20esqui"));
    AddExit("este","./celda14");
    AddDoor("este","la puerta de la celda",
        "Es una puerta de hierro que tiene una pequeña reja.\n",
        ({"puerta","puerta de celda","puerta de la celda"}),2,
        ([P_DOOR_TRANSPARENCY:1,P_MATERIAL:M_HIERRO, P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_metalica"),
            P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_metalica")]));
    SetLocate("las mazmorras");
}
