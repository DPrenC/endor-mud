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
    "En el Este tienes una taberna bastante apestosa y en la que es muy "
    "poco recomendable que entres a no ser por una causa muy buena. En el Oeste "
    "está la tienda de Ronn un gigante con bastantes malas pulgas pero que "
    "ofrece unos precios muy interesantes."
    );
    SetIndoors(0);
    AddItem(PNJ("glucksfall/troll"),REFRESH_DESTRUCT);
    AddExit("norte","calle6");
    AddExit("sur","calle8");
    AddExit("este","pub2");
    AddExit("oeste","tienda");
    AddDoor("oeste","la puerta de la tienda",
        "Es una gruesa puerta de hierro, como era de esperar en un sitio como éste. Por "
        "supuesto, aquí nadie se fía de nadie.\n",
        ({"puerta","puerta oeste","puerta de tienda","puerta de la tienda"}),GENERO_FEMENINO,
        ([P_DOOR_CLOSE_SOUND:SND_SUCESOS("cerrar_metalica"),
        P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_metalica"),
        P_MATERIAL:M_HIERRO,P_DOOR_CLOSE_TIME:S_CLOSED_AT_NIGHT]));
    SetLocate("Glucksfall");
}
