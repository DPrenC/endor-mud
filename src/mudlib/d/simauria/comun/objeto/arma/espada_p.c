inherit WEAPON;
#include <combat.h>
#include <properties.h>
#include <materials.h>

create() {
  ::create();
  SetStandard(WT_ESPADA, 5, P_SIZE_SMALL, M_ACERO);
  SetAds(({"una","ancha","pequeña"}));
  SetIds(({"espada","arma"}));
  SetShort("una espada ancha pequeña.");
  SetLong(
"Es una espada ancha pequeña.\n");
SetValue(QueryValue()*2);
SetDamType(DT_SLASH);
Set(P_GENDER,GENDER_FEMALE);
}
