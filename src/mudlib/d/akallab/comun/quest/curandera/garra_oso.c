/*
DESCRIPCION  : garra de oso gris para el quest de la curandera
FICHERO      : /d/akallab/comun/quest/curandera/garra_oso.c
MODIFICACION : 23-02-99 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

inherit THING;
#include "path.h"
#include AK_MACRO
#include <properties.h>

create() {
  ::create();
  AddId("garra");
  AddId("garra de oso");
  AddId("cur_quest_09");
  SetShort("una garra de oso");
  SetLong(
  "Es una larga y fuerte garra de oso. Por su tamanyo dirias que "
    "pertenecio a un oso bastante grande.\n");
  SetWeight(500);
  SetValue(80);
}

