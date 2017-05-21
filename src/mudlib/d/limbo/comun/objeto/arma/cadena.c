/*
DESCRIPCION  : Cadena
FICHERO      : /d/limbo/comun/objeto/arma/cadena.c
MODIFICACION : 03-10-98 [Angor@Simauria] Creacion.
               28-09-99 [Mirill@Simauria] Adapatación al nuevo combat.c
--------------------------------------------------------------------------------
*/

inherit WEAPON;
#include <combat.h>
#include <properties.h>

create() {
  ::create();
  SetStandard(WT_CADENA,2,P_SIZE_GENERIC,M_HIERRO);
  SetAds(({"una","larga"}));
  SetIds(({"arma","cadena"}));
  SetShort("una cadena");
  SetLong("Es una cadena corriente de metal que puede ser usada como arma.\n");
  SetWeight(1500);
  SetValue(5);
  Set(P_GENDER, GENDER_FEMALE);
  SetResetQuality(75);
  SetNumberHands(1);
  Set(P_NOSELL,1);
}
