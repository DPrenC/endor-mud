/*
DESCRIPCION  : calle de las tabernas
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/ctab4.c
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
    SetIntLong("Estás en la calle de la sirena o calle de las tabernas.\n "
    "En este punto la calle se une con la calle del mercado al norte. Al "
    "este continúa la calle y al sur hay una taberna con un cartel a la entrada.\n "
    "Al oeste el camino parece estar en obras, debido a la rápida expansión "
    "de este pueblo.\n");
    SetIndoors(0);
    SetIntNoise("Escuchas el bullicio proveniente de la taberna.\n");
    AddDetail(({"camino","calle"}),"Es la calle más transitada de "
    "Berat, al oeste se ve que todavía esta en construcción.\n");
    AddDetail(({"letrero","cartel"}), "El cartel de la taberna.\n");
    AddDetail("taberna", "Has visto tabernas mejores, desde luego... Es un edificio "
    "de una sola planta y bastante ruinoso.\n");
    AddReadMsg(({"cartel", "letrero"}),   "En él puedes leer TABERNA EL PIRATA COJO.\n");
    AddExit("sur","./taberna1");
    AddExit("norte","./cmerc4");
    AddExit("este","./ctab3");
    AddDoor("sur", "la puerta de la taberna",
    "La puerta principal de la taberna, de madera vieja y sucia.\n",
    ({"puerta", "puerta del sur", "puerta de la taberna"}));
}


