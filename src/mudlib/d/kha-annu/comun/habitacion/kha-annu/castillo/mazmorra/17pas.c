#include "path.h"
#include <properties.h>
#include <materials.h>
#include <sounds.h>

inherit KHA_ROOM;

create()
{
    ::create();
    SetIntShort("el pasillo de las celdas");
    SetIntLong("Sigues en el pasillo.\nMás pasillo al sur, y la consabida "
        "puerta al este.\n");
    SetIndoors(1);
    SetIntBright(10);
    SetIntNoise("No oyes nada en especial.\n");
    SetIntSmell("Un olor fétido sale de la celda.\n");
    AddExit("norte",("16esqui"));
    AddExit("sur",("18pas"));
    AddExit("este","./celda12");
    AddDoor("este","la puerta de la celda",
        "Es una puerta de hierro completamente lisa.\n",
        ({"puerta","puerta de celda","puerta de la celda"}),2,"cdpnmpgs",
        ([P_DOOR_STATE:DOOR_CLOSED,P_DOOR_LOCK_STATE:DOOR_LOCKED,P_MATERIAL:M_HIERRO,
            P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_metalica"),P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_metalica")]));
    SetLocate("las mazmorras");
}
