/*
DESCRIPCION  : Seccion de comida en el edificio de suministros
FICHERO      : /d/limbo/comun/habitacion/limbo/templo/comida.c
MODIFICACION : 22-09-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit TEMPLO("suministros");

create() {
  tipo="comida";
  path=COMIDA("");
  productos=(({"manzana","naranja","lechuga","uvas"}));
  ::create();
  AddExit("sur",TEMPLO("entrada_sum"));
  AddExit("oeste",TEMPLO("bebida"));
}
