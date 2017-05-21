/*
DESCRIPCION  : Un fruto de mandragora para el quest de la curandera
FICHERO      : /d/akallab/comun/quest/curandera/mandragora.c
MODIFICACION : 14-02-99 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

#include <herbs.h>

inherit HERB;

create() {
  ::create();

  SetShort("un fruto de mandragora");
  SetLong("Es una especie de grueso fruto con forma de huevo y mal olor.\n");
  AddId(({"fruto","mandragora","cur_quest_02"}));
  AddAdjective(({"grues","maloliente"}));
  SetSmell("El fruto de la mandragora tiene un olor desagradable.\n");
  SetWeight(200);
  SetClass(HERB_CLASS_NARCOTIC);
  SetPower(random(100));
  SetValue(QueryPowerNumber());
}
