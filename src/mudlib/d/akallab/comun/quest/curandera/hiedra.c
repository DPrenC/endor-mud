/*
DESCRIPCION  : Hiedra venenosa para el quest de la curandera
FICHERO      : /d/akallab/comun/quest/curandera/hiedra.c
MODIFICACION : 14-02-99 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

#include <herbs.h>

inherit HERB;

create() {
  ::create();

  SetShort("una hiedra");
  SetLong("La hiedra es una planta trepadora que crece apoyandose en los arboles.\n");
  AddId(({"hiedra","cur_quest_01"}));
  AddAdjective(({"trepadora"}));
  SetSmell("La hiedra tiene un olor suave.\n");
  SetWeight(100);
  SetClass(HERB_CLASS_POISONOUS);
  SetPower(random(25));
  SetValue(QueryPowerNumber());
}


