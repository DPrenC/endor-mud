inherit WEAPON;
#include <combat.h>
#include <properties.h>
#include <materials.h>

create() {
  ::create();
  SetStandard(WT_ESPADA, 5, P_SIZE_MEDIUM, M_ACERO);
  SetAds(({"una","ancha"}));
  SetIds(({"espada","arma"}));
  SetShort("una espada");
  SetLong(
"Es una espada ancha, con una hoja brillante y corta. A lo largo de su hoja\n\
ves unas palabras en un idioma que no comprendes.\n");
SetValue(QueryValue()*2);
SetDamType(DT_SLASH);
Set(P_GENDER,GENDER_FEMALE);
}
