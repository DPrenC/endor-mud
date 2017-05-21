#include "path.h"
#include <properties.h>
#include <door.h>
#include <sounds.h>
#include <scheduler.h>
inherit SMITHY;

create()
{
    ::create();
    SetIntShort("la herrería de Glucksfall");
    SetIntLong("Has entrado en la herrería de Glucksfall, que goza de una gran popularidad "
        "entre los más famosos delincuentes. Si deseas que tus armas sean de una mayor calidad "
        "y consistencia, has venido al sitio correcto.\n");
    SetIndoors(1);
    SetIntBright(50);
    AddExit("este","calle1");
    AddDoor("este","la puerta de la calle",
        "Es una gruesa puerta de hierro, como era de esperar en un sitio como éste. Por "
        "supuesto, aquí nadie se fía de nadie.\n",
        ({"puerta","puerta este","puerta de calle","puerta de la calle"}),GENERO_FEMENINO,
        ([P_DOOR_CLOSE_SOUND:SND_SUCESOS("cerrar_metalica"),
        P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_metalica"),
        P_MATERIAL:M_HIERRO,P_DOOR_CLOSE_TIME:S_CLOSED_AT_NIGHT]));
    SetLocate("Glucksfall");
}