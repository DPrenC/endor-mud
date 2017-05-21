/*
DESCRIPCION  : trozo de cristal brillante
FICHERO      : /d/akallab/comun/objeto/otro/cristal.c
MODIFICACION : 19-05-98 [Elric@Simauria] Creacion
               28-10-99 [Angor@Simauria] modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
#include <properties.h>
inherit THING;

create () {
  ::create();
  SetShort("extraño cristal ambar");
  SetLong(
    "Es un raro cristal de color ambar. Es bastante brillante y atractivo, "
      "aunque no crees que tenga mucha utilidad tal vez podría valer algo.\n");
  SetIds(({"cristal","ambar"}));
  SetWeight(100);
  SetValue(1000);
}
