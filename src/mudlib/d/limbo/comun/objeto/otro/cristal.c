/*
DESCRIPCION  : trozo de cristal brillante
FICHERO      : /d/limbo/comun/objeto/otro/cristal.c
MODIFICACION : 02-11-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <properties.h>
inherit THING;

create () {
  ::create();
  SetShort("extranyo cristal ambar");
  SetLong(
    W("Es un raro cristal de color ambar. Es bastante brillante y atractivo, "
      "aunque no crees que tenga mucha utilidad tal vez podria valer algo.\n"));
  SetIds(({"cristal","ambar"}));
  SetWeight(100);
  SetValue(500);
}
