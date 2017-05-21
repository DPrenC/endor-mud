/**
 * /torrewiz/piso1/center.c
 */

#include "path.h"
inherit ROOM;

create() {
	::create();

    SetIntShort("la primera planta de la Torre de Magia");
	SetIntLong(
"Has llegado al primer piso de la Torre de la Magia. La habitacion está "
"iluminada por una luz cálida, y a tu alrededor ves habitaciones "
"pertenecientes a cada uno de los "
"wizards de Simauria, perfectamente diferenciadas por grandes letreros con "
"el nombre de cada uno de ellos sobre las puertas. "
"Unas escaleras suben desde la entrada y continuan ascendiendo hacia el "
"segundo.\n");

    SetIntBright(70);
    SetIndoors(1);

    AddExit("arriba", TORRE("piso2/center"));
    AddExit("abajo",  TORRE("hall"));
    // AddExit(<nombre>, TORRE("rooms/<nombre>/workroom"));
}