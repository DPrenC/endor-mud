inherit WEAPON;
#include <combat.h>
#include <properties.h>
#include <materials.h>

create() {
  ::create();
  SetStandard(WT_ESPADA, 10, P_SIZE_MEDIUM, M_ACERO);
  SetAds(({"una","tosca","pesada"}));
  AddId(({"claymore","arma","espada"}));
  SetShort("una claymore");
  SetLong(
"Es una pesada espada de hoja recta, de la que sobresalen dos largas hojas\n\
orientadas oblicuamente. En general parece algo tosca, pero es efectiva.\n");
  SetResetQuality(85);
}
