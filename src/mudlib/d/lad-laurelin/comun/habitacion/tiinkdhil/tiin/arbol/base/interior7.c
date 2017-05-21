/*
DESCRIPCION  :
FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/
NOTAS:
MODIFICACION :
*/

#include "./path.h"

#include <properties.h>
#include <rooms.h>

inherit ROOM;

create() {
  ::create();
  SetIntShort("");
SetIntLong(
"Te encuentras en el pasillo interior de la base del Arbol de la Vida\n"
"Las paredes, el suelo, y el techo estan esculpidos en el mismo arbol.\n"
"Hay varias antorchas colgadas en la pard iluminando el ambiente. Al norte\n"
"ves una sala, en el resto de las direcciones el pasillo sigue.\n"
);

AddDetail (({"","",""}),"");

SetIntBright(20);
SetIntNoise("");
SetIntSmell("");
SetLocate("Arbol");
SetIndoors(1);

AddExit("norte",TABASE("centro1"));
AddExit("sur",TABASE("pasillo4"));
AddExit("este",TABASE("interior8"));
AddExit("oeste",TABASE("bajada1"));

}
