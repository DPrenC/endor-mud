/*
Nombre:         bayas.c
Localizacion:   Bosque de Zarkam.
Comentario:     Narcoticas.
*/

#include <herbs.h>

inherit HERB;

create() {
  ::create();
  SetShort("unas bayas rojas");
  SetLong("Unas cuantas bayas rojas de aspecto tentador.\n");
  SetIds(({"baya","bayas"}));
  SetAds(({"rojas","tentadoras"}));
  SetSmell("Tienen un aroma casi narcótico...\n");
  SetWeight(70);
  SetType("baya");
  SetClass(HERB_CLASS_NARCOTIC);
  SetPower(10);
}
