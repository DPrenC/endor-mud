/*
Nombre:         fruta_plata.c
Localizacion:   Tienda de Bosque de Nyne.
Comentario:     Recupera mogollon puntos de magia.
*/

#include <herbs.h>

inherit HERB;

create() {
  ::create();

  SetShort("fruta plateada");
  SetLong("Una extranya fruta plateada.\n");
  SetIds(({"fruta"}));
  SetAds(({"plateada"}));
  SetSmell("Tiene un aroma magico...\n");
  SetWeight(210);
  SetType("fruto");
  SetClass(HERB_CLASS_MAGIC);
  SetPower(300);
  SetValue(45000);
}
