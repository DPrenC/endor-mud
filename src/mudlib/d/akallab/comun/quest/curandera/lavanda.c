/*
DESCRIPCION    : planta de lavanda para el queste de la curandera
FICHERO        : /d/akallab/comun/quest/curandera/lavanda.c
MODIFICACION   : 19-02-99 [Angor@Simauria].
*/

#include "path.h"
#include AK_MACRO

#include <herbs.h>

inherit HERB;

create() {
  ::create();
  SetShort("un matojo de lavanda");
  SetLong(
  "Es un matojo de ramas de lavanda, una planta de agradable aroma y "
    "flores de un tono morado apagado. Con esta planta se hacen perfumes "
    "y algunas pociones.\n");
  AddId(({"lavanda","matojo","cur_quest_03"}));
  SetSmell("La lavanda desprende un agradable aroma.\n");
  SetWeight(100);
  SetClass(HERB_CLASS_MAGIC);
  SetPower(25+random(10)); //poco
  SetValue(25);
}
