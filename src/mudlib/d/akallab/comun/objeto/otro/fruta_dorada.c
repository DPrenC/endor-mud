/*
Nombre:         fruta_dorada.c
Localizacion:   Bosque de Zarkam.
Comentario:     Recupera 150 puntos de magia.
*/

#include <herbs.h>
inherit HERB;

create() {
  ::create();
  SetShort("fruto dorado");
  SetLong("Un extranyo fruto dorado por el que muchos matarian.\n");
  SetIds(({"fruta","fruto","frt"}));
  SetAds(({"dorado""extranyo","extraño"}));
  SetSmell("Tiene un aroma magico...\n");
  SetWeight(70);
  SetType("fruto");
  SetClass(HERB_CLASS_MAGIC);
  SetPower(150);
}
