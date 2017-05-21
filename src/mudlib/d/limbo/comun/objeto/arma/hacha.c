
/*
DESCRIPCION  : Hacha
FICHERO      : /d/limbo/comun/objeto/arma/hacha.c
MODIFICACION : 03-10-98 [Angor@Simauria] Creacion.
               28-09-99 [Mirill@Simauria] Adapatación al nuevo combat.c
--------------------------------------------------------------------------------
*/

inherit WEAPON;
#include <combat.h>
#include <properties.h>

create() {
  ::create();
  SetStandard(WT_HACHA,2,P_SIZE_GENERIC,M_ACERO);
  SetAds(({"un","gran"}));
  SetIds(({"hacha","arma"}));
  SetShort("un hacha");
  SetLong("Es un hacha de combate con una doble hoja ancha.\n");
  SetValue(25);
  Set(P_GENDER, GENDER_MALE);
  SetResetQuality(100);
  SetNumberHands(2);
  Set(P_NOSELL,1);
}
