/*
DESCRIPCION  : Seccion de armas de flecha en el edificio de suministros
FICHERO      : /d/limbo/comun/habitacion/limbo/templo/armas2.c
MODIFICACION : 03-10-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit TEMPLO("suministros");

create() {
  tipo="armas de flecha";
  //path=ARMA("");
  //productos=(({"arco","flechas","ballesta"}));
  ::create();
  AddExit("norte",TEMPLO("armas1"));
  AddExit("oeste",TEMPLO("armas3"));
}
