/*
DESCRIPCION  : Seccion de bebida en el edificio de suministros
FICHERO      : /d/limbo/comun/habitacion/limbo/templo/bebida.c
MODIFICACION : 22-09-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit TEMPLO("suministros");

create() {
  tipo="bebida";
  path=BEBIDA("");
  productos=(({"cerveza","agua","vino","zumo"}));
  ::create();
  AddExit("sur",TEMPLO("magia"));
  AddExit("oeste",TEMPLO("medicina"));
  AddExit("este",TEMPLO("comida"));
}

