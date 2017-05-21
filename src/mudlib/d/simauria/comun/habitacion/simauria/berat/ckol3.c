/*
DESCRIPCION  : calle koldar
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/ckol3.c
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
    "del pueblo. La calle continúa al norte y al sur, un riachuelo "
    "recorre la misma dirección por el este del camino, y ves una "
    "casa en construcción al oeste.\n");
    SetIndoors(0);
    SetIntNoise("Escuchas el murmullo del riachuelo.\n");
    AddDetail(({"camino","calle"}),"Es la calle más bella del pueblo "
    "y tambien la más tranquila y solitaria.\n");
    AddDetail(({"casas","casa"}),"Son unas casas bastante normales.\n");
    AddDetail(({"rio", "río","riachuelo"}),"Es uno de los riachuelos que forman el "
    "delta en el que se encuentra Berat .\n");
    AddExit("norte","./ckol2");
    AddExit("oeste","./cons1");
    AddExit("sur","./ckol4");
}

