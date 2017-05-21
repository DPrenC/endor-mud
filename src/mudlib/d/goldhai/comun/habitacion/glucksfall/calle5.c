#include "path.h"
#include <properties.h>
#include <door.h>
#include <sounds.h>
#include <scheduler.h>
inherit GROOM;

create()
{
    ::create();
    SetIntShort("la avenida Djorn");
    SetIntLong("Estás paseando por la Avenida Djorn de Glucksfall, que recorre la ciudad de "
        "Norte a Sur.\nTe paras a contemplar un pequeño edificio en el Oeste, que parece "
        "tratarse de una armería.\n");
    SetIndoors(0);
    AddExit("norte","calle4");
    AddExit("sur","calle6");
    AddExit("oeste","armeria");
    AddDoor("oeste","la puerta de la armería",
        "Es una gruesa puerta de hierro, como era de esperar en un sitio como éste. Por "
        "supuesto, aquí nadie se fía de nadie.\n",
        ({"puerta","puerta oeste","puerta de armería","puerta de la armería"}),GENERO_FEMENINO,
        ([P_DOOR_CLOSE_SOUND:SND_SUCESOS("cerrar_metalica"),
        P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_metalica"),
        P_MATERIAL:M_HIERRO,P_DOOR_CLOSE_TIME:S_CLOSED_AT_NIGHT]));
    SetLocate("Glucksfall");
}
