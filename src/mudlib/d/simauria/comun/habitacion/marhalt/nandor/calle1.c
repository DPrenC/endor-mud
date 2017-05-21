/****************************************************************************
Fichero: calle1.c
Autor: Ratwor
Fecha: 12/08/2007
Descripción: Calle principal de Nandor.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <door.h>
#include <sounds.h>
#include <scheduler.h>
inherit SIM_ROOM;
create () {
    ::create();
    SetLocate("Aldea de Nandor");
    SetIntShort("la calle principal de Nandor");
    SetIntLong("Te encuentras en la calle principal de Nandor. La calle discurre de "
        "este a oeste, desde la plaza hasta la entrada del pueblo.\n  En el sur "
        "se encuentra la herrería de Nandor.\n Al norte puedes ver una casita"
        " pequeña.\n");

    SetIndoors(0);
    SetIntNoise("Se escucha sonido de herrería en el local del sur.\n");
    AddExit("norte","./casas/casa1");
    AddExit("este","./calle2");
    AddExit("oeste","./calle0" );
    AddExit("sur","./tiendas/herreria" );
    AddDoor("sur", "la puerta de la herrería",
    "Es la puerta que da entrada a la herrería.\n",
    ({"puerta", "puerta de la herrería", "puerta de la herreria", "puerta del sur"}),
    ([P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
    AddDoor("norte", "una puerta vieja", "Es una puerta vieja de madera de una casa.\n",
    ({"puerta", "puerta vieja", "puerta de madera", "puerta vieja de madera"}));
}
