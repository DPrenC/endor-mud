/*
DESCRIPCION  : calle koldar
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/ckol1.c
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
    SetIntLong("Estás en la calle Koldar, es la calle más bella "
    "del pueblo, gracias al limpio riachuelo que la rodea por el este "
    "y que al no ser muy transitada, se encuentra limpia y bien cuidada. "
    "La calle continua al norte y al sur, y al oeste puedes ver la casa de "
    "algun comerciante o marinero.\n");
    SetIndoors(0);
    SetIntSmell("Huele a aire fresco.\n");
    AddDetail(({"camino","calle"}),"Es la calle más bella del pueblo "
    "es una calle tranquila y solitaria, perfecta para las parejas jóvenes "
    "del pueblo.\n");
    AddDetail(({"casas","casa"}),"Son unas casas bastante normales.\n");
    AddDetail(({"rio", "río", "riachuelo"}),"Es uno de los riachuelos que forman el "
    "delta en el que se encuentra Berat .\n");

    AddExit("norte","./cgold6");
    AddExit("oeste","./hab8_1");
    AddExit("sur","./ckol2");
    AddItem(PNJ("simauria/berat/marino"),REFRESH_DESTRUCT,d2());
    AddDoor("oeste", "la puerta de una casa");
}

