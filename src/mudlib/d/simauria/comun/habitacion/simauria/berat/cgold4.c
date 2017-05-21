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
    SetIntLong("Te encuentras en la calle Golduin, la calle m�s nueva de Berat. "
    "Esta calle bordea la parte norte del pueblo y contin�a de este a oeste. "
    "En el sur se ven distintas casas t�picas de la regi�n.\n");
    SetIntNoise("Escuchas el bullicio t�pico de un pueblo como Berat.\n");
    SetIntSmell("Huele a hierba.\n");
    AddDetail(({"camino","calle"}),"Como es la calle m�s nueva del pueblo, "
    "las piedras que lo forman no est�n casi desgastadas.\n");
    AddDetail(({"casas","casa"}),"Parecen unas casas bastante altas "
    "aunque sencillas.\n");
    AddDetail("piedras","Son piedras planas como las que se usan para pavimentar.\n");
    SetIndoors(0);
    AddExit("este","./cgold5");
    AddExit("oeste","./cprin1");
    AddItem(PNJ("simauria/berat/campes1"),REFRESH_DESTRUCT,1);
}

