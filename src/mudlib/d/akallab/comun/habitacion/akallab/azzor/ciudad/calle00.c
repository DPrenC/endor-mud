/*
DESCRIPCION : callejuela
FICHERO     : /d/akallab/comun/habitacion/akallab/azzor/ciudad/calle00.c
MODIFICACION: 09-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create(){
 ::create();
SetIntShort("el extremo de una callejuela en el puerto de Azzor");
 SetIntLong(
  "Este es el extremo de una callejuela que parte del muelle "
    "del puerto que se halla al este, adentrándose en la ciudad "
    "de Azzor. Es una callejuela estrecha y más bien sucia con "
    "el suelo de tierra.\n");

 AddDetail(({"calle","callejuela"}),QueryIntLong());

 SetIndoors(0);

 AddItem(PNJ_AZZOR("manak"),REFRESH_DESTRUCT);
 AddExit("norte",AZ_PUERTO("portico03"));
 AddExit("este",AZ_PUERTO("muelle00"));
 AddExit("sur",AZ_PUERTO("portico04"));
 AddExit("oeste",AZ_CIUDAD("calle01"));
}
