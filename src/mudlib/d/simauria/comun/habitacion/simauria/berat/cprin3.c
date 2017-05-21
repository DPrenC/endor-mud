/*
DESCRIPCION  : calle principal
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/cprin3.c
MODIFICACION : 28-10-99 [icaro@simauria]creacion
[Mal]
--------------------------------------------------------------------------------
*/
#include "./path.h"
inherit SIM_ROOM;

create() {
    ::create();
    SetLocate("Berat");
    SetIntShort("la calle principal");
    SetIntLong("Est�s en la calle principal de Berat, la calle contin�a "
    "al norte hacia un gran edificio, y al sur en direcci�n a la salida del pueblo.\n"
    "Al oeste se puede entrar a la casa de alg�n comerciante.\n");
    SetIndoors(0);
    SetIntNoise("Escuchas el bullicio t�pico de los pueblos comerciantes.\n");
    AddDetail(({"camino","calle"}),"Es la calle mas grande de Berat"
    " y las piedras que lo forman estan muy desgastadas.\n");
    AddDetail("casa","Parece una casa bastante vieja en "
    "comparacion con el resto.\n");
    AddDetail("piedras","Parecen cantos rodados, muy desgastados.\n");

    AddExit("norte","./cprin2");
    AddExit("sur","./cprin4");
    //AddExit("este","/d/simauria/comun/habitacion/simauria/berat/bancoh");
    AddExit("oeste","./hab2_1");
    AddDoor("oeste", "la puerta de una casa");
    AddItem(PNJ("simauria/berat/guardia"),REFRESH_DESTRUCT,d2());
}

