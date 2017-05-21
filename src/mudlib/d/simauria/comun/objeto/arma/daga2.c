inherit WEAPON;
#include <combat.h>
#include <properties.h>
#include <materials.h>

create() {
  ::create();
  SetStandard(WT_CUCHILLO, 2, P_SIZE_MEDIUM, M_ACERO);
  SetAds(({"una","pequenya","pequeña"}));
  SetIds(({"daga","arma"}));
  SetShort("una daga");
  SetLong(
"Es una pequeña daga de brillante hoja corta y afilada. La hoja representa\n\
una cabeza de halcón y está hecha de asta de ciervo.\n");
SetValue(QueryValue()*2);
SetDamType(DT_PIERCE);
Set(P_GENDER,GENDER_FEMALE);
}
