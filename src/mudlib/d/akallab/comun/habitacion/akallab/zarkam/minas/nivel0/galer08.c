/*
DESCRIPCION  : galeria de las minas
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/mina/nivel0/galer08.c
MODIFICACION : 05-11-99 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
#include "../std/galeria.h"
inherit  Z_MINAS("std/galeria");

create() {
  ::create();
  HazDescr(GAL_NORMAL,1);
  SetIntBright(0);

  AddExit("este",Z_MINAS("/nivel0/galer07"));
  //AddExit("sur",Z_MINAS("/nivel0/galer09"));
  //AddExit("noroeste",Z_MINAS("/nivel0/galer10"));
}
