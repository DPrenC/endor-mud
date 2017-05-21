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
SetIntShort("un calabozo del Arbol de la Vida");
SetIntLong("");

AddDetail (({"","",""}),"");

SetIntBright(20);
SetIntNoise("");
SetIntSmell("");
SetLocate("");
SetIndoors (0); /* 0 exterior; 1 interior */

AddExit("sur", TASOTANO("pasillo1"));

/* AddDoor("p1", "sur", TASOTANO("pasillo1"),"puerta","La puerta da al pasillo. ",0,1); */
}