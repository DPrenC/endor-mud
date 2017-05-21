inherit WEAPON;
#include <combat.h>
#include <properties.h>
#include <materials.h>

create() {
  ::create();
  SetStandard(WT_MAZA, 6, P_SIZE_MEDIUM, M_HIERRO);
  SetAds(({"un","ligero"}));
  SetIds(({"arma","maza","gargaz"}));
  SetShort("un gargaz");
  SetLong(
"Es una ligera maza con cabeza claveteada. Los clavos estan hacia afuera,\n\
lo que sin duda debe provocar heridas muy graves.\n");
  SetWeight(QueryWeight()-3000);
  SetDamType(DT_SLASH);
  Set(P_GENDER,GENDER_MALE);
  SetResetQuality(90);
}
