/*
DESCRIPCION  : Vara
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
  SetStandard(WT_VARA,1,P_SIZE_GENERIC,M_MADERA);
  SetAds(({"una","larga"}));
  SetIds(({"arma","vara"}));
  SetShort("una vara");
  SetLong("Es una larga vara de roble que puede usarse como arma.\n");
  SetValue(10);
  SetResetQuality(90);
  SetNumberHands(2);
  Set(P_NOSELL,1);
}
