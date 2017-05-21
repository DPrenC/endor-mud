/*
DESCRIPCION    : planta de tomillo para el queste de la curandera
FICHERO        : /d/akallab/comun/quest/curandera/tomillo.c
MODIFICACION   : 19-02-99 [Angor@Simauria].
*/

#include "path.h"
#include AK_MACRO

#include <herbs.h>

inherit HERB;

create() {
  ::create();
  SetShort("unas ramas de tomillo");
  SetLong(
  "Son varias ramas de tomillo. Esta planta tiene unos tallos asperos "
    "con hojas de pequenyo tamanyo y desprende un intenso aunque "
     "agradable olor. La gente suele utilizar esta planta para aromatizar "
     "algunas comidas.\n");
  AddId(({"ramas de tomillo","tomillo","cur_quest_05"}));
  SetSmell("El tomillo desprende un fuerte y agradable olor.\n");
  SetWeight(100);
  SetClass(HERB_CLASS_MAGIC);
  SetPower(25+random(10)); //poco
  SetValue(25);
}
