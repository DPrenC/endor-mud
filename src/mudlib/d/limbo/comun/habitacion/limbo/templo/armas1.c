/*
DESCRIPCION  : Seccion de armas de filo en el edificio de suministros
FICHERO      : /d/limbo/comun/habitacion/limbo/templo/armas1.c
MODIFICACION : 03-10-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit TEMPLO("suministros");

create() {
  tipo="armas de filo";
  path=ARMA("");
  productos=(({"espada","daga","hacha","claymore"}));
  ::create();
  AddExit("norte",TEMPLO("entrada_sum"));
  AddExit("sur",TEMPLO("armas2"));
  AddExit("oeste",TEMPLO("proteccion"));
}
