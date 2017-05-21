/*
DESCRIPCION  : Ayuntamiento de berat
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/ayuntamiento.c
--------------------------------------------------------------------------------
*/

#include "./path.h"
#include <nightday.h>
#include <door.h>
inherit SCHEDULER_ROOM;
inherit "/room/censo";

create() {
    ::create();
    SetCity("Berat");
    SetIntShort("el ayuntamiento de Berat");
    SetIntLong(
"Estás en el ayuntamiento de Berat. Frente a ti se halla un "
"mostrador y un libro de censo sobre él. En la planta de arriba está "
"la sala de reuniones.\n");

    AddDetail(({"mostrador"}),
    "El mostrador es una especie de mesa alta y estrecha de madera. Tras ella "
 "rodeado de papeles y archivos se encuentra el lugar de trabajo del secretario del "
 "ayuntamiento.\n");

    AddDetail(({"salon", "salón", "sala"}),
    "En la planta de arriba se halla una amplia sala de reunión.\n");

    AddDetail(({"censo","libro"}),
    "En este libro esta una copia del censo actual en Simauria. Para censarte "
    "en este lugar o cambiar el lugar en el que estas censado utiliza 'censar' y "
    "si quieres saber donde estás censado, usa 'consultar'.\n");

    SetLocate("Berat");
    SetIntBright(30);
    AddExit("norte","./cprin4");
    AddExit("arriba","./salon_ay");
    AddDoor("norte", "la puerta de salida",
    "Es la puerta que da a la calle principal de Berat.\n",
    ({"puerta", "puerta de la calle", "puerta del norte"}),
    ([P_DOOR_CLOSE_TIME : ({ND_PREFALL, ND_FALL, ND_PRENIGHT, ND_NIGHT, ND_PREDAWN, ND_DAWN, ND_SUNRISE})]));
    SetLastDest("./cprin4");
    SetNotifyExits("norte");
    SetAssociatedRooms("./salon_ay");
    SetSchedulerID("secretario");
    SetCloseTime(({ND_PREFALL, ND_FALL, ND_PRENIGHT, ND_NIGHT, ND_PREDAWN, ND_DAWN, ND_SUNRISE}));
    AddItem( PNJ("simauria/berat/secretar"),REFRESH_DESTRUCT,1);
    AddItem(PNJ("simauria/berat/guardia"),REFRESH_DESTRUCT,2);
}
