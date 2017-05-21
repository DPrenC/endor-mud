/*
DESCRIPCION  : calle golduin
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/cgold3.c
*/
#include "./path.h"
inherit SIM_ROOM;

create() {
    ::create();
    SetLocate("Berat");
    SetIntShort("la calle Golduin");
    SetIntLong("Est�s en la calle Golduin, la calle m�s nueva de Berat. "
    "Las piedras que forman el camino apenas est�n desgastadas, y todav�a "
    "se mueven. La calle contin�a al este y al oeste, quedando cortada al "
    "norte por una densa maleza, parece que la construcci�n de nuevos caminos "
    "es fruto de la rapida expansi�n del pueblo. Al sur se ven algunas casas.\n");
    SetIntNoise("Escuchas el bullicio t�pico de un pueblo como Berat.\n");
    SetIntSmell("Huele a hierba.\n");
    SetIndoors(0);
    AddDetail(({"camino","calle"}),"Es la calle m�s nueva del pueblo, "
    "las piedras que lo forman no est�n casi desgastadas.\n");
    AddDetail(({"casas","casa"}),"Parecen unas casas bastante altas "
    "pero muy sencillas.\n");
    AddDetail("piedras","Son piedras planas apenas desgastadas.\n");
    AddDetail("maleza","Las ramas y hojas impiden el paso.\n");
    AddExit("este","./cprin1");
    AddExit("oeste","./cgold2");
    AddItem(PNJ("simauria/berat/alana"), REFRESH_DESTRUCT, 1);
}

