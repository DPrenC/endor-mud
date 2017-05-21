/****************************************************************************
Fichero: calle2.c
Autor: Ratwor
Fecha: 12/08/2007
Descripción: Calle principal de Nandor.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <materials.h>
#include <door.h>
#include <sounds.h>
#include <scheduler.h>

inherit SIM_ROOM;
create() {
    ::create();
    SetLocate("Aldea de Nandor");
    SetIntShort("la calle principal de Nandor");
    SetIntLong("Estás en la calle principal de Nandor, precisamente delante de una de "
        "las tiendas del pueblo. Al norte puedes ver la entrada a la tienda, mientras "
        "que al sur queda la casa de la tendera.\n  La calle continúa hacia el este en"
        " dirección a la plaza, y hacia el oeste en dirección a la entrada del "
        "pueblo.\n");
    SetIndoors(0);
    AddExit("norte","./tiendas/tienda");
    AddExit("sur","./casas/casa2");
    AddExit("este","./calle3");
    AddExit("oeste","./calle1");
    AddDoor("norte", "la puerta de la tienda de Leyma",
    "Es la puerta de la tienda de Leyma.\n",
    ({"puerta", "puerta de la tienda", "puerta de la tienda de Leyma", "puerta del norte"}),
    ([P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
P_DOOR_CLOSE_TIME: S_CLOSED_AT_NIGHT]));
    AddItem(PNJ("marhalt/pueblerinos_nandor"),REFRESH_DESTRUCT,2);
}
