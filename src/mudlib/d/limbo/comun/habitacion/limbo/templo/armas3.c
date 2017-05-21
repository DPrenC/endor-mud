/*
DESCRIPCION  : Seccion de armas varias en el edificio de suministros
FICHERO      : /d/limbo/comun/habitacion/limbo/templo/armas2.c
MODIFICACION : 03-10-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit TEMPLO("suministros");

create() {
  tipo="armas varias";
  path=ARMA("");
  productos=(({"latigo","cadena","vara"}));
  ::create();
  AddExit("este",TEMPLO("armas2"));
  AddExit("norte",TEMPLO("proteccion"));
  AddExit("oeste",TEMPLO("otras"));
}
