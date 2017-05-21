#include "path.h"
#include <properties.h>
#include <materials.h>
#include <sounds.h>

inherit KHA_ROOM;

create()
{
    ::create();
    SetIntShort("el pasillo de las celdas");
    SetIntLong("Continúas hasta la siguiente puerta, que está al norte.\nAl este ves un recodo. "
        "Al oeste hay mas puertas, y el pasillo se pierde en la oscuridad.\n");
    SetIndoors(1);
    SetIntBright(10);
    SetIntNoise("No oyes nada en especial.\n");
    SetIntSmell("La humedad se cuela en los pelillos de tu nariz.\n");
    AddDetail(({"reja"}),"La reja deja ver parte de la habitación, está muy oscuro.\n");
    AddExit("oeste",("22pas"));
    AddExit("este",("20esqui"));
    AddExit("norte","./celda15");
    AddDoor("norte","la puerta de la celda",
        "Es una puerta de hierro que tiene una pequeña reja.\n",
        ({"puerta","puerta de celda","puerta de la celda"}),2,
        ([P_DOOR_TRANSPARENCY:1,P_MATERIAL:M_HIERRO, P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_metalica"),
            P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_metalica")]));
    SetLocate("las mazmorras");
}
