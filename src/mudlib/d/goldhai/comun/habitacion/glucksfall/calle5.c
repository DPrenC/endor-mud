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
    SetIntLong("Est�s paseando por la Avenida Djorn de Glucksfall, que recorre la ciudad de "
        "Norte a Sur.\nTe paras a contemplar un peque�o edificio en el Oeste, que parece "
        "tratarse de una armer�a.\n");
    SetIndoors(0);
    AddExit("norte","calle4");
    AddExit("sur","calle6");
    AddExit("oeste","armeria");
    AddDoor("oeste","la puerta de la armer�a",
        "Es una gruesa puerta de hierro, como era de esperar en un sitio como �ste. Por "
        "supuesto, aqu� nadie se f�a de nadie.\n",
        ({"puerta","puerta oeste","puerta de armer�a","puerta de la armer�a"}),GENERO_FEMENINO,
        ([P_DOOR_CLOSE_SOUND:SND_SUCESOS("cerrar_metalica"),
        P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_metalica"),
        P_MATERIAL:M_HIERRO,P_DOOR_CLOSE_TIME:S_CLOSED_AT_NIGHT]));
    SetLocate("Glucksfall");
}
