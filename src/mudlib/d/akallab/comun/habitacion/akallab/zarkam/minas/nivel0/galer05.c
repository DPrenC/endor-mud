/*
DESCRIPCION  : galeria de las minas
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/mina/nivel0/galer05.c
MODIFICACION : 05-11-99 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
//#include Z_MINAS("std/galeria.h")
#include "../std/galeria.h"
inherit  Z_MINAS("std/galeria");

create() {
  ::create();
  HazDescr(GAL_NORMAL,2);
  SetIntBright(0);

  AddExit("oeste",Z_MINAS("/nivel0/galer06"));
  AddExit("nordeste",Z_MINAS("/nivel0/galer04"));
}
