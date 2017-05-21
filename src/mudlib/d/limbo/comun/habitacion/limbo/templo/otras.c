/*
DESCRIPCION  : Seccion de otras cosas en el edificio de suministros
FICHERO      : /d/limbo/comun/habitacion/limbo/templo/otras.c
MODIFICACION : 03-10-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit TEMPLO("suministros");

create() {
  tipo="otras cosas";
  path=OTRO("");
  productos=(({"dado"}));
  ::create();
  AddExit("este",TEMPLO("armas3"));
  AddExit("norte",TEMPLO("util"));
}
