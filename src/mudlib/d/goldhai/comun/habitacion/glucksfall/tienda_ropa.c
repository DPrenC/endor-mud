#include "path.h"
#include <properties.h>
#include <door.h>
#include <sounds.h>
#include <scheduler.h>
inherit SHOP;

create()
{
    ::create();
    SetIntShort("la sastrería de Glucksfall");
    SetIntLong("Una sastrería en Glucksfall, sí, porque ser un guerrero o un contrabandista no "
        "va en contra de que vistas bien. Ése es el lema que puedes leer en una de las "
        "esquinas.\nPuedes ver la avenida Djorn a través de la puerta.\n");
    SetIndoors(1);
    SetIntBright(50);
    AddExit("este","calle6");
    AddDoor("este","la puerta de la calle",
        "Es una gruesa puerta de hierro, como era de esperar en un sitio como éste. Por "
        "supuesto, aquí nadie se fía de nadie.\n",
        ({"puerta","puerta este","puerta de calle","puerta de la calle"}),GENERO_FEMENINO,
        ([P_DOOR_CLOSE_SOUND:SND_SUCESOS("cerrar_metalica"),
        P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_metalica"),
        P_MATERIAL:M_HIERRO,P_DOOR_CLOSE_TIME:S_CLOSED_AT_NIGHT]));
    SetLocate("Glucksfall");
}
