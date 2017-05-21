/*
DESCRIPCION    : planta de romero para el queste de la curandera
FICHERO        : /d/akallab/comun/quest/curandera/romero.c
MODIFICACION   : 19-02-99 [Angor@Simauria].
*/

#include "path.h"
#include AK_MACRO

#include <herbs.h>

inherit HERB;

create() {
  ::create();
  SetShort("unas ramas de romero");
  SetLong(
  "Son varias ramas de romero. Los tallos estan resecos pero despreenden "
    "un fuerte y agradable olor que se te queda impregnado en las manos. "
    "Esta planta se utiliza en la cocina y tambien para hacer perfumes.\n");
  AddId(({"ramas de romero","romero","cur_quest_04"}));
  SetSmell("El romero desprende un fuerte y agradable olor.\n");
  SetWeight(100);
  SetClass(HERB_CLASS_MAGIC);
  SetPower(25+random(10)); //poco
  SetValue(25);
}
