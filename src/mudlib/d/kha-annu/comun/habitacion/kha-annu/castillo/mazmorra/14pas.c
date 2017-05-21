#include "path.h"
#include <properties.h>
#include <materials.h>
#include <sounds.h>

inherit KHA_ROOM;

create()
{
    ::create();
    SetIntShort("el pasillo de las celdas");
    SetIntLong("Continúas hasta la siguiente puerta.\nAl este y al oeste solo ves puertas, el "
        "muro está perfecto.\n");
    SetIndoors(1);
    SetIntBright(10);
    SetIntNoise("Oyes un gruñido en el interior de la celda.\n");
    SetIntSmell("Huele a ... no sé. Algo.\n");
    AddExit("este",("15pas"));
    AddExit("oeste",("13pas"));
    AddExit("norte","./celda10");
    AddDoor("norte","la puerta de la celda",
        "Es una puerta de hierro totalmente lisa.\n",
        ({"puerta","puerta de celda","puerta de la celda"}),2,
        ([P_MATERIAL:M_HIERRO, P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_metalica"),
            P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_metalica")]));
    SetLocate("las mazmorras");
}
