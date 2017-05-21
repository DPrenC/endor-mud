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
SetIntShort("el cruce entre Calle Hirak y Calle El Anochecer");
SetIntLong("");

AddDetail (({"","",""}),"");

SetIntNoise("");
SetIntSmell("");
SetLocate("");
SetIndoors (0); /* 0 exterior; 1 interior */

AddExit("sur",TCSUELO("anoch1"));
AddExit("este",TCSUELO("hirak2"));

}