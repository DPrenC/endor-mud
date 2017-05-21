/*
DESCRIPCION  : calle principal
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/cprin2.c
MODIFICACION : 28-10-99 [icaro@simauria]creacion
[Mal]
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <colours.h>

inherit SIM_ROOM;

create() {
    ::create();
    SetLocate("Berat");
    SetIntShort("la calle principal");
    SetIntLong("Estás en la calle principal de Berat, al norte hay un "
    "cruce, mientras que al sur a lo lejos divisas el ayuntamiento. Al este "
    "ves un edificio que parece cerrado o que se entra por otra parte, y al oeste "
    "la casa de algún comerciante.\n");
    SetIndoors(0);
    SetIntNoise("Escuchas el bullicio típico de los pueblos comerciantes.\n");
    AddDetail(({"camino","calle"}),"Es la calle más grande de la ciudad"
    " y las piedras que lo forman están muy desgastadas.\n");
    AddDetail(({"edificio","este","edificio del este"}),
          "Se trata de un edificio de una sola planta. Aunque está en buen "
          "estado y no parece abandonado, la puerta de entrada tiene que estar por "
          "otra parte. En la pared hay un cartel.\n");
    AddDetail(({"cartel", "letrero"}),"Está a media altura para que se pueda leer bien.\n");
    AddReadMsg(({"letrero", "cartel"}), "En el cartel se lee: " +
          TC_RED + "'La oficina de la hermandad de consignas'\n Se entra por el banco."
          + TC_NORMAL + "\n");
    AddDetail("casa","Parece una casa bastante alta pero muy sencilla.\n");
    AddDetail("piedras","Parecen cantos rodados, muy desgastados.\n");
    AddExit("norte","./cprin1");
    AddExit("sur","./cprin3");
    //AddExit("este","./taquillas");
    AddExit("oeste","./hab1_1");
    AddDoor("oeste", "la puerta de una casa");
}

