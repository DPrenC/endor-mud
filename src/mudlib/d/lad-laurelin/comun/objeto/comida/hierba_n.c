/*
DESCRIPCION  : Hierba narcotica
FICHERO      : /d/limbo/comun/objeto/hierba/hierba_narcotica.c
MODIFICACION : 13-01-97 [Angor@Simauria] Creacion.
               11-11-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include <herbs.h>

inherit HERB;

create() {
  ::create();

  AddId(({"hierbas","hierbas verdes","hierbas de color verde"}));
  AddAdjective(({"verdes","de coor verde"}));
  SetShort("algunas hierbas de color verde oscuro");
  SetLong("Algunas hierbas de color verde oscuro con un olor agradable.\n");
  SetSmell("Tienen un olor parecido al de las flores.\n");
  SetWeight(100);
  SetClass(HERB_CLASS_TOXIC);
  SetPower(random(100));
  SetValue(QueryPowerNumber());
}


