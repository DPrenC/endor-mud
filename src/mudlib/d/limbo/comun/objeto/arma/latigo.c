/*
DESCRIPCION  : latigo
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
  SetStandard(WT_LATIGO,1,P_SIZE_GENERIC,M_CUERO);
  SetAds(({"un","elástico","elastico"}));
  SetIds(({"arma","latigo","látigo"}));
  SetShort("un látigo");
  SetLong("Es un látigo de tres colas con unas bolitas de plomo en la punta.\n");
  SetValue(5);
  SetResetQuality(90);
  SetNumberHands(1);
  Set(P_NOSELL,1);
}
