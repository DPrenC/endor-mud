/*
DESCRIPCION  : Seccion de medicina en el edificio de suministros
FICHERO      : /d/limbo/comun/habitacion/limbo/templo/medicina.c
MODIFICACION : 03-10-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit TEMPLO("suministros");

create() {
  tipo="medicina";
  path=BEBIDA("");
  productos=(({"jarabe"}));
  ::create();
  AddExit("sur",TEMPLO("ropa"));
  AddExit("este",TEMPLO("bebida"));
}
