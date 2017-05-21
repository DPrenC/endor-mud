/*
DESCRIPCION  : calle principal
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/cprin5.c
MODIFICACION : 28-10-99 [icaro@simauria]creacion
[Mal]
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <sounds.h>
#include <door.h>
#include <scheduler.h>


inherit SIM_ROOM;

create() {
    ::create();
    SetLocate("Berat");
    SetIntShort("la calle principal");
    SetIntLong("Estás en la calle principal de Berat, la calle continua "
    "al oeste y al sur. Al norte se puede entrar al banco y al "
    "este ves la pared trasera del una de las tiendas.\n");
    SetIndoors(0);
    SetIntNoise("Escuchas el bullicio típico de los pueblos comerciantes.\n");
    AddDetail(({"camino","calle"}),"Es la calle mas grande de la ciudad"
    " y las piedras que lo forman estan muy desgastadas.\n");
    AddDetail("banco","Parece un edificio muy nuevo en comparación "
    "con el resto del pueblo.\n");
    AddDetail("piedras","Parecen cantos rodados, muy desgastados.\n");
    AddDetail("pared","No tiene nada en especial.\n");
    AddExit("norte","./bancoh");
    AddExit("sur","./cprin6");
    AddExit("oeste","./cprin4");
    AddDoor("norte", "la puerta del banco",
    "Es la puerta para entrar al banco de Berat.\n",
    ({"puerta", "puerta del banco", "puerta del norte"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"), P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
}

