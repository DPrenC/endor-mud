/* Fichero: alfanje.c */

#include <combat.h>
#include <properties.h>
inherit WEAPON;
create() {
  ::create();
  SetStandard(WT_CIMITARRA, 6, P_SIZE_LARGE, M_ACERO);
  SetAds(({"ligero","afilado", "curvo", "de acero"}));
  SetIds(({"alfanje","arma","cimitarra"}));
  SetShort("un alfanje");
  SetLong(
"Es una ligera espada de hoja curva, muy estrecha en la base, pero bastante "
"ancha en la punta.\n");
    Set(P_GENDER, GENDER_MALE);
    }
