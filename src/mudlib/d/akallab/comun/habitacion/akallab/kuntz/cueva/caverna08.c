/*
DESCRIPCION  : Gran Caverna, mivel inferior
FICHERO      : /d/akallab/comun/rooms/akallab/kuntz/cueva/caverna08.c
MODIFICACION : 22-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit K_CUEVA("caverna");

create() {
  piso=0;
  ::create();

  AddExit("oeste",K_CUEVA("suelo01"));
  AddExit("este",K_CUEVA("casa05"));
  AddExit("sur",K_CUEVA("caverna09"));
  AddExit("noroeste",K_CUEVA("caverna15"));
}
