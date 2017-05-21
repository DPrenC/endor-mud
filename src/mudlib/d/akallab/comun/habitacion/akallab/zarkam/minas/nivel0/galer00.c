/*
DESCRIPCION  : galeria de las minas
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/mina/nivel0/galer00.c
MODIFICACION : 05-11-99 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
//#include Z_MINAS("std/galeria.h")
#include "../std/galeria.h"
inherit  Z_MINAS("std/galeria");

create() {
  ::create();
  HazDescr(GAL_NORMAL,1);
  SetIntBright(20);

  AddExit("norte",Z_MINAS("/nivel0/caverna7"));
  AddExit("suroeste",Z_MINAS("/nivel0/galer01"));
}
