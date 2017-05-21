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
  SetIntLong("");

AddDetail (({"","",""}),"");

SetIntBright(20);
SetIntNoise("");
SetIntSmell("");
SetLocate("");
SetIndoors (0); /* 0 exterior; 1 interior */

AddExit("","");

}
