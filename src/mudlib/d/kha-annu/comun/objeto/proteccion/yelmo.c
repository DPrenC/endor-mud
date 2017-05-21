/* Yelmo creado por [Y] Yandros a 03.11.98
   [Woo] Modificado */

#include "./path.h"
#include <combat.h>
#include <properties.h>
#include <materials.h>


inherit ARMOUR;

create() {
   ::create();
   SetStandard(AT_HELMET,1,P_SIZE_MEDIUM);
   SetShort("un yelmo");
   SetLong("Es un yelmo normal bastante sencillo.\n");
   SetIds( ({"yelmo","yelmo normal","yelmo sencillo"}) );
   SetAds( ({"un","el"}) );
   Set(P_GENDER,GENDER_MALE);
   SetWeight(1000);
   SetValue(75);
}
