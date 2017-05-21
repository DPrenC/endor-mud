/*
Nombre:         fruta_rara.c
Localizacion:   Tienda de Bosque de Nyne.
Comentario:     Recupera mogollon puntos de vida.
*/

#include <herbs.h>
inherit HERB;

create() {
  ::create();

  SetShort("fruta extraña");
  SetLong("Una extranya fruta.\n");
  SetIds(({"fruta"}));
  SetAds(({"extranya"}));
  SetSmell("Mmmm... Huele bien...\n");
  SetWeight(210);
  SetType("fruto");
  SetClass(HERB_CLASS_HEALING);
  SetPower(300);
  SetValue(55000);
}
