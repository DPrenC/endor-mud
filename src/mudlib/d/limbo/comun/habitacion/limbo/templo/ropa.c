/*
DESCRIPCION  : Seccion de ropa en el edificio de suministros
FICHERO      : /d/limbo/comun/habitacion/limbo/templo/ropa.c
MODIFICACION : 03-10-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

// NOTA: La ropas son protecciones que adornan mas que proteger

#include "./path.h"
inherit TEMPLO("suministros");

create() {
  tipo="ropa";
  path=PROT("");
  productos=(({"sombrero","capa","pantalon","camisa"}));
  ::create();
  amedida=1;
  AddExit("norte",TEMPLO("medicina"));
  AddExit("sur",TEMPLO("util"));
  AddExit("este",TEMPLO("magia"));
}
