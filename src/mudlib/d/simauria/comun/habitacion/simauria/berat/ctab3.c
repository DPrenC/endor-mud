/*
DESCRIPCION  : calle de las tabernas
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/ctab3.c
MODIFICACION : 28-10-99 [icaro@simauria]creacion
[Maler]
--------------------------------------------------------------------------------
*/
#include "./path.h"
inherit SIM_ROOM;
create() {
    ::create();
    SetLocate("Berat");
    SetIntShort("la calle de las tabernas");
    SetIntLong("Estás en la calle de la sirena o calle de las tabernas. "
    "La calle continua al este y al oeste. Al norte ves una taberna con "
    "un cartel a la entrada, y al sur la entrada a una casa. Esta zona de "
    "la calle está especialmente sucia, muy probablemente por la clientela "
    "de la taberna.\n");
    SetIndoors(0);
    AddDetail(({"camino","calle"}),"Es la calle más transitada de "
    "Berat, está bastante sucia, en especial esta zona.\n");
    AddDetail(({"letrero","cartel"}), "El cartel de la taberna del norte");
    AddReadMsg(({"cartel", "letrero"}), "En él puedes leer: TABERNA LA SERPIENTE MARINA.\n");

    AddExit("sur","./hab7_1");
    AddExit("norte","./taberna3");
    AddExit("oeste","./ctab4");
    AddExit("este","./ctab2");
    AddItem(PNJ("simauria/berat/guardia"),REFRESH_DESTRUCT,d2());
    AddDoor("sur", "la puerta de una casa");
    AddDoor("norte", "la puerta de la taberna",
    "Es la puerta que da a la calle de las tabernas, se nota que ha sido arreglada "
    "multitud de veces.\n",
    ({"puerta", "puerta de la calle", "puerta de salida", "puerta del sur"}));
}

