/*
DESCRIPCION  : calle koldar
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/ckol2.c
MODIFICACION : 28-10-99 [icaro@simauria]creacion
						[Mal]
--------------------------------------------------------------------------------
*/
#include "./path.h"
inherit SIM_ROOM;
create() {
    ::create();
    SetLocate("Berat");
    SetIntShort("la calle Koldar");
    SetIntLong("Estás en la calle Koldar, la calle más bella "
    "del pueblo. La calle continua al norte y al sur. Mientras "
    "que al oeste se levanta una de las casas de Berat.\n");
    SetIndoors(0);
    SetIntSmell("Huele a aire fresco.\n");
    AddDetail(({"camino","calle"}),"Es la calle más bella del pueblo "
    "es una calle tranquila y solitaria, perfecta para las parejas jóvenes "
    "del pueblo.\n");
    AddDetail(({"casas","casa"}),"Son unas casas altas y sencillas.\n");
    //AddDetail("puente","Es uno de los puentes de acceso al "
    //"pueblo, es estrecho pero sólido.\n");

    AddExit("norte","./ckol1");
    AddExit("oeste","./hab9_1");
    AddExit("sur","./ckol3");
    //AddExit("este","./puente2");
    AddDoor("oeste", "la puerta de una casa");
    AddItem(PNJ("simauria/berat/guardia"),REFRESH_DESTRUCT,d2());
}
