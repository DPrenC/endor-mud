/*
DESCRIPCION  : calle principal
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/cprin6.c

*/
#include "./path.h"
inherit SIM_ROOM;
create() {
    ::create();
    SetLocate("Berat");
    SetIntShort("la calle principal");
    SetIntLong("Estás en la calle principal de Berat. En este punto se "
    "une al este con la calle Byrson, una de las mas pequeñas de la zona.\n "
    "La calle principal continúa al sur hacia el puerto y al norte hacia la salida "
    "del pueblo.\n");
    SetIndoors(0);
    SetIntNoise("Se escucha el bullicio típico de los pueblos comerciantes.\n");
    AddDetail(({"camino","calle"}),"Es la calle mas grande de Berat"
    " y las piedras que lo forman están muy desgastadas.\n");
    AddDetail("piedras","Son cantos rodados, muy desgastados.\n");

    AddExit("norte","./cprin5");
    AddExit("sur","./cprin7");
    AddExit("este","./calle3");
    AddItem(PNJ("simauria/berat/marino"),REFRESH_DESTRUCT,d2());
}

