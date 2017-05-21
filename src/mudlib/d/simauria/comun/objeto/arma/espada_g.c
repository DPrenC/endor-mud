inherit WEAPON;
#include <combat.h>
#include <properties.h>
#include <materials.h>

create() {
  ::create();
  SetStandard(WT_ESPADA, 5, P_SIZE_LARGE, M_ACERO);
  SetAds(({"una","ancha","gran","grande"}));
  SetIds(({"espada","arma"}));
  SetShort("una espada ancha grande.");
  SetLong(
"Es una espada ancha grande.\n");
SetValue(QueryValue()*2);
SetDamType(DT_SLASH);
Set(P_GENDER,GENDER_FEMALE);
}
