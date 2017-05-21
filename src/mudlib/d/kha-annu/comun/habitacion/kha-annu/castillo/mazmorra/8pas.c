#include "./path.h"
#include <properties.h>
#include <materials.h>
#include <sounds.h>

inherit KHA_ROOM;

create()
{
    ::create();
    SetIntShort("el pasillo de las celdas");
    SetIntLong("Llegas hasta la siguiente celda que está al oeste.\nPuedes ver que hay mas "
        "puertas en el pasillo, tanto al sur como al norte.\n");
    SetIndoors(1);
    SetIntBright(10);
    SetIntNoise("Un ruido llega de esa puerta.\n");
    SetIntSmell("Huele a suciedad, como si alguien que no se lava estuviera por aquí.\n");
    AddDetail(({"reja"}),"A través de la reja, te parece ver una figura al fondo de la celda.\n");
    AddExit("norte",("9pas"));
    AddExit("sur",("7pas"));
    AddExit("oeste","./celda5");
    AddDoor("oeste","la puerta de la celda",
        "Es una puerta de hierro, con una pequeña reja.\n",
        ({"puerta","puerta de celda","puerta de la celda"}),2,
        ([P_DOOR_TRANSPARENCY:1,P_MATERIAL:M_HIERRO, P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_metalica"),
            P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_metalica")]));
    SetLocate("las mazmorras");
}
