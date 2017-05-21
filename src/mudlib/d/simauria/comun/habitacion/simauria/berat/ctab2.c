/*
DESCRIPCION  : calle de las tabernas
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/ctab2.c
MODIFICACION : 28-10-99 [icaro@simauria]creacion
[Maler]
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <door.h>
#include <nightday.h>


inherit SIM_ROOM;
create() {
    ::create();
    SetLocate("Berat");
    SetIntShort("la calle de las tabernas");
    SetIntLong("Estás en la calle de la sirena o calle de las tabernas, "
    "esta es la calle preferida por comerciantes y marineros para descansar "
    "tras un largo viaje.\n La calle continúa al este y al oeste, mientras "
    "que al norte encontramos la casa de algún mercader y al sur una taberna "
    "con un cartel en la entrada.\n");
    SetIndoors(0);
    AddDetail(({"camino","calle"}),"Es la calle más transitada de "
    "Berat, está bastante sucia y mal iluminada.\n");
    AddReadMsg(({"letrero", "cartel"}),"En él puedes leer: TABERNA ROSA DE LOS VIENTOS.\n");
    AddDetail(({"cartel", "letrero"}), "El cartel de la taberna del sur.\n");
    AddExit("sur","./taberna2");
    AddExit("norte","./hab3_1");
    AddExit("oeste","./ctab3");
    AddExit("este","./ctab1");
    AddDoor("norte", "la puerta de una casa");
    AddDoor("sur", "la puerta de la taberna",
    "Es la puerta de la taberna Rosa de los Vientos.\n",
    ({"puerta", "puerta del sur", "puerta de la taberna"}),
    ([P_DOOR_CLOSE_TIME : ND_NIGHT]));
}

