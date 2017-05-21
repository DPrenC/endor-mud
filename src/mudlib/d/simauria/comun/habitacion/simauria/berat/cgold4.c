/*
DESCRIPCION  : calle golduin
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/cgold4.c
*/
#include "./path.h"
inherit SIM_ROOM;

create() {
    ::create();
    SetLocate("Berat");
    SetIntShort("la calle Golduin");
    SetIntLong("Te encuentras en la calle Golduin, la calle más nueva de Berat. "
    "Esta calle bordea la parte norte del pueblo y continúa de este a oeste. "
    "En el sur se ven distintas casas típicas de la región.\n");
    SetIntNoise("Escuchas el bullicio típico de un pueblo como Berat.\n");
    SetIntSmell("Huele a hierba.\n");
    AddDetail(({"camino","calle"}),"Como es la calle más nueva del pueblo, "
    "las piedras que lo forman no están casi desgastadas.\n");
    AddDetail(({"casas","casa"}),"Parecen unas casas bastante altas "
    "aunque sencillas.\n");
    AddDetail("piedras","Son piedras planas como las que se usan para pavimentar.\n");
    SetIndoors(0);
    AddExit("este","./cgold5");
    AddExit("oeste","./cprin1");
    AddItem(PNJ("simauria/berat/campes1"),REFRESH_DESTRUCT,1);
}

