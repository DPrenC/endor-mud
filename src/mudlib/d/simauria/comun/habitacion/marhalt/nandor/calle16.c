/****************************************************************************
Fichero: calle16.c
Autor: Ratwor
Fecha: 01/11/2006
Descripción:  una calle que une las dos paralelas de nandor.
****************************************************************************/

#include "./path.h"
#include <door.h>
#include <properties.h>
#include <sounds.h>
#include <scheduler.h>

inherit SIM_ROOM;

create()
{
    ::create();
    SetLocate("Aldea de Nandor");
    SetIntShort("un pasaje");
    SetIntLong("Te encuentras en un pasaje de la aldea de Nandor que une la calle Narwhald"
        " al norte, con la plaza de la villa al sur.\n El edificio que tienes al oeste "
        "forma parte del cuartel general de guerreros, y al este puedes entrar en la "
        "armería de la villa.\n");
    SetIntNoise("En esta zona no se oye gran cosa.\n");
    SetIndoors(0);
    AddDetail(({"edificio","edificio del oeste"}), "Un tanto espartano, pero para ser"
        " de guerreros tampoco se puede esperar mucho.\n");
    AddDetail(({"armería", "armeria", "tienda"}), "Es la armería de Nandor, comprensible "
        "su ubicación teniendo en cuenta la proximidad con el gremio de guerreros,  se "
        "entra al este.\n");
    AddDetail(({"pasaje","calle"}), "Es un pasaje, de norte a sur, perpendicular a la "
        "calle principal.\n");
    AddExit("sur","./calle17");
    AddExit("norte","./calle12");
    AddExit("este", "./tiendas/armeria");
    AddDoor("este", "la puerta de la armería",
    "Es la puerta que da entrada a la armería.\n",
    ({"puerta", "puerta de la armería", "puerta de la armeria", "puerta del este"}),
    ([P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
    AddItem(PNJ("marhalt/pueblerinos_nandor"),REFRESH_DESTRUCT,2);
}
