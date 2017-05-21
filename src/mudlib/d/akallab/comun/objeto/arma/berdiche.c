inherit WEAPON;
#include <combat.h>
#include <properties.h>
#include <materials.h>

create() {
  ::create();
  SetStandard(WT_HACHA, 12, P_SIZE_MEDIUM, M_ACERO);
  SetAds(({"una","pesada"}));
  SetIds(({"berdiche","arma","hacha"}));
  SetShort("una berdiche");
  SetLong(
"Es una gran hacha con una solida hoja de hierro de unos 80 cm de largo,\n\
empotrada en una larga asta de roble que mide casi 2 metros de largo.\n\
Es sin duda un arma efectiva en las manos adecuadas.\n");
  SetWeight(7800);
  SetResetQuality(95);
  SetNumberHands(2);
}
