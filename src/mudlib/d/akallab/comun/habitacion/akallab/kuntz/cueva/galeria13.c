/*
DESCRIPCION  : galeria de las cuevas troll
FICHERO      : /d/akallab/comun/habitacion/akallab/kuntz/cueva/galeria13.c
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
  AddExit("este",K_CUEVA("galeria11"));
  AddExit("sur",K_CUEVA("galeria14"));
  AddExit("oeste",K_CUEVA("galeria15"));
  AddExit("nordeste",K_CUEVA("galeria10"));
}
