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
  SetLongWrap(
    "En un principio te parece que est�s perdido pero de inmediato ves "
    "que no hay perdida, te encuentras en medio de la avenida Djorn. En el "
    "Este hay una peque�a biblioteca en ruinas que contrasta con la lujosa "
    "tienda ropas que tienes en el Oeste."
    );
    SetIndoors(0);
    AddExit("norte","calle5");
    AddExit("sur","calle7");
    AddExit("este","biblioteca");
    AddExit("oeste","tienda_ropa");
    AddDoor("oeste","la puerta de la sastrer�a",
        "Es una gruesa puerta de hierro, como era de esperar en un sitio como �ste. Por "
        "supuesto, aqu� nadie se f�a de nadie.\n",
        ({"puerta","puerta oeste","puerta de sastrer�a","puerta de la sastrer�a"}),GENERO_FEMENINO,
        ([P_DOOR_CLOSE_SOUND:SND_SUCESOS("cerrar_metalica"),
        P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_metalica"),
        P_MATERIAL:M_HIERRO,P_DOOR_CLOSE_TIME:S_CLOSED_AT_NIGHT]));
    SetLocate("Glucksfall");
}
