/*
DESCRIPCION : callejuela
FICHERO     : /d/akallab/comun/habitacion/akallab/azzor/ciudad/calle01.c
MODIFICACION: 09-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create(){
 ::create();
SetIntShort("el extremo de una callejuela en el puerto de Azzor");
 SetIntLong(
  "La callejuela estrecha y sucia en la que te encuentras sigue "
    "avanzando a traves de los edificios de esta zona portuaria de "
    "la ciudad de Azzor. La callejuela parece acabar al este de aqui.\n");

 AddDetail(({"calle","callejuela"}),QueryIntLong());
 SetIndoors(0);

 AddExit("este",AZ_CIUDAD("calle00"));
 AddExit("oeste",AZ_CAMINO("camino20"));
}
