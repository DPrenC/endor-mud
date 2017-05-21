inherit WEAPON;
#include <combat.h>
#include <properties.h>
#include <materials.h>

create() {
  ::create();
  SetStandard(WT_CUCHILLO, 1, P_SIZE_SMALL, M_PLATA);
  SetAds(({"una","pequenya","pequeña"}));
  SetIds(({"daga","arma"}));
  SetShort("una daga");
  SetLong(
"Es un afilado cuchillo plateado. El mango es de acero recubierto de piel gruesa.\n");
SetValue(QueryValue()*5);
SetDamType(DT_PIERCE);
Set(P_GENDER,GENDER_FEMALE);
}
