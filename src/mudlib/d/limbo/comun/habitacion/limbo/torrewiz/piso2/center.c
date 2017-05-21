/**
 * /torrewiz/piso2/center.c
 */

#include "path.h"
inherit ROOM;

create() {
    ::create();

    SetIntShort("la segunda planta de la Torre de Magia");
    SetIntLong(
"Has llegado al segundo piso de la Torre de la Magia. La habitacion está "
"iluminada por una luz cálida, y a tu alrededor ves habitaciones "
"pertenecientes a cada uno de los "
"Lords y Vicelords de Simauria, perfectamente diferenciadas por grandes letreros con "
"el nombre de cada uno de ellos sobre las puertas. Al sur está la "
"sala de control de los dominios. "
"Unas escaleras suben desde el primer piso y continuan ascendiendo hacia el "
"tercero.\n");

    SetIntBright(70);
    SetIndoors(1);

    AddExit("arriba", TORRE("piso3/center"));
    AddExit("abajo",  TORRE("piso1/center"));
    AddExit("sur",    TORRE("piso2/domainmanager"));
    AddExit("ratwor", TORRE("rooms/ratwor/workroom"));
    AddExit("yalin", TORRE("rooms/yalin/workroom"));
    AddExit("tagoras", TORRE("rooms/tagoras/workroom"));
    // AddExit(<nombre>, TORRE("rooms/<nombre>/workroom"));
    AddDoor("ratwor", "una puerta oscura",
    "Es una puerta de madera oscura, suave y reluciente, sin ningún adorno.\n",
    ({"puerta", "puerta oscura", "puerta de madera", "puerta de ratwor"}));
                            AddDoor("yalin","una puerta verde",
        "Es una puerta de roble, pintada de verde.\nEs austera y fría, sin adornos ni "
            "grabados. Casi da la impresión de ser de una celda, o un velatorio.\n",
        ({"puerta verde","puerta yalin","puerta Yalin","puerta de yalin","puerta de Yalin"}));
}
