/*
DESCRIPCION  : Seccion de protecciones en el edificio de suministros
FICHERO      : /d/limbo/comun/habitacion/limbo/templo/proteccion.c
MODIFICACION : 03-10-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit TEMPLO("suministros");

create() {
  tipo="protecciones";
  path=PROT("");
  productos=(({"escudo","coraza","guantes","casco"}));
  ::create();
  amedida=1;
  AddExit("norte",TEMPLO("magia"));
  AddExit("sur",TEMPLO("armas3"));
  AddExit("este",TEMPLO("armas1"));
  AddExit("oeste",TEMPLO("util"));
}
