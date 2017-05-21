/*
DESCRIPCION  : armario de la posada
FICHERO      : /d/limbo/comun/objeto/otro/armario_posada.c
MODIFICACION : 03-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
//inherit THING;
inherit OTRO("cofre_posada");

create() {
  ::create();
  SetTipo("armario");
  SetEstado(0);
  SetRuido(75);
}
