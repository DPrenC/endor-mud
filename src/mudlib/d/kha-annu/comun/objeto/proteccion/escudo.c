/* Escudo sin reborde por [Y] Yandros a 03.11.98
   [Woo] Modificado */

#include "./path.h"

#include <combat.h>
#include <properties.h>
#include <materials.h>

inherit ARMOUR;

create() {
   ::create();
  SetStandard(AT_SHIELD,1,P_SIZE_MEDIUM);
  SetShort("un escudo sin reborde");
  SetLong(
"Es un pequeño y ligero escudo sin reborde. Está hecho de piel.\n");
  SetIds(({"escudo sin reborde","escudo pequenyo","escudo sencillo","escudo"}));
  SetAds( ({"un","el"}) );
  Set(P_GENDER,GENDER_MALE);
  SetWeight(800);
  SetValue(30);
  SetResetQuality(60);
}
