/**
 * /torrewiz/piso3/center.c
 */

#include "path.h"
inherit ROOM;

create() {
    ::create();

    SetIntShort("la tercera planta de la Torre de Magia");
    SetIntLong(
"Estás en la tercera planta de la Torre de la Magia. La habitacion está "
"iluminada por una luz cálida, y a tu alrededor ves los aposentos personales "
"de los Archs de Simauria, perfectamente diferenciados por grandes letreros con "
"el nombre de cada uno de ellos sobre las puertas. "
"Unas escaleras suben desde el segundo piso y continuan ascendiendo hasta el "
"cuarto.\n");

    SetIntBright(70);
    SetIndoors(1);

    AddExit("arriba", TORRE("piso4/center"));
    AddExit("abajo",  TORRE("piso2/center"));

    // AddExit(<nombre>, TORRE("rooms/<nombre>/workroom"));
}
