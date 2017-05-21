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
    SetIntLong("La avenida Djorn continúa hacia el Norte y hacia el Sur.\nSi quieres realizar "
        "alguna transacción monetaria, al Este tienes la sede de la hermandad de banqueros.\n");
    SetIndoors(0);
    AddExit("norte","calle1");
    AddExit("sur","calle3");
    AddExit("este","banco");
    AddDoor("este","la puerta del banco",
        "Es una gruesa puerta de hierro, como era de esperar en un sitio como éste. Por "
            "tratarse además de una sede bancaria, está reforzada por ambos lados con un "
            "entramado de barras de hierro, embutidas en la plancha a fuego y martillo.\n",
        ({"puerta","puerta este","puerta de banco","puerta del banco"}),GENERO_FEMENINO,
        ([P_DOOR_CLOSE_SOUND:SND_SUCESOS("cerrar_metalica"),
        P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_metalica"),
        P_MATERIAL:M_HIERRO,P_DOOR_CLOSE_TIME:S_CLOSED_AT_NIGHT]));
    SetLocate("Glucksfall");
}
