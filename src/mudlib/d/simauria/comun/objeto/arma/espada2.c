inherit WEAPON;
#include <combat.h>
#include <properties.h>
#include <materials.h>
#include "./path.h"
create() {
  ::create();
  SetStandard(WT_ESPADA, 7, P_SIZE_MEDIUM, M_ACERO);
  SetAds(({"una","larga"}));
  SetIds(({"espada","arma"}));
  SetShort("una espada larga");
  SetLong(W(
"Es una espada larga, forjada especialmente para los oficiales de la banda "
"de bandidos que habita en la fortaleza de Cored, al norte de Nandor.\n"));
SetDamType(DT_SLASH);
Set(P_GENDER,GENDER_FEMALE);
}
