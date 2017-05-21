/*
DESCRIPCION  : galeria de las cuevas troll
FICHERO      : /d/akallab/comun/habitacion/akallab/kuntz/cueva/galeria10.c
MODIFICACION : 03-12-99 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
#include "../sys/galeria.h"
inherit  K_CUEVA("galeria");

create() {
  ::create();
  HazDescr(GAL_NORMAL,0);
  SetIntBright(0);
  AddExit("suroeste",K_CUEVA("galeria13"));
  AddExit("sur",K_CUEVA("galeria11"));
  AddExit("norte",K_CUEVA("galeria09"));
}
