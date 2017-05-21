/*
DESCRIPCION  : Hierba intoxicante
FICHERO      : /d/lad-laurelin/comun/objeto/comida/hierba_c
MODIFICACION : 13-01-97 [Angor@Simauria] Creacion.
               11-11-98 [Angor@Simauria] Varias modificaciones
			   16-02-99 [Alura] modifica para que sea curativa el hierba_intoxicante.c
--------------------------------------------------------------------------------
*/

#include <herbs.h>

inherit HERB;

create() {
  ::create();

  AddId(({"hierbas","hierbas grises","hierbas de color gris"}));
  AddAdjective(({"grises","de color grisaceo"}));
  SetShort("algunas hierbas grises con brotes");
  SetLong("Algunas perfumadas hierbas grises con brotes.\n");
  SetSmell("No identificas su olor, pero te gusta como huele.\n");
  SetWeight(100);
  SetClass(HERB_CLASS_HEALING);
  SetPower(random(200));
  SetValue(QueryPowerNumber());
}


