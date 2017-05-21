/*
DESCRIPCION  : pluma de cuervo para el quest de la curandera
FICHERO      : /d/akallab/comun/quest/curandera/pluma.c
MODIFICACION : 24-02-99 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

inherit THING;
#include "path.h"
#include AK_MACRO
#include <properties.h>

create() {
  ::create();
  AddId("pluma");
  AddId("pluma de cuervo");
  AddId("cur_quest_10");
  SetShort("una pluma de cuervo");
  SetLong("Es una larga y negra pluma de cuervo. Es suave y apenas pesa.\n");
  SetWeight(10);
  SetValue(5);
}

