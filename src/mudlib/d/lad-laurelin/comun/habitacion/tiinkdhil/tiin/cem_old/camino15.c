/*
DESCRIPCION  :
FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/ camino15.c
NOTAS:
CREACION :  ALura (Julio del 2000)
*/

#include "./path.h"
#include <properties.h>
#include <rooms.h>

inherit ROOM;

create() {
  ::create();
SetIntShort("el camino del cementerio.");
SetIntLong(
"  En esta parte del cementerio no hay tumbas. Debe ser uno de los pocos sitios\n"
"tranquilos. Ves que el camino esta un poco más cuidado y que queda vegetación\n"
"viva, como arbustos y algún que otro viejo árbol.\n"
" Al sur ves las paredes del panteón.\n");

AddDetail (({"niebla"}),"  No hay restos de niebla.\n");

AddDetail (({"panteón"}),
"  Es una obra de arte gigantesca que destaca del cementerio porque no tiene la\n"
"misma fina y delicada estructura que el resto de lugares. Figuras como gárgolas\n"
"y otros horrorosos seres pueblan sus paredes.\n");

SetIntSmell("  Huele un poco mal, pero el olor no es muy fuerte.\n ");
SetLocate("Cementerio2");
SetIndoors (0); /* 0 exterior; 1 interior */
SetIntBright(25);

AddExit("suroeste","camino3");
AddExit("este","camino8");

}
