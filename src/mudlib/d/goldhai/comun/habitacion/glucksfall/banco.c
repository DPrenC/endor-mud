#include "path.h"
#include <properties.h>
#include <door.h>
#include <sounds.h>
#include <scheduler.h>
inherit BANK;

create()
{
    ::create();
    SetIntShort("el banco de Glucksfall");
    SetIntLong("Has entrado al banco  de Glucksfall. Si dispones de algún dinero será mejor "
        "que lo ingreses pronto no sea que alguien te lo robe mientras estás vivo, o después de "
        "matarte.\n");
    SetIndoors(1);
    SetBankName("glucksfall");
    SetIntBright(50);
    AddDetail(({"barrotes","rejas","reja"}),
            "Es una reja de gruesos barrotes, tras la que se encuentra el banquero "
            "para atender a los clientes, sin acabar siendo asesinado ni atracado.\n");
    SetKeeper(PNJ("glucksfall/molian"));
    SetLastDest("calle2");
    SetNotifyExits(({"oeste"}));
    AddExit("oeste","calle2");
    AddDoor("oeste","la puerta de la calle",
        "Es una gruesa puerta de hierro, como era de esperar en un sitio como éste. Por "
            "tratarse además de una sede bancaria, está reforzada por ambos lados con un "
            "entramado de barras de hierro, embutidas en la plancha a fuego y martillo.\n",
        ({"puerta","puerta este","puerta de calle","puerta de la calle"}),GENERO_FEMENINO,
        ([P_DOOR_CLOSE_SOUND:SND_SUCESOS("cerrar_metalica"),
        P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_metalica"),
        P_MATERIAL:M_HIERRO,P_DOOR_CLOSE_TIME:S_CLOSED_AT_NIGHT]));
    SetLocate("Glucksfall");
}