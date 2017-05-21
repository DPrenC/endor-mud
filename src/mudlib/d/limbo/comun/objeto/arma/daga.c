/*
DESCRIPCION  : Daga
FICHERO      : /d/limbo/comun/objeto/arma/daga.c
MODIFICACION : 03-10-98 [Angor@Simauria] Creacion.
               28-09-99 [Mirill@Simauria] Adapatación al nuevo combat.c
--------------------------------------------------------------------------------
*/

inherit WEAPON;
#include <combat.h>
#include <properties.h>

create() {
  ::create();
  SetStandard(WT_CUCHILLO,1,P_SIZE_GENERIC,M_ACERO);
  SetAds(({"una","pequenya","pequeña"}));
  SetIds(({"daga","arma"}));
  SetShort("una daga");
  SetLong("Es una pequeña daga de brillante hoja corta y afilada.\n");
  SetValue(2);
  Set(P_GENDER, GENDER_FEMALE);
  SetResetQuality(95);
  SetNumberHands(1);
  Set(P_NOSELL,1);
}
