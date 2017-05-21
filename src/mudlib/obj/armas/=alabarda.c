/* Fichero: alabarda.c */



#include <mud.h>
#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
  ::create();
  SetStandard(WT_ALABARDA, 10, P_SIZE_GENERIC, M_HIERRO);
  SetAds(({"una","pesada"}));
  SetIds(({"alabarda","arma","alabarda"}));
  SetShort("una alabarda");
  SetLong(
"Es una alabarda construida con gran solidez. Cualquier guardia desearía\n\
tener una así. Es sin duda un arma efectiva en las manos adecuadas.\n");
  Set(P_GENDER,GENDER_FEMALE);
  SetWeight(5500);
  SetNumberHands(2);
}
