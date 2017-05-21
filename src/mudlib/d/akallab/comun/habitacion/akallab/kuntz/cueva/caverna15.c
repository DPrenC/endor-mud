/*
DESCRIPCION  : Gran Caverna, mivel inferior
FICHERO      : /d/akallab/comun/rooms/akallab/kuntz/cueva/caverna15.c
MODIFICACION : 22-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
inherit K_CUEVA("caverna");

create() {
  piso=0;
  ::create();
 SetIntLong(QueryIntLong()+
  "Una galeria parte de aqui hacia el nordeste y una escalera permite "
    "subir al nivel superior.\n");

  AddExit("oeste",K_CUEVA("caverna14"));
  AddExit("sudeste",K_CUEVA("caverna08"));
  AddExit("arriba",K_CUEVA("caverna07"));
  //AddExit("nordeste",K_CUEVA("galeria05"));
  AddExit("sur",K_CUEVA("suelo01"));
}
