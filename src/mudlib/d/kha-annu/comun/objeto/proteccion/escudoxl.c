/* Escudo ancho creado por [Y] Yandros a 03.11.98
   [Woo] Modificado */

#include "./path.h"
#include <combat.h>
#include <properties.h>
#include <materials.h>


inherit ARMOUR;

create() {
   ::create();
  SetStandard(AT_SHIELD,1,P_SIZE_MEDIUM);
  SetShort("un escudo ancho");
  SetLong(
"Un escudo ancho y de cuero. Tiene una insignia de la ciudad de Kha-annu.\n");
  SetIds( ({"escudo ancho","escudo de cuero","escudo ancho y de cuero","escudo"}));
  SetAds( ({"un","el"}) );
  Set(P_GENDER,GENDER_MALE);
  SetWeight(2000);
  SetValue(95);
  SetResetQuality(100);
}
